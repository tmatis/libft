#include <ft_test.h>
#include <ft_printf.h>

START_TEST(basic, "Test that ft_dprintf prints a string on a fd")
{
    int pipefd[2];

    pipe(pipefd);
    ft_dprintf(pipefd[1], "Hello, world!");
    close(pipefd[1]);
    char buf[14];
    read(pipefd[0], buf, 14);
    buf[13] = '\0';
    assert_string_equal(buf, "Hello, world!");
    close(pipefd[0]);
} END_TEST