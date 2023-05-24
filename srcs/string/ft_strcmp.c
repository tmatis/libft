#include <ft_string.h>

/**
 * @brief Compare two strings
 * 
 * @param s1 the first string
 * @param s2 the second string
 * @return int the difference between the first two different characters
 */
int ft_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;
    while (s1[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}