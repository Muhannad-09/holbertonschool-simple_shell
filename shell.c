#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

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

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *argv[64];
    int i;
    pid_t pid;
    char *token;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("#cisfun$ ");

        read = getline(&line, &len, stdin);
        if (read == -1)
        {
            if (isatty(STDIN_FILENO))
                printf("\n");
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

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            continue;
        }

        if (pid == 0)
        {
            if (execve(argv[0], argv, environ) == -1)
            {
                perror(argv[0]);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(NULL);
        }
    }

    free(line);
    return (0);
}
