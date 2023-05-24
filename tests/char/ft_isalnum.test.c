#include <ft_test.h>
#include <ft_char.h>

START_TEST(test_upper, "Test that ft_isalnum returns true [A-Z]")
{
    for (int i = 'A'; i <= 'Z'; i++)
        if (!ft_isalnum(i))
            fail("ft_isalnum() returned false for an uppercase letter");
    succeed();
} END_TEST

START_TEST(basic_lower, "Test that ft_isalnum returns true [a-z]")
{
    for (int i = 'a'; i <= 'z'; i++)
        if (!ft_isalnum(i))
            fail("ft_isalnum() returned false for a lowercase letter");
    succeed();
} END_TEST

START_TEST(basic_digit, "Test that ft_isalnum returns true [0-9]")
{
    for (int i = '0'; i <= '9'; i++)
        if (!ft_isalnum(i))
            fail("ft_isalnum() returned false for a digit");
    succeed();
} END_TEST

START_TEST(basic_false, "Test that ft_isalnum returns false")
{
    for (int i = 0; i < 256; i++)
        if (i < '0' || i > '9')
            if (i < 'A' || i > 'Z')
                if (i < 'a' || i > 'z')
                    if (ft_isalnum(i))
                        fail("ft_isalnum() returned true for a non-alphanumeric character");
    succeed();
} END_TEST