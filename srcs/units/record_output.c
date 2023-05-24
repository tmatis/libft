#include <unistd.h>
#include <ft_string.h>
#include <stdlib.h>
#include <ft_test.h>

record_output launch_record(void)
{
    record_output output;
    if (pipe(output.pipe) == -1)
        exit(1);
    output.backup_stdout = dup(STDOUT_FILENO);
    output.backup_stderr = dup(STDERR_FILENO);
    dup2(output.pipe[1], STDOUT_FILENO);
    dup2(output.pipe[1], STDERR_FILENO);
    return output;
}

char *stop_record(record_output *record)
{
    char *output = NULL;
    char buffer[1024];
    int len = 0;
    int read_len = 0;

    write(record->pipe[1], "\0", 1);
    close(record->pipe[1]);
    while ((read_len = read(record->pipe[0], buffer, 1024)) > 0)
    {
        char *new_output = malloc(len + read_len + 1);
        if (new_output == NULL)
            exit(1);
        ft_memcpy(new_output, output, len);
        ft_memcpy(new_output + len, buffer, read_len);
        new_output[len + read_len] = '\0';
        free(output);
        output = new_output;
        if (buffer[read_len - 1] == '\0')
            break;
    }
    close(record->pipe[0]);
    dup2(record->backup_stdout, STDOUT_FILENO);
    dup2(record->backup_stderr, STDERR_FILENO);
    close(record->backup_stdout);
    close(record->backup_stderr);
    return output;
}