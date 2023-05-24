#include <ft_string.h>

/**
 * @brief Get the length of a string up to a maximum length
 * 
 * @param s the string to get the length of
 * @param maxlen the maximum length
 * @return size_t the length of the string
 */
size_t ft_strnlen(const char *s, size_t maxlen)
{
    size_t i = 0;
    while (s[i] && i < maxlen)
        i++;
    return (i);
}