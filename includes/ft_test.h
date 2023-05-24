#ifndef FT_TEST_H
#define FT_TEST_H

#include <stdio.h>
#include <stddef.h>
#include <sys/time.h>
#include "ft_list.h"
#include "ft_btree.h"
#include "ft_string.h"
#include "ft_colors.h"

typedef struct timeval timeval;

typedef struct
{
    const char *error_message;
    const char *function_name;
    const char *file_name;
    size_t line;
} test_result;

DEFINE_LIST_HEADERS(test_result);

typedef struct
{
    const char *function_name;
    const char *file_name;
    const char *description;
    size_t failed;
    int time;
    t_list_test_result *results;
} test_function;

DEFINE_BTREE_HEADERS(test_function);

typedef struct
{
    const char *file_name;
    btree_test_function *functions;
    int time;
    size_t total;
    size_t passed;
    size_t failed;
} test_suite;

DEFINE_BTREE_HEADERS(test_suite);

void add_test_result(
    const char *error_message,
    size_t line,
    const char *function_name,
    const char *description,
    const char *file_name,
    btree_test_suite **test_suites);

typedef struct
{
    btree_test_suite *test_suites;
} tests_tracker;

void add_test_time(
    const char *function_name,
    const char *file_name,
    int time,
    btree_test_suite **test_suites);

int display_tests_results(tests_tracker *test_tracker);

typedef struct
{
    int pipe[2];
    int backup_stdout;
    int backup_stderr;
} record_output;

record_output launch_record(void);
char *stop_record(record_output *record);

#define BEFORE_MAIN __attribute__((constructor))

#define START_TEST(name, description)                 \
    BEFORE_MAIN static void test_##name()             \
    {                                                 \
        const char *__test_name = #name;              \
        const char *__test_description = description; \
        timeval __start_time;                         \
        gettimeofday(&__start_time, NULL);

#define END_TEST                                                                                                                                                        \
    timeval __end_time;                                                                                                                                                 \
    gettimeofday(&__end_time, NULL);                                                                                                                                    \
    add_test_time(__test_name, __FILE__, (__end_time.tv_sec - __start_time.tv_sec) * 1000000 + (__end_time.tv_usec - __start_time.tv_usec), &test_tracker.test_suites); \
    }

#define TEST_FRAMEWORK                                       \
    tests_tracker test_tracker = {0};                        \
    int main()                                               \
    {                                                        \
        return display_tests_results(&test_tracker) ? 1 : 0; \
    }

extern tests_tracker test_tracker;

#define fail(str) \
    add_test_result(str, __LINE__, __test_name, __test_description, __FILE__, &test_tracker.test_suites)

#define succeed() \
    add_test_result(NULL, __LINE__, __test_name, __test_description, __FILE__, &test_tracker.test_suites)

#define assert_true(expr) expr ? succeed() : fail("Assertion failed: " C_BOLD "assert_true(" #expr ")" C_RESET " is " C_BOLD C_RED "not true" C_RESET);

#define assert_false(expr) expr ? fail("Assertion failed: " C_BOLD "assert_false(" #expr ")" C_RESET " is " C_BOLD C_RED "not false" C_RESET) : succeed();

#define assert_null(expr) expr == NULL ? succeed() : fail("Assertion failed: " C_BOLD "assert_null(" #expr ")" C_RESET " is " C_BOLD C_RED "not null" C_RESET);

#define assert_not_null(expr) expr != NULL ? succeed() : fail("Assertion failed: " C_BOLD "assert_not_null(" #expr ")" C_RESET " is " C_BOLD C_RED "null" C_RESET);

#define assert_equal(a, b) a == b ? succeed() : fail("Assertion failed: " C_BOLD "assert_equal(" #a ", " #b ")" C_RESET " is " C_BOLD C_RED "not equal" C_RESET);

#define assert_not_equal(a, b) a != b ? succeed() : fail("Assertion failed: " C_BOLD "assert_not_equal(" #a ", " #b ")" C_RESET " is " C_BOLD C_RED "equal" C_RESET);

#define assert_string_equal(a, b) ft_strcmp(a, b) == 0 ? succeed() : fail("Assertion failed: " C_BOLD "assert_string_equal(" #a ", " #b ")" C_RESET " is " C_BOLD C_RED "not equal" C_RESET);

#endif