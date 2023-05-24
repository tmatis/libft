#include <ft_test.h>
#include <ft_printf.h>
#include <limits.h>

START_TEST(basic, "Test that ft_printf prints a string")
{
    char *str = "Hello World!";
    record_output record = launch_record();
    ft_printf("%s", str);
    char *result = stop_record(&record);
    assert_string_equal(result, str);
    succeed();
} END_TEST

START_TEST(basic2, "Test that ft_printf prints a string with a newline")
{
    char *str = "Hello World!\n";
    record_output record = launch_record();
    ft_printf("%s", str);
    char *result = stop_record(&record);
    assert_string_equal(result, str);
    succeed();
} END_TEST

START_TEST(num, "Test that ft_printf prints a number")
{
    char *str = "12345";
    record_output record = launch_record();
    ft_printf("%d", 12345);
    char *result = stop_record(&record);
    assert_string_equal(result, str);
    succeed();
} END_TEST

START_TEST(num2, "Test that ft_printf prints a negative number")
{
    char *str = "-12345";
    record_output record = launch_record();
    ft_printf("%d", -12345);
    char *result = stop_record(&record);
    assert_string_equal(result, str);
    succeed();
} END_TEST

START_TEST(num3, "Test that ft_printf prints a number with a plus sign")
{
    char *str = "+12345";
    record_output record = launch_record();
    ft_printf("%+d", 12345);
    char *result = stop_record(&record);
    assert_string_equal(result, str);
    succeed();
} END_TEST

START_TEST(num4, "Test that ft_printf prints a number with a space")
{
    char *str = "12345";
    record_output record = launch_record();
    ft_printf("% d", 12345);
    char *result = stop_record(&record);
    assert_string_equal(result, str);
    succeed();
} END_TEST

START_TEST(num_limit, "Test that ft_printf prints INT_MAX")
{
    char *str = "2147483647";
    record_output record = launch_record();
    ft_printf("%d", INT_MAX);
    char *result = stop_record(&record);
    assert_string_equal(result, str);
    succeed();
} END_TEST

START_TEST(num_limit2, "Test that ft_printf prints INT_MIN")
{
    char *str = "-2147483648";
    record_output record = launch_record();
    ft_printf("%d", INT_MIN);
    char *result = stop_record(&record);
    assert_string_equal(result, str);
    succeed();
} END_TEST

START_TEST(num_length, "Test that ft_printf prints a number with a length modifier")
{
    char *str = "12345";
    record_output record = launch_record();
    ft_printf("%ld", 12345);
    char *result = stop_record(&record);
    assert_string_equal(result, str);
    succeed();
} END_TEST

START_TEST(test_string_with_length, "Test that ft_printf prints a string with a length modifier")
{
    char *str = "Hello World!";
    record_output record = launch_record();
    ft_printf("%10s", str);
    char *result = stop_record(&record);
    assert_string_equal(result, str);
    succeed();
} END_TEST