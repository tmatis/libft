#include <ft_string.h>

/**
 * @brief find the first occurrence of c in s
 * 
 * @param s string to search
 * @param c character to search for
 * @return char* a pointer to the first occurrence of c in s
 */
char *ft_strchr(const char *s, int c)
{
    while (*s != (char)c)
    {
        if (*s == '\0')
            return (NULL);
        s++;
    }
    return ((char *)s);
}