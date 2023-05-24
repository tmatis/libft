#include <ft_char.h>

/**
 * @brief Return the lowercase version of the character if it is uppercase
 * 
 * @param c Character to convert
 * @return int Converted character
 */
int ft_tolower(int c)
{
    if (ft_isupper(c))
        return (c + 32);
    return (c);
}