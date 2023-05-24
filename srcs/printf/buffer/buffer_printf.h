#ifndef BUFFER_PRINTF_H
#define BUFFER_PRINTF_H

#include <stdio.h>
#include <bool_t.h>

#define BUFFER_PRINTF_DEFAULT_CAPACITY 1024
#define BUFFER_PRINTF_GROWTH_FACTOR 2
#define BUFFER_WRITE_THRESHOLD 1024

typedef enum {
    PRINTF_WRITE_MODE,
    PRINTF_LEN_MODE,
    PRINTF_BUFFER_MODE
} buffer_mode_t;

typedef struct
{
    char *str;
    size_t len;
    size_t total_len;
    size_t capacity;
    buffer_mode_t mode;
    int fd;
    int error_number;
} printf_buffer_t;

/**
 * @brief Initialize a printf_buffer_t
 *
 * @param should_flush if it should flush the buffer when it is full or when a \n is found
 * @return printf_buffer_t the buffer
 */
printf_buffer_t buffer_printf_init(buffer_mode_t mode, int fd);

/**
 * @brief Destroy the buffer
 * 
 * @param buffer the buffer to destroy
 */
void buffer_printf_destroy(printf_buffer_t *buffer);

/**
 * @brief Add a char to the buffer
 *
 * @param buffer the buffer
 * @param c the char to add
 */
void buffer_printf_add_char(printf_buffer_t *buffer, char c);

/**
 * @brief Add a string to the buffer
 *
 * @param buffer the buffer
 * @param str the string to add
 */
void buffer_printf_add_str(printf_buffer_t *buffer, const char *str);

#endif