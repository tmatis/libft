#include <ft_char.h>

/**
 * @brief Checks for an alphabetic character
 * 
 * @param c Character to be checked, casted to an int
 * @return int Non-zero value if the character is an alphabetic character, 0 otherwise.
 */
int ft_isalpha(int c)
{
    return (ft_isupper(c) || ft_islower(c));
}