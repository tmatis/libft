/**
 * @brief Checks for an uppercase letter.
 * 
 * @param c Character to be checked, casted to an int
 * @return int Non-zero value if the character is an uppercase letter, 0 otherwise.
 */
int ft_isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}