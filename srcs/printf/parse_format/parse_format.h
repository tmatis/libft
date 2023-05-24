#ifndef PARSE_FORMAT_H
#define PARSE_FORMAT_H

#include <bool_t.h>
#include "../buffer/buffer_printf.h"

typedef enum {
    def,
    hh,
    ll,
    h,
    l,
    L,
    z,
    j,
    t
} t_length;

typedef struct
{
    bool_t minus;
    bool_t plus;
    bool_t space;
    bool_t zero;
    bool_t hash;
    int width;
    int precision;
    t_length length;
    char type;
} t_flags;

typedef long long int _int64_t;
typedef unsigned long long int _uint64_t;

void parse_format(printf_buffer_t *printf_buffer, const char **format, va_list args);

#endif