#include <ft_test.h>
#include <ft_string.h>

START_TEST(basic, "Test that ft_memcmp return correct result")
{
    assert_equal(ft_memcmp("abc", "abc", 3), 0);
    assert_equal(ft_memcmp("abc", "abd", 3), -1);
    assert_equal(ft_memcmp("abc", "abb", 3), 1);
    assert_equal(ft_memcmp("abc", "abc", 0), 0);
    assert_equal(ft_memcmp("abc", "abc", 2), 0);
} END_TEST