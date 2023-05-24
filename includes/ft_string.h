#ifndef STRING_H
#define STRING_H

#include <string.h>

typedef long long int _int64_t;

/**
 * @brief The strlen() function calculates the length of the string pointed to by s, excluding the terminating null byte ('\0').
 *
 * @param str the string to be measured
 * @return size_t the length of the string
 */
size_t ft_strlen(const char *str);

/**
 * @brief Copy memory area
 * 
 * @param dst destination 
 * @param src source
 * @param n number of bytes to copy
 * @return void* 
 */
void *ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Copy memory area
 * 
 * @param dst the destination
 * @param src the source
 * @param len the length
 * @return void* the destination
 */
void *ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Convert a string to an integer
 *
 * @param str the string to convert
 * @return int the integer
 */
int ft_atoi(const char *str);

/**
 * @brief Get the length of a string up to a maximum length
 * 
 * @param s the string to get the length of
 * @param maxlen the maximum length
 * @return size_t the length of the string
 */
size_t ft_strnlen(const char *s, size_t maxlen);

/**
 * @brief Compare two strings
 * 
 * @param s1 the first string
 * @param s2 the second string
 * @return int the difference between the first two different characters
 */
int ft_strcmp(const char *s1, const char *s2);

/**
 * @brief Compare two strings up to a maximum length
 * 
 * @param s1 the first string
 * @param s2 the second string
 * @param n the maximum length
 * @return int the difference between the first two different characters
 */
int ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Copy a string to another
 * 
 * @param dest destination
 * @param src source
 * @param n the maximum length
 * @return char* the destination string
 */
char *ft_strlcpy(char *dest, const char *src, size_t n);

/**
 * @brief find the first occurrence of any character in accept
 * 
 * @param s the string to search
 * @param accept the characters to search for
 * @return size_t the number of characters in s that are in accept
 */
size_t ft_strspn(const char *s, const char *accept);

/**
 * @brief find the first occurrence of any character in accept
 * 
 * @param s the string to search
 * @param accept the characters to search for
 * @return char* a pointer to the first occurrence of any character in accept
 */
char *ft_strpbrk(const char *s, const char *accept);

/**
 * @brief find the first occurrence of c in s
 * 
 * @param s string to search
 * @param c character to search for
 * @return char* a pointer to the first occurrence of c in s
 */
char *ft_strchr(const char *s, int c);


/**
 * @brief duplicate a string
 * 
 * @param s1 the string to duplicate
 * @return char* a pointer to the duplicated string
 */
char *ft_strdup(const char *s1);


/**
 * @brief Compare memory areas
 * 
 * @param s1 first memory area
 * @param s2 second memory area
 * @param n number of bytes to compare
 * @return int 0 if the two memory areas are identical, otherwise the difference between the first two differing bytes
 */
int ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Return a string describing the error number
 * 
 * @param errnum the error number
 * @return const char* the string describing the error number
 */
const char *ft_strerror(int errnum);

#endif