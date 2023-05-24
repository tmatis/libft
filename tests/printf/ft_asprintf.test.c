#include <ft_test.h>
#include <ft_printf.h>

START_TEST(basic, "Test that ft_asprintf put a string in a variable")
{
    char *buf;

    ft_asprintf(&buf, "Hello, world!");
    assert_string_equal(buf, "Hello, world!");
    free(buf);
} END_TEST