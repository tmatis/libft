#ifndef FT_CHAR_H
#define FT_CHAR_H

#include <bool_t.h>

/**
 * @brief Check if a character is a digit
 * 
 * @param c the character
 * @return bool_t true if the character is a digit
 */
bool_t ft_isdigit(int c);

/**
 * @brief Checks for an alphabetic character
 * 
 * @param c Character to be checked, casted to an int
 * @return int Non-zero value if the character is an alphabetic character, 0 otherwise.
 */
int ft_isalpha(int c);

/**
 * @brief Checks for a lowercase letter.
 * 
 * @param c Character to be checked, casted to an int
 * @return int Non-zero value if the character is a lowercase letter, 0 otherwise.
 */
int ft_islower(int c);

/**
 * @brief Checks for an uppercase letter.
 * 
 * @param c Character to be checked, casted to an int
 * @return int Non-zero value if the character is an uppercase letter, 0 otherwise.
 */
int ft_isupper(int c);


/**
 * @brief Return the lowercase version of the character if it is uppercase
 * 
 * @param c Character to convert
 * @return int Converted character
 */
int ft_tolower(int c);

/**
 * @brief Checks if the given character is alphanumeric
 * 
 * @param c The character to check
 * @return int 1 if the character is alphanumeric, 0 otherwise
 */
int ft_isalnum(int c);

#endif