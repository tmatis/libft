#include <ft_string.h>
#include "../parse_format.h"
#include "../../utils/printf_utils.h"

#define BASE_16 "0123456789abcdef"

/**
 * @brief Convert an ptr to a string of hex
 *
 * @param printf_buffer the printf buffer
 * @param flags the flags for the conversion
 * @param number the number to convert
 */
void ptr_conversion(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    void *ptr)
{
    char buffer[64];
    uint_to_array_base(buffer, (_uint64_t)ptr, BASE_16);
    size_t size = ft_strlen(buffer);
    size_t saved_size = size;
    if (flags->precision > (int)size)
        size = flags->precision;
    size += 2;
    if (flags->zero)
        buffer_printf_add_str(printf_buffer, "0x");
    if (!flags->minus)
        number_left_padding(printf_buffer, flags, size);
    if (!flags->zero)
        buffer_printf_add_str(printf_buffer, "0x");
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