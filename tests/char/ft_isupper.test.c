#include <ft_test.h>
#include <ft_char.h>

START_TEST(test_upper, "Test that ft_isupper returns true [A-Z]")
{
    for (int i = 'A'; i <= 'Z'; i++)
        if (!ft_isupper(i))
            fail("ft_isupper() returned false for an uppercase letter");
    succeed();
} END_TEST

START_TEST(basic_lower, "Test that ft_isupper returns false [a-z]")
{
    for (int i = 'a'; i <= 'z'; i++)
        if (ft_isupper(i))
            fail("ft_isupper() returned true for a lowercase letter");
    succeed();
} END_TEST