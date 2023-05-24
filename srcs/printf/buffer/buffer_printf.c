#include <stdlib.h>
#include <unistd.h>
#include <bool_t.h>
#include <ft_min.h>
#include <ft_string.h>
#include <errno.h>
#include "buffer_printf.h"

/**
 * @brief Initialize a printf_buffer_t
 *
 * @param should_flush if it should flush the buffer when it is full or when a \n is found
 * @return printf_buffer_t the buffer
 */
printf_buffer_t buffer_printf_init(buffer_mode_t mode, int fd)
{
    printf_buffer_t printf_buffer = {
        .str = malloc(sizeof(char) * BUFFER_PRINTF_DEFAULT_CAPACITY),
        .len = 0,
        .total_len = 0,
        .capacity = BUFFER_PRINTF_DEFAULT_CAPACITY,
        .mode = mode,
        .fd = fd,
        .error_number = 0};
    if (printf_buffer.str == NULL)
        return (printf_buffer);
    printf_buffer.str[0] = '\0';
    return (printf_buffer);
}

/**
 * @brief Flush the buffer
 *
 * @param buffer the buffer to flush
 */
static void buffer_printf_flush(printf_buffer_t *buffer)
{
    size_t len = buffer->len;
    size_t i = 0;

    while (i < len)
    {
        size_t write_len = MIN(len - i, BUFFER_WRITE_THRESHOLD);
        write(buffer->fd, buffer->str + i, write_len);
        i += write_len;
    }
    buffer->len = 0;
    free(buffer->str);
    buffer->str = malloc(sizeof(char) * BUFFER_PRINTF_DEFAULT_CAPACITY);
    if (buffer->str == NULL)
    {
        buffer->capacity = 0;
        buffer->error_number = errno;
        return;
    }
    buffer->str[0] = '\0';
    buffer->capacity = BUFFER_PRINTF_DEFAULT_CAPACITY;
}

/**
 * @brief Destroy the buffer
 *
 * @param buffer the buffer to destroy
 */
void buffer_printf_destroy(printf_buffer_t *buffer)
{
    if (buffer->mode == PRINTF_WRITE_MODE && buffer->capacity != 0)
        buffer_printf_flush(buffer);
    free(buffer->str);
}

/**
 * @brief Double the capacity of the buffer
 *
 * @param buffer the buffer
 */
static void buffer_printf_double_capacity(printf_buffer_t *buffer)
{
    char *new_str = malloc(sizeof(char) * buffer->capacity * BUFFER_PRINTF_GROWTH_FACTOR);
    if (new_str == NULL)
    {
        buffer->capacity = 0;
        buffer->error_number = errno;
        return;
    }
    buffer->capacity *= BUFFER_PRINTF_GROWTH_FACTOR;
    ft_memcpy(new_str, buffer->str, buffer->len + 1);
    free(buffer->str);
    buffer->str = new_str;
}

/**
 * @brief Add a char to the buffer
 *
 * @param buffer the buffer
 * @param c the char to add
 */
void buffer_printf_add_char(printf_buffer_t *buffer, char c)
{
    if (buffer->capacity == 0)
        return;
    if (buffer->len == buffer->capacity)
        buffer_printf_double_capacity(buffer);
    buffer->str[buffer->len] = c;
    buffer->len++;
    buffer->total_len++;
    buffer->str[buffer->len] = '\0';
    if (buffer->mode == PRINTF_WRITE_MODE && c == '\n')
        buffer_printf_flush(buffer);
}

/**
 * @brief Add a string to the buffer
 *
 * @param buffer the buffer
 * @param str the string to add
 */
void buffer_printf_add_str(printf_buffer_t *buffer, const char *str)
{
    while (*str)
    {
        buffer_printf_add_char(buffer, *str);
        str++;
    }
}