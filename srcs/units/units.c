#include <ft_list.h>
#include <ft_btree.h>
#include <bool_t.h>
#include <stddef.h>
#include <ft_string.h>
#include <ft_printf.h>
#include <ft_test.h>
#include <ft_colors.h>
#include <stdint.h>

DEFINE_LIST_FUNCTIONS(test_result);

int cmp_test_function(test_function *a, test_function *b)
{
    return ft_strcmp(a->function_name, b->function_name);
}

DEFINE_BTREE_FUNCTIONS(test_function, cmp_test_function);

int cmp_test_suite(test_suite *a, test_suite *b)
{
    return ft_strcmp(a->file_name, b->file_name);
}

DEFINE_BTREE_FUNCTIONS(test_suite, cmp_test_suite);

void add_test_result(
    const char *error_message,
    size_t line,
    const char *function_name,
    const char *description,
    const char *file_name,
    btree_test_suite **test_suites)
{
    test_suite new_suite = {
        .file_name = file_name,
        .functions = NULL,
        .time = 0,
        .total = 0,
        .passed = 0,
        .failed = 0};
    btree_test_suite *suite = btree_test_suite_search(*test_suites, &new_suite);
    if (suite == NULL)
        suite = btree_test_suite_insert(test_suites, &new_suite);
    test_function new_function = {
        .function_name = function_name,
        .description = description,
        .results = NULL,
        .time = 0,
        .failed = 0};
    btree_test_function *function = btree_test_function_search(suite->value.functions, &new_function);
    if (function == NULL)
        function = btree_test_function_insert(&suite->value.functions, &new_function);
    test_result new_result = {
        .error_message = error_message,
        .function_name = function_name,
        .file_name = file_name,
        .line = line};
    lst_add_back_test_result(&function->value.results, &new_result);
    suite->value.total++;
    if (error_message == NULL)
        suite->value.passed++;
    else
    {
        suite->value.failed++;
        function->value.failed++;
    }
}

void add_test_time(
    const char *function_name,
    const char *file_name,
    int time,
    btree_test_suite **test_suites)
{
    test_suite test_suite_to_search = {
        .file_name = file_name};
    btree_test_suite *suite = btree_test_suite_search(*test_suites, &test_suite_to_search);
    if (suite == NULL)
        return;
    test_function test_function_to_search = {
        .function_name = function_name};
    btree_test_function *function = btree_test_function_search(suite->value.functions, &test_function_to_search);
    if (function == NULL)
        return;
    function->value.time = time;
    suite->value.time += time;
}


static void display_test_result(test_result *result)
{
    if (result->error_message == NULL)
        return;
    ft_printf("    %s at %s %s:%zu\n\n",
        result->error_message,
        result->function_name,
        result->file_name,
        result->line);
}

static char *get_time_to_display(int ms)
{
    static char buffer[100];
    if (ms == 0)
        return "< 1ms";
    ft_snprintf(buffer, 100, "%dms", ms);
    return buffer;
}

static void display_test_function(test_function *function)
{
    if (function->failed == 0)
        ft_printf("  %s✓%s %s (%s)\n", C_GREEN, C_RESET, function->description, get_time_to_display(function->time));
    else
    {
        ft_printf("  %s⨉%s %s (%s)\n\n", C_RED, C_RESET, function->description, get_time_to_display(function->time));
        ft_printf("  %s%s● %s%s\n\n", C_RED, C_BOLD, function->description, C_RESET);
        lst_foreach_test_result(function->results, display_test_result);
    }
}

static void display_test_suite(test_suite *suite)
{
    if (suite->failed == 0)
        ft_printf(
            "%s %sPASS %s %s%s%s\n",
            C_GREEN_B,
            C_BOLD,
            C_RESET,
            C_BOLD,
            suite->file_name,
            C_RESET);
    else
        ft_printf(
            "%s %sFAIL %s %s%s%s\n",
            C_RED_B,
            C_BOLD,
            C_RESET,
            C_BOLD,
            suite->file_name,
            C_RESET);
    btree_test_function_foreach(suite->functions, display_test_function);
    ft_printf("\n");
}

typedef struct
{
    uint64_t time_ms;
    size_t suite_total;
    size_t suite_passed;
    size_t suite_failed;
    size_t function_total;
    size_t function_passed;
    size_t function_failed;
} tests_summary;

void display_test_summary(tests_summary *summary)
{
    ft_printf("Summary of all tests\n" C_RESET);
    ft_printf(C_BOLD "Test Suites: " C_RESET);
    if (summary->suite_failed > 0)
        ft_printf(C_RED "%zu failed" C_RESET C_BOLD ", ", summary->suite_failed);
    if (summary->suite_passed > 0)
        ft_printf(C_GREEN C_BOLD "%zu passed" C_RESET C_BOLD ", ", summary->suite_passed);
    ft_printf("%zu total\n", summary->suite_total);
    ft_printf(C_BOLD "Tests:       " C_RESET);
    if (summary->function_failed > 0)
        ft_printf(C_RED C_BOLD "%zu failed" C_RESET C_BOLD ", ", summary->function_failed);
    if (summary->function_passed > 0)
        ft_printf(C_GREEN C_BOLD "%zu passed" C_RESET C_BOLD ", ", summary->function_passed);
    ft_printf("%zu total\n", summary->function_total);
    ft_printf(C_BOLD "Time:        %s\n", get_time_to_display(summary->time_ms));
}

void count_test_suites(test_suite *suite, tests_summary *summary)
{
    summary->suite_total++;
    if (suite->failed == 0)
        summary->suite_passed++;
    else
        summary->suite_failed++;
    summary->time_ms += suite->time;
    summary->function_total += suite->total;
    summary->function_passed += suite->passed;
    summary->function_failed += suite->failed;
}

int display_tests_results(tests_tracker *tracker)
{
    btree_test_suite_foreach(tracker->test_suites, display_test_suite);
    
    tests_summary tests_summary = {0};
    btree_test_suite_foreach_arg(tracker->test_suites, (void (*)(test_suite *, void *))count_test_suites, &tests_summary);
    display_test_summary(&tests_summary);
    return tests_summary.function_failed;
}