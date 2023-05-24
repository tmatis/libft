#include <ft_string.h>

/**
 * @brief Compare memory areas
 * 
 * @param s1 first memory area
 * @param s2 second memory area
 * @param n number of bytes to compare
 * @return int 0 if the two memory areas are identical, otherwise the difference between the first two differing bytes
 */
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1 = s1;
    const unsigned char *p2 = s2;
    while (n--)
    {
        if (*p1 != *p2)
            return (*p1 - *p2);
        p1++;
        p2++;
    }
    return (0);
}