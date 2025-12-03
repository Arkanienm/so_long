NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I.

SRC     = ft_itoh_down.c ft_itoh_up.c ft_printf.c ft_ptoh.c ft_putchar.c \
 		  ft_putformat.c ft_putnbr.c ft_putunbr.c ft_putstr.c \
 		  ft_strlen.c ft_strnstr.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar  -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
