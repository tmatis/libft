#include <ft_string.h>

/**
 * @brief split string into tokens
 * 
 * @param str 
 * @param delim 
 * @return char* 
 */
char *ft_strtok(char *str, const char *delim)
{
    static char *old_str;
    char *token;

    if (str == NULL)
        str = old_str;
    str += ft_strspn(str, delim);
    if (*str == '\0')
        return (NULL);
    token = str;
    str = ft_strpbrk(token, delim);
    if (str == NULL)
        old_str = ft_strchr(token, '\0');
    else
    {
        *str = '\0';
        old_str = str + 1;
    }
    return (token);
}