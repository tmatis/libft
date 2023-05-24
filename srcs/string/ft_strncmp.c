#include <ft_string.h>

/**
 * @brief Compare two strings up to a maximum length
 *
 * @param s1 the first string
 * @param s2 the second string
 * @param n the maximum length
 * @return int the difference between the first two different characters
 */
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char u1, u2;

    while (n-- > 0)
    {
        u1 = (unsigned char) *s1++;
        u2 = (unsigned char) *s2++;
        if (u1 != u2)
            return (u1 - u2);
        if (u1 == '\0')
            return (0);
    }
    return (0);
}