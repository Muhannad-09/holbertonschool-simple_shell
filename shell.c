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

char *find_command(char *cmd)
{
    struct stat st;
    char *path = getenv("PATH");
    char *token, *full_path;
    size_t len;

    if (stat(cmd, &st) == 0)
        return strdup(cmd);

    token = strtok(path, ":");
    while (token)
    {
        len = strlen(token) + strlen(cmd) + 2;
        full_path = malloc(len);
        if (!full_path)
            return NULL;

        snprintf(full_path, len, "%s/%s", token, cmd);

        if (stat(full_path, &st) == 0)
            return full_path;

        free(full_path);
        token = strtok(NULL, ":");
    }

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
