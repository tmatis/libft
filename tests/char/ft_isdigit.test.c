#include <ft_test.h>
#include <ft_char.h>

START_TEST(basic_true, "Test that ft_isdigit returns true [0-9]")
{
    for (int i = '0'; i <= '9'; i++)
        if (!ft_isdigit(i))
            fail("ft_isdigit() returned false for a digit");
    succeed();
} END_TEST

START_TEST(basic_false, "Test that ft_isdigit returns false")
{
    for (int i = 0; i < 256; i++)
        if (i < '0' || i > '9')
            if (ft_isdigit(i))
                fail("ft_isdigit() returned true for a non-digit character");
    succeed();
} END_TEST