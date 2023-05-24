#include <ft_string.h>
#include <stdlib.h>

/**
 * @brief Copy memory area
 * 
 * @param dst the destination
 * @param src the source
 * @param len the length
 * @return void* the destination
 */
void *ft_memmove(void *dst, const void *src, size_t len)
{
    char *from = (char *)src;
    char *to = (char *)dst;

    if (from == to || len == 0)
        return dst;
    if (to > from && to - from < (int)len)
    {
        ssize_t i;
        for (i = len - 1; i >= 0; i--)
            to[i] = from[i];
        return dst;
    }
    if (from > to && from - to < (int)len)
    {
        size_t i;
        for (i = 0; i < len; i++)
            to[i] = from[i];
        return dst;
    }
    return ft_memcpy(dst, src, len);
}