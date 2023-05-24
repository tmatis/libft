#include <bool_t.h>

/**
 * @brief Check if a character is a digit
 * 
 * @param c the character
 * @return bool_t true if the character is a digit
 */
bool_t ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}