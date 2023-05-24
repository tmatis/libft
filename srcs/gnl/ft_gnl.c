#include <ft_string.h>
#include <bool_t.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

/**
 * @brief join two strings and free the first one
 *
 * @param s1 the first string allocated with malloc
 * @param s2 the second string on the stack
 * @param s2_len the length of s2 to copy
 * @return char* a pointer to the new string
 */
static char *strjoin(char *s1, char s2[BUFFER_SIZE])
{
    size_t s1_len;
    if (s1 == NULL)
        s1_len = 0;
    else
        s1_len = ft_strlen(s1);
    size_t s2_len = ft_strlen(s2);
    char *new = malloc(s1_len + s2_len + 1);
    if (new == NULL)
    {
        free(s1);
        return (NULL);
    }
    ft_memcpy(new, s1, s1_len);
    ft_memcpy(new + s1_len, s2, s2_len);
    new[s1_len + s2_len] = '\0';
    free(s1);
    return new;
}

static int add_to_line(char **line, char buffer[BUFFER_SIZE])
{
    char *new_line = ft_strchr(buffer, '\n');

    if (new_line != NULL)
    {
        *new_line = '\0';
        *line = strjoin(*line, buffer);
        if (*line == NULL)
        {
            return -1;
        }
        ft_memmove(buffer, new_line + 1, ft_strlen(new_line + 1) + 1);
        return 1;
    }
    *line = strjoin(*line, buffer);
    return 0;
}

/**
 * @brief get the next line from a file descriptor
 *
 * @param fd file descriptor to read from
 * @param line pointer to a string to store the line
 * @return int 1 if a line was read, -1 if an error occured
 */
int ft_gnl(int fd, char **line)
{
    static char buffer[BUFFER_SIZE];

    if (fd < 0 || line == NULL)
        return (-1);

    *line = NULL;
    ssize_t read_return;
    while ((read_return = read(fd, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[read_return] = '\0';
        int line_return = add_to_line(line, buffer);
        if (line_return == 1)
            return (1);
        if (line_return == -1)
            return (-1);
    }
    if (read_return == -1)
    {
        free(*line);
        *line = NULL;
        return (-1);
    }
    if (*line != NULL)
        return (1);
    return (0);
}