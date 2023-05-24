#include <ft_test.h>
#include <ft_string.h>

START_TEST(basic, "Test that atoi converts a string to an int")
{
    assert_equal(ft_atoi("0"), 0);
    assert_equal(ft_atoi("1"), 1);
    assert_equal(ft_atoi("42"), 42);
    assert_equal(ft_atoi("-42"), -42);
    assert_equal(ft_atoi("2147483647"), 2147483647);
    assert_equal(ft_atoi("-2147483648"), -2147483648);
} END_TEST