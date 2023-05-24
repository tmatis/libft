
#include <ft_string.h>
#include <stdlib.h>
#include "printf_utils.h"

#define BASE_10 "0123456789"

typedef long long int _int64_t;
typedef unsigned long long int _uint64_t;

/**
 * @brief Convert an float to a string in a given base
 * 
 * @param dest the destination string
 * @param number the number to convert
 * @param precision the precision of the number
 * @return char* the destination string
 */
char *float_to_array(char *dest, double number, int precision)
{
    _int64_t integer_part = (_int64_t)number;
    double decimal_part = number - integer_part;
    int_to_array_base(dest, integer_part, BASE_10);
    size_t integer_part_size = ft_strlen(dest);
    dest[integer_part_size] = '.';
    dest += integer_part_size + 1;
    while (precision > 0)
    {
        decimal_part *= 10;
        _int64_t decimal_part_int = (_int64_t)decimal_part;
        *dest = BASE_10[decimal_part_int];
        dest++;
        decimal_part -= decimal_part_int;
        precision--;
    }
    *dest = '\0';
    return dest;
}