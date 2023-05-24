#include <ft_test.h>
#include <ft_printf.h>

START_TEST(basic, "Test that ft_snprintf copies a string to a buffer")
{
    char buf[14];

    ft_snprintf(buf, 14, "Hello, world!");
    buf[13] = '\0';
    assert_string_equal(buf, "Hello, world!");
} END_TEST