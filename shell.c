#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int is_empty(const char *str)
{
    while (*str)
    {
        if (*str != ' ' && *str != '\t')
            return (0);
        str++;
    }
    return (1);
}

char *_getenv(const char *name)
{
    int i = 0;
    size_t len = strlen(name);

    while (environ[i])
    {
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
            return environ[i] + len + 1;
        i++;
    }
    return NULL;
}

char *find_command(char *cmd)
{
    char *path_env, *path_dup, *token, *full_path;
    size_t len;

    if (strchr(cmd, '/') != NULL)
    {
        if (access(cmd, X_OK) == 0)
            return strdup(cmd);
        return NULL;
    }

    path_env = _getenv("PATH");
    if (!path_env || *path_env == '\0')
        return NULL;

    path_dup = strdup(path_env);
    if (!path_dup)
        return NULL;

    token = strtok(path_dup, ":");
    while (token)
    {
        len = strlen(token) + strlen(cmd) + 2;
        full_path = malloc(len);
        if (!full_path)
        {
            free(path_dup);
            return NULL;
        }

        snprintf(full_path, len, "%s/%s", token, cmd);
        if (access(full_path, X_OK) == 0)
        {
            free(path_dup);
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path_dup);
    return NULL;
}

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *argv[64];
    int i;
    pid_t pid;
    char *token, *cmd_path;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(1, "#cisfun$ ", 9);

        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            if (isatty(STDIN_FILENO))
                write(1, "\n", 1);
            break;
        }

        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        if (is_empty(line))
            continue;

        i = 0;
        token = strtok(line, " \t");
        while (token != NULL && i < 63)
        {
            argv[i++] = token;
            token = strtok(NULL, " \t");
        }
        argv[i] = NULL;

        cmd_path = find_command(argv[0]);
        if (!cmd_path)
        {
            dprintf(STDERR_FILENO, "%s: command not found\n", argv[0]);
            continue;
        }

        argv[0] = cmd_path;

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            free(cmd_path);
            continue;
        }

        if (pid == 0)
        {
            execve(argv[0], argv, environ);
            perror(argv[0]);
            free(cmd_path);
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(NULL);
            free(cmd_path);
        }
    }

    free(line);
    return (0);
}
