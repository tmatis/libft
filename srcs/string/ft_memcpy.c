#include <string.h>

/**
 * @brief Copy memory area
 * 
 * @param dst destination 
 * @param src source
 * @param n number of bytes to copy
 * @return void* 
 */
void *ft_memcpy(void *dst, const void *src, size_t n)
{
    for (size_t i = 0; i < n; i++)
        ((char *)dst)[i] = ((char *)src)[i];
    return dst;
}