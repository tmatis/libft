#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>

int ft_printf(const char *format, ...);
int ft_dprintf(int fd, const char *format, ...);
int ft_snprintf(char *dest, size_t size, const char *format, ...);
int ft_asprintf(char **dest, const char *format, ...);

#endif