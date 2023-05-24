#include <ft_string.h>
#include "../parse_format.h"
#include "../../utils/printf_utils.h"

/**
 * @brief Convert a string for printf
 * 
 * @param printf_buffer printf buffer
 * @param flags the flags
 * @param str the string to convert
 */
void str_conversion(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    char *str)
{
    if (str == NULL)
        str = "(null)";
    size_t size = ft_strlen(str);
    if (flags->precision > 0 && flags->precision < (int)size)
        size = flags->precision;
    if (!flags->minus)
        string_left_padding(printf_buffer, flags, size);
    if (flags->precision > 0)
    {
        while (flags->precision > 0 && *str)
        {
            buffer_printf_add_char(printf_buffer, *str);
            str++;
            flags->precision--;
        }
    }
    else
        buffer_printf_add_str(printf_buffer, str);
    if (flags->minus)
        string_left_padding(printf_buffer, flags, size);
}