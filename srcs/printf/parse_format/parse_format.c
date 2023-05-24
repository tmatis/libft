#include <stdarg.h>
#include <stdint.h>
#include <ft_string.h>
#include <ft_char.h>
#include <stddef.h>
#include "parse_format.h"
#include "conversions/conversions.h"
#include "../buffer/buffer_printf.h"

static t_flags init_flags(void)
{
    t_flags flags;

    flags.minus = false;
    flags.plus = false;
    flags.space = false;
    flags.zero = false;
    flags.hash = false;
    flags.width = -1;
    flags.precision = -1;
    flags.length = def;
    flags.type = 0;
    return (flags);
}

static void parse_flags(const char **format, t_flags *flags)
{
    while (**format == '-' || **format == '+' || **format == ' ' || **format == '0' || **format == '#')
    {
        if (**format == '-')
            flags->minus = true;
        else if (**format == '+')
            flags->plus = true;
        else if (**format == ' ')
            flags->space = true;
        else if (**format == '0')
            flags->zero = true;
        else if (**format == '#')
            flags->hash = true;
        (*format)++;
    }
}

static void parse_width(const char **format, t_flags *flags, va_list args)
{
    if (**format == '*')
    {
        flags->width = va_arg(args, int);
        (*format)++;
    }
    else if (**format != '0' && ft_isdigit(**format))
    {
        flags->width = ft_atoi(*format);
        while (ft_isdigit(**format))
            (*format)++;
    }
}

static void parse_precision(const char **format, t_flags *flags, va_list args)
{
    if (**format == '.')
    {
        (*format)++;
        if (**format == '*')
        {
            flags->precision = va_arg(args, int);
            (*format)++;
        }
        else if (ft_isdigit(**format))
        {
            flags->precision = ft_atoi(*format);
            while (ft_isdigit(**format))
                (*format)++;
        }
        else
            flags->precision = 0;
    }
}

static void parse_type(const char **format, t_flags *flags)
{
    flags->type = **format;
    (*format)++;
}

static void parse_length(const char **format, t_flags *flags)
{
    static const char *lengths[] = {"hh", "ll", "h", "l", "L", "z", "j", "t"};
    static const t_length length_types[] = {hh, ll, h, l, L, z, j, t};

    for (size_t i = 0; i < sizeof(lengths) / sizeof(lengths[0]); i++)
    {
        size_t len = ft_strlen(lengths[i]);
        if (ft_strncmp(*format, lengths[i], len) == 0)
        {
            flags->length = length_types[i];
            *format += len;
            break;
        }
    }
}

static _int64_t get_int_from_va_list(va_list args, t_flags *flags)
{
    switch (flags->length)
    {
    case hh:
        return (char)va_arg(args, int);
    case ll:
        return (va_arg(args, _int64_t));
    case h:
        return (short)va_arg(args, int);
    case l:
        return (va_arg(args, long));
    case L:
        return (va_arg(args, long long));
    case z:
        return (va_arg(args, size_t));
    case j:
        return (va_arg(args, intmax_t));
    case t:
        return (va_arg(args, ptrdiff_t));
    default:
        return (va_arg(args, int));
    }
}

static _uint64_t get_uint_from_va_list(va_list args, t_flags *flags)
{
    switch (flags->length)
    {
    case hh:
        return (unsigned char)va_arg(args, unsigned int);
    case ll:
        return (va_arg(args, _uint64_t));
    case h:
        return (unsigned short)va_arg(args, unsigned int);
    case l:
        return (va_arg(args, unsigned long));
    case L:
        return (va_arg(args, unsigned long long));
    case z:
        return (va_arg(args, size_t));
    case j:
        return (va_arg(args, uintmax_t));
    case t:
        return (va_arg(args, ptrdiff_t));
    default:
        return (va_arg(args, unsigned int));
    }
}

void parse_format(printf_buffer_t *printf_buffer, const char **format, va_list args)
{
    t_flags flags = init_flags();

    parse_flags(format, &flags);
    parse_width(format, &flags, args);
    parse_precision(format, &flags, args);
    parse_length(format, &flags);
    parse_type(format, &flags);

    if (flags.type == 'd' || flags.type == 'i')
        int_conversion(printf_buffer, &flags, get_int_from_va_list(args, &flags));
    else if (flags.type == 'u')
        uint_conversion(printf_buffer, &flags, get_uint_from_va_list(args, &flags));
    else if (flags.type == 'o')
        octal_conversion(printf_buffer, &flags, get_uint_from_va_list(args, &flags));
    else if (flags.type == 'x' || flags.type == 'X')
        hex_conversion(printf_buffer, &flags, get_uint_from_va_list(args, &flags), flags.type == 'X');
    else if (flags.type == 'c')
        char_conversion(printf_buffer, &flags, (char)va_arg(args, int));
    else if (flags.type == 's')
        str_conversion(printf_buffer, &flags, va_arg(args, char *));
    else if (flags.type == 'p')
        ptr_conversion(printf_buffer, &flags, va_arg(args, void *));
    else if (flags.type == 'f')
        float_conversion(printf_buffer, &flags, va_arg(args, double));
}
