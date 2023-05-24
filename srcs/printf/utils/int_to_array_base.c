#include <ft_string.h>
#include <stdlib.h>

typedef long long int _int64_t;
typedef unsigned long long int _uint64_t;

/**
 * @brief Get the number size in a given base
 * 
 * @param n the number to get the size of
 * @param base_size the size of the base
 * @return size_t the size of the number
 */
static size_t number_size(_uint64_t n, size_t base_size)
{
    size_t size = 0;
    while (n > 0)
    {
        n /= base_size;
        size++;
    }
    if (size == 0)
        size = 1;
    return (size);
}

/**
 * @brief Convert an integer to a string in a given base
 * 
 * @param dest the destination string
 * @param n the number to convert
 * @param base the base to convert to
 * @return char* the destination string
 */
char *int_to_array_base(char *dest, _int64_t n, const char *base)
{
    size_t base_size = ft_strlen(base);
    if (base_size < 2)
        return (dest);
    _uint64_t number = n;
    size_t i = 0;

    if (n == 0)
    {
        dest[0] = '0';
        dest[1] = '\0';
        return (dest);
    }
    if (n < 0)
    {
        dest[0] = '-';
        number = -n;
        i++;
    }
    size_t size = number_size(number, base_size);
    i += size - 1;
    dest[i + 1] = '\0';
    while (number > 0)
    {
        dest[i] = base[number % base_size];
        number /= base_size;
        i--;
    }
    return (dest);
}