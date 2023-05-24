#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include "../parse_format.h"

/**
 * @brief Convert an int to a string
 * 
 * @param printf_buffer the printf buffer
 * @param flags the flags for the conversion
 * @param number the number to convert
 */
void int_conversion(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    _int64_t number);


/**
 * @brief Convert an uint to a string
 *
 * @param printf_buffer the printf buffer
 * @param flags the flags for the conversion
 * @param number the number to convert
 */
void uint_conversion(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    _int64_t number);


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
    _uint64_t number);

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
    double number);

/**
 * @brief Convert an uint to a string of hex
 *
 * @param printf_buffer the printf buffer
 * @param flags the flags for the conversion
 * @param number the number to convert
 */
void hex_conversion(
    printf_buffer_t *printf_buffer,
    t_flags *flags,
    _uint64_t number,
    bool_t is_upper);

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
    char c);

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
    char *str);

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
    void *ptr);

#endif