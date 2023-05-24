#include <ft_test.h>
#include <ft_gnl.h>
#include <unistd.h>

START_TEST(basic_read, "Test that ft_gnl reads a line")
{
    int pipefd[2];
    pipe(pipefd);
    write(pipefd[1], "Hello, world!\n", 14);
    close(pipefd[1]);
    char *line = NULL;
    int ret = ft_gnl(pipefd[0], &line);
    assert_equal(ret, 1);
    assert_string_equal(line, "Hello, world!");
    free(line);
    close(pipefd[0]);
} END_TEST

START_TEST(basic_eof, "Test that ft_gnl returns 0 on EOF")
{
    int pipefd[2];
    pipe(pipefd);
    close(pipefd[1]);
    char *line = NULL;
    int ret = ft_gnl(pipefd[0], &line);
    assert_equal(ret, 0);
    assert_null(line);
    close(pipefd[0]);
} END_TEST

START_TEST(basic_empty, "Test that ft_gnl returns an empty string on empty file")
{
    int pipefd[2];
    pipe(pipefd);
    write(pipefd[1], "", 1);
    close(pipefd[1]);
    char *line = NULL;
    int ret = ft_gnl(pipefd[0], &line);
    assert_equal(ret, 1);
    assert_string_equal(line, "");
    free(line);
    close(pipefd[0]);
} END_TEST

START_TEST(basic_null, "Test that ft_gnl returns NULL on NULL pointer")
{
    int pipefd[2];
    pipe(pipefd);
    write(pipefd[1], "Hello, world!\n", 14);
    close(pipefd[1]);
    int ret = ft_gnl(pipefd[0], NULL);
    assert_equal(ret, -1);
    close(pipefd[0]);
} END_TEST

START_TEST(basic_null_fd, "Test that ft_gnl returns NULL on invalid file descriptor")
{
    char *line = NULL;
    int ret = ft_gnl(-1, &line);
    assert_equal(ret, -1);
    assert_null(line);
} END_TEST

START_TEST(basic_null_fd_null, "Test that ft_gnl returns NULL on invalid file descriptor and NULL pointer")
{
    int ret = ft_gnl(-1, NULL);
    assert_equal(ret, -1);
} END_TEST