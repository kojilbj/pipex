CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

HEAD = pipex.h

SRCS = ./pipex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -I $(HEAD) $(OBJS) -o $(NAME) -L./libft -lft -g -fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
