#include <ft_string.h>

/**
 * @brief find the first occurrence of any character in accept
 * 
 * @param s the string to search
 * @param accept the characters to search for
 * @return size_t the number of characters in s that are in accept
 */
size_t ft_strspn(const char *s, const char *accept)
{
    size_t i;
    size_t j;

    i = 0;
    while (s[i] != '\0')
    {
        j = 0;
        while (accept[j] != '\0')
        {
            if (s[i] == accept[j])
                break;
            j++;
        }
        if (accept[j] == '\0')
            return (i);
        i++;
    }
    return (i);
}