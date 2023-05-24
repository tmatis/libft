#include <ft_string.h>

/**
 * @brief Copy a string to another
 * 
 * @param dest destination
 * @param src source
 * @param n the maximum length
 * @return char* the destination string
 */
char *ft_strlcpy(char *dest, const char *src, size_t n)
{
    size_t i = 0;
    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}