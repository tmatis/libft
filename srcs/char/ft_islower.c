/**
 * @brief Checks for a lowercase letter.
 * 
 * @param c Character to be checked, casted to an int
 * @return int Non-zero value if the character is a lowercase letter, 0 otherwise.
 */
int ft_islower(int c)
{
    return (c >= 'a' && c <= 'z');
}