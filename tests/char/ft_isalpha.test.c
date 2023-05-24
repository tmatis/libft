#include <ft_test.h>
#include <ft_char.h>

START_TEST(test_upper, "Test that ft_isalpha returns true [A-Z]")
{
    for (int i = 'A'; i <= 'Z'; i++)
        if (!ft_isalpha(i))
            fail("ft_isalpha() returned false for an uppercase letter");
    succeed();
} END_TEST

START_TEST(basic_lower, "Test that ft_isalpha returns true [a-z]")
{
    for (int i = 'a'; i <= 'z'; i++)
        if (!ft_isalpha(i))
            fail("ft_isalpha() returned false for a lowercase letter");
    succeed();
} END_TEST

START_TEST(basic_false, "Test that ft_isalpha returns false")
{
    for (int i = 0; i < 256; i++)
        if (i < 'A' || i > 'Z')
            if (i < 'a' || i > 'z')
                if (ft_isalpha(i))
                    fail("ft_isalpha() returned true for a non-alphabetic character");
    succeed();
} END_TEST