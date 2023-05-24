#include <ft_string.h>
#include "../parse_format.h"
#include "../../utils/printf_utils.h"

/**
 * @brief Convert a float for printf
 * 
 * @param printf_buffer printf buffer
 * @param flags the flags
 * @param number the number to convert
 */
void float_conversion(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    double number)
{
    char buffer[64];
    float_to_array(buffer, number, flags->precision == -1 ? 6 : flags->precision);
    size_t size = ft_strlen(buffer);
    size_t saved_size = size;
    if (flags->precision > (int)size)
        size = flags->precision;
    if (flags->plus)
    {
        size++;
        if (flags->zero)
            buffer_printf_add_char(printf_buffer, '+');
    }
    if (!flags->minus)
        number_left_padding(printf_buffer, flags, size);
    if (flags->plus && !flags->zero)
        buffer_printf_add_char(printf_buffer, '+');
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
