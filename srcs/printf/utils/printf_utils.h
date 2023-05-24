#ifndef PRINTF_UTILS_H
#define PRINTF_UTILS_H

#include "../parse_format/parse_format.h"

typedef long long int _int64_t;
typedef unsigned long long int _uint64_t;

/**
 * @brief Convert an integer to a string in a given base
 * 
 * @param dest the destination string of NULL to allocate a new one
 * @param n the number to convert
 * @param base the base to convert to
 * @return char* the destination string
 */
char *int_to_array_base(char *dest, _int64_t n, const char *base);

/**
 * @brief Convert an integer to a string in a given base
 * 
 * @param dest the destination string
 * @param n the number to convert
 * @param base the base to convert to
 * @return char* the destination string
 */
char *uint_to_array_base(char *dest, _uint64_t number, const char *base);

/**
 * @brief Convert an float to a string in a given base
 * 
 * @param dest the destination string
 * @param number the number to convert
 * @param precision the precision of the number
 * @return char* the destination string
 */
char *float_to_array(char *dest, double number, int precision);

/**
 * @brief Add padding to the printf buffer for number conversions
 *
 * @param printf_buffer the printf buffer
 * @param flags the flags
 * @param size the size of the number
 */
void number_left_padding(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    size_t size);

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
    size_t size);

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
    size_t size);

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
    size_t size);

#endif