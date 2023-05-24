#include <ft_test.h>
#include <ft_char.h>

START_TEST(test_upper, "Test that ft_islower returns false [A-Z]")
{
    for (int i = 'A'; i <= 'Z'; i++)
        if (ft_islower(i))
            fail("ft_islower() returned true for an uppercase letter");
    succeed();
} END_TEST

START_TEST(basic_lower, "Test that ft_islower returns true [a-z]")
{
    for (int i = 'a'; i <= 'z'; i++)
        if (!ft_islower(i))
            fail("ft_islower() returned false for a lowercase letter");
    succeed();
} END_TEST