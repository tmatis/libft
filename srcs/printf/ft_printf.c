#include <unistd.h>
#include <stdarg.h>
#include <ft_string.h>
#include "buffer/buffer_printf.h"
#include "parse_format/parse_format.h"
#include <stdlib.h>

/**
 * @brief Parse the format string
 * 
 * @param format the format string
 * @param args the arguments
 * @param printf_buffer the printf buffer
 */
static void _printf_wrapper(const char *format, va_list args, printf_buffer_t *printf_buffer)
{
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '%')
            {
                buffer_printf_add_char(printf_buffer, '%');
                format++;
            }
            else
                parse_format(printf_buffer, &format, args);
        }
        else
            buffer_printf_add_char(printf_buffer, *format++);
        if (printf_buffer->error_number != 0)
        {
            buffer_printf_destroy(printf_buffer);
            va_end(args);
        }
    }
}

/**
 * @brief Mimic the printf function
 *
 * @param format the format string
 * @param ... the arguments
 * @return int the number of characters printed
 */
int ft_printf(const char *format, ...)
{
    printf_buffer_t printf_buffer = buffer_printf_init(
        PRINTF_WRITE_MODE,
        STDOUT_FILENO);
    if (printf_buffer.str == NULL)
        return (-1);
    va_list args;
    va_start(args, format);
    _printf_wrapper(format, args, &printf_buffer);
    va_end(args);
    buffer_printf_destroy(&printf_buffer);
    return (printf_buffer.total_len);
}

/**
 * @brief Mimic the dprintf function
 *
 * @param fd the file descriptor
 * @param format the format string
 * @param ... the arguments
 * @return int the number of characters printed
 */
int ft_dprintf(int fd, const char *format, ...)
{
    printf_buffer_t printf_buffer = buffer_printf_init(
        PRINTF_WRITE_MODE,
        fd);
    if (printf_buffer.str == NULL)
        return (-1);
    va_list args;
    va_start(args, format);
    _printf_wrapper(format, args, &printf_buffer);
    va_end(args);
    buffer_printf_destroy(&printf_buffer);
    return (printf_buffer.total_len);
}

/**
 * @brief Mimic the snprintf function
 *
 * @param str the string
 * @param format the format string
 * @param ... the arguments
 * @return int the number of characters printed
 */
int ft_snprintf(char *str, size_t size, const char *format, ...)
{
    printf_buffer_t printf_buffer = buffer_printf_init(
        PRINTF_BUFFER_MODE,
        STDOUT_FILENO);
    if (printf_buffer.str == NULL)
        return (-1);
    va_list args;
    va_start(args, format);
    _printf_wrapper(format, args, &printf_buffer);
    ft_strlcpy(str, printf_buffer.str, size);
    va_end(args);
    buffer_printf_destroy(&printf_buffer);
    if (size > 0)
        str[size - 1] = '\0';
    return (printf_buffer.total_len);
}

/**
 * @brief Mimic the asprintf function
 *
 * @param str the string
 * @param format the format string
 * @param ... the arguments
 * @return int the number of characters printed
 */
int ft_asprintf(char **str, const char *format, ...)
{
    printf_buffer_t printf_buffer = buffer_printf_init(
        PRINTF_BUFFER_MODE,
        STDOUT_FILENO);
    if (printf_buffer.str == NULL)
        return (-1);
    va_list args;
    va_start(args, format);
    _printf_wrapper(format, args, &printf_buffer);
    *str = malloc(sizeof(char) * (printf_buffer.len + 1));
    if (*str == NULL)
    {
        buffer_printf_destroy(&printf_buffer);
        va_end(args);
        return (-1);
    }
    ft_strlcpy(*str, printf_buffer.str, printf_buffer.len + 1);
    va_end(args);
    buffer_printf_destroy(&printf_buffer);
    return (printf_buffer.total_len);
}