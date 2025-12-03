# --- VARIABLES ---
NAME        = so_long
NAME_BONUS  = so_long_bonus

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3

SRCS        = main.c check_map_content.c check_map_form.c check_path_utils.c \
              check_path.c init_map.c init_sprite.c manage_ft.c rendering_map.c \
              get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS        = $(SRCS:.c=.o)

BONUS_SRCS  = main_bonus.c rendering_map_bonus.c \
              check_map_content_bonus.c check_map_form.c check_path_utils.c \
              check_path.c init_map.c init_sprite_bonus.c manage_ft_bonus.c \
              get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			  ft_itoa_bonus.c ft_manage_next_bonus.c init_collec_bonus.c \
			  init_player_bonus.c 

BONUS_OBJS  = $(BONUS_SRCS:.c=.o)
LIBFT       = ./ft_printf/libftprintf.a
MLX         = ./minilibx-linux/libmlx.a
MLX_FLAGS   = -Lminilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./ft_printf
	make -C ./minilibx-linux
	$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	make -C ./ft_printf
	make -C ./minilibx-linux
	$(CC) $(BONUS_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C ./ft_printf
	# Pas de make clean pour la minilibx car elle est longue à recompiler

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re bonus