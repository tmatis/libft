#include <ft_string.h>

/**
 * @brief find the first occurrence of any character in accept
 * 
 * @param s the string to search
 * @param accept the characters to search for
 * @return char* a pointer to the first occurrence of any character in accept
 */
char *ft_strpbrk(const char *s, const char *accept)
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
                return ((char *)s + i);
            j++;
        }
        i++;
    }
    return (NULL);
}