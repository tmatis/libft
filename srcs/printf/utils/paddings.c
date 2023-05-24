#include "../parse_format/parse_format.h"

/**
 * @brief Add padding to the printf buffer for int conversions
 *
 * @param printf_buffer the printf buffer
 * @param flags the flags
 * @param size the size of the number
 */
void number_left_padding(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    size_t size)
{
    while (flags->width > (int)size)
    {
        buffer_printf_add_char(printf_buffer, flags->zero ? '0' : ' ');
        flags->width--;
    }
}

/**
 * @brief Add padding to the right of the number
 * 
 * @param printf_buffer the printf buffer
 * @param flags the flags
 * @param size the size of the number
 */
void number_right_padding(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    size_t size)
{
    while (flags->width > (int)size)
    {
        buffer_printf_add_char(printf_buffer, ' ');
        flags->width--;
    }
}

/**
 * @brief Add padding to the left of the string
 * 
 * @param printf_buffer the printf buffer
 * @param flags the flags
 * @param size the size of the string
 */
void string_left_padding(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    size_t size)
{
    while (flags->width > (int)size)
    {
        buffer_printf_add_char(printf_buffer, ' ');
        flags->width--;
    }
}

/**
 * @brief Add padding to the right of the string
 * 
 * @param printf_buffer the printf buffer
 * @param flags the flags
 * @param size the size of the string
 */
void string_right_padding(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    size_t size)
{
    while (flags->width > (int)size)
    {
        buffer_printf_add_char(printf_buffer, ' ');
        flags->width--;
    }
}