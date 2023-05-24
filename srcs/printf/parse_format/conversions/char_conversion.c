#include <ft_string.h>
#include "../parse_format.h"
#include "../../utils/printf_utils.h"

/**
 * @brief Convert a char for printf
 * 
 * @param printf_buffer printf buffer
 * @param flags the flags
 * @param c the char to convert
 */
void char_conversion(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    char c)
{
    if (!flags->minus)
        string_left_padding(printf_buffer, flags, 1);
    buffer_printf_add_char(printf_buffer, c);
    if (flags->minus)
        string_left_padding(printf_buffer, flags, 1);
}