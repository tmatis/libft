NAME := libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror -fPIE -g
DFLAGS	= -MMD -MF $(@:.o=.d)

# Directories
SRCSDIR := srcs
OBJDIR := objs
INCDIR := includes

# string files
SRCS +=	string/ft_strlen.c \
		string/ft_strnlen.c \
		string/ft_strcmp.c \
		string/ft_strncmp.c \
		string/ft_memcpy.c \
		string/ft_memmove.c \
		string/ft_atoi.c \
		string/ft_strlcpy.c \
		string/ft_strchr.c \
		string/ft_strpbrk.c \
		string/ft_strspn.c \
		string/ft_strtok.c \
		string/ft_strdup.c \
		string/ft_memcmp.c \
		string/ft_strerror.c

# char files

SRCS += char/ft_isdigit.c \
		char/ft_isalpha.c \
		char/ft_isupper.c \
		char/ft_islower.c \
		char/ft_tolower.c \
		char/ft_isalnum.c

# gnl files

SRCS += gnl/ft_gnl.c

# printf family files
SRCS +=	printf/buffer/buffer_printf.c \
		printf/parse_format/parse_format.c \
		printf/parse_format/conversions/int_conversion.c \
		printf/parse_format/conversions/float_conversion.c \
		printf/parse_format/conversions/uint_conversion.c \
		printf/parse_format/conversions/octal_conversion.c \
		printf/parse_format/conversions/hex_conversion.c \
		printf/parse_format/conversions/char_conversion.c \
		printf/parse_format/conversions/str_conversion.c \
		printf/parse_format/conversions/ptr_conversion.c \
		printf/utils/int_to_array_base.c \
		printf/utils/uint_to_array_base.c \
		printf/utils/float_to_array.c \
		printf/utils/paddings.c \
		printf/ft_printf.c

# unit test files

SRCS += units/units.c \
		units/record_output.c

OBJS := $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

DFLAGS	= -MMD -MF $(@:.o=.d)
DEPS	= $(addprefix $(OBJDIR)/, $(SRCS:.c=.d))
# Rules

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) -I $(INCDIR) -c $< -o $@

unit: $(OBJS)
	@LIBFT_TEST=true scripts/car.sh $(OBJS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re