#include <ft_string.h>
#include "../parse_format.h"
#include "../../utils/printf_utils.h"

#define BASE_8 "01234567"

/**
 * @brief Convert an uint to a string of octal
 *
 * @param printf_buffer the printf buffer
 * @param flags the flags for the conversion
 * @param number the number to convert
 */
void octal_conversion(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    _uint64_t number)
{
    char buffer[64];
    uint_to_array_base(buffer, number, BASE_8);
    size_t size = ft_strlen(buffer);
    size_t saved_size = size;
    if (flags->precision > (int)size)
        size = flags->precision;
    if (flags->plus)
    {
        buffer_printf_add_char(printf_buffer, '+');
        flags->width--;
    }
    if (flags->hash)
    {
        size += 1;
        if (flags->zero)
            buffer_printf_add_char(printf_buffer, '0');
    }
    if (!flags->minus)
        number_left_padding(printf_buffer, flags, size);
    if (flags->plus && !flags->zero)
        buffer_printf_add_char(printf_buffer, '+');
    if (flags->hash && !flags->zero)
        buffer_printf_add_char(printf_buffer, '0');
    if (flags->precision > (int)saved_size)
    {
        while (flags->precision > (int)saved_size)
        {
            buffer_printf_add_char(printf_buffer, '0');
            flags->precision--;
        }
    }
    buffer_printf_add_str(printf_buffer, buffer);
    if (flags->minus)
        number_right_padding(printf_buffer, flags, size);
}
    