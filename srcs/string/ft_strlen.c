/**
 * @file ft_strlen.c
 * @author tmatis (tmatis@student.42.fr)
 * @brief The strlen() function calculates the length of the string pointed to by s, excluding the terminating null byte ('\0').
 * @date 2023-04-03
 * 
 * The strlen function is inspired by the GNU C Library. With the longword optimization.
 */

#include <ft_string.h>
#include <bool_t.h>

#define HIMAGIC_64 0x8080808080808080L
#define LOMAGIC_64 0x0101010101010101L

/**
 * @brief The strlen() function calculates the length of the string pointed to by s, excluding the terminating null byte ('\0').
 *
 * @param str the string to be measured
 * @return size_t the length of the string
 */
size_t ft_strlen(const char *str)
{
    const char *char_ptr;
    const unsigned long *longword_ptr;
    unsigned long int longword;

    /* Handle the first few characters by reading one character at a time.
    Do this until char_ptr is aligned on a longword boundary.
    if the str is shorter than a longword, we return the length of the str */
    for (char_ptr = str; ((unsigned long int)char_ptr &
                          (sizeof(unsigned long int) - 1)) != 0;
         ++char_ptr)
    {
        if (*char_ptr == '\0')
            return char_ptr - str;
    }

    longword_ptr = (unsigned long *)char_ptr;

    while (true)
    {
        /* We read in a longword at a time. If any of the bytes in
        the longword in the string are zero, we will find a zero byte
        after shifting it down by some number of bits. */
        longword = *longword_ptr++;

        if (((longword - LOMAGIC_64) & ~longword & HIMAGIC_64) != 0)
        {
            /* Determine the position of the zero byte. */
            const char *cp = (const char *)(longword_ptr - 1);

            for (unsigned int i = 0; i < sizeof(unsigned long int); i++)
            {
                if (cp[i] == 0)
                    return cp - str + i;
            }
        }
    }
    /* the function never reach this point */
    return 0;
}