NAME = libftprintf.a

SRC = ft_printf.c ft_utils.c

all: $(NAME)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re