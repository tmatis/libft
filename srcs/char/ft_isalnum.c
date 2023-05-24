#include <ft_char.h>

/**
 * @brief Checks if the given character is alphanumeric
 * 
 * @param c The character to check
 * @return int 1 if the character is alphanumeric, 0 otherwise
 */
int ft_isalnum(int c)
{
    return ft_isalpha(c) || ft_isdigit(c);
}