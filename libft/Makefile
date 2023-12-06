CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

HEAD = libft.h

SRCS = ./ft_digit_deci_to_hexa.c \
		./ft_print_c.c \
		./ft_print_d.c \
		./ft_print_p.c \
		./ft_print_s.c \
		./ft_print_u.c \
		./ft_print_x.c \
		./ft_print_x_cap.c \
		./ft_printf.c \
		./ft_isalpha.c \
		./ft_isdigit.c \
		./ft_isalnum.c \
		./ft_isascii.c \
		./ft_isprint.c \
		./ft_strlen.c \
		./ft_memset.c \
		./ft_bzero.c \
		./ft_memcpy.c \
		./ft_memmove.c \
		./ft_strlcpy.c \
		./ft_strlcat.c \
		./ft_toupper.c \
		./ft_tolower.c \
		./ft_strchr.c \
		./ft_strrchr.c \
		./ft_strncmp.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_strnstr.c \
		./ft_atoi.c \
		./ft_calloc.c \
		./ft_strdup.c \
		./ft_substr.c \
		./ft_strjoin.c \
		./ft_strtrim.c \
		./ft_itoa.c \
		./ft_putchar_fd.c \
		./ft_putstr_fd.c \
		./ft_putnbr_fd.c \
		./ft_putendl_fd.c \
		./ft_strmapi.c \
		./ft_striteri.c \
		./ft_split.c \
		./ft_printf.c \
		./ft_print_c.c \
		./ft_print_d.c \
		./ft_print_p.c \
		./ft_print_s.c \
		./ft_print_u.c \
		./ft_print_x.c \
		./ft_digit_deci_to_hexa.c \
		./ft_print_x_cap.c \
		./get_next_line_utils_bonus.c \
		./get_next_line_bonus.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
