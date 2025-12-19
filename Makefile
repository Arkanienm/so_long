NAME        = so_long
NAME_BONUS  = so_long_bonus

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

SRCS        = srcs/main.c srcs/check_map_content.c srcs/check_map_form.c \
			  srcs/check_path_utils.c srcs/check_path.c srcs/init_map.c \
			  srcs/init_sprite.c srcs/manage_ft.c srcs/rendering_map.c \
              srcs/get_next_line/get_next_line.c srcs/get_next_line/get_next_line_utils.c \
			  srcs/check_extention_args.c

OBJS        = $(SRCS:.c=.o)

BONUS_SRCS  = srcs/main_bonus.c srcs/rendering_map_bonus.c \
              srcs/check_map_content_bonus.c srcs/check_map_form.c srcs/check_path_utils_bonus.c \
              srcs/check_path.c srcs/init_map.c srcs/init_sprite_bonus.c srcs/manage_ft_bonus.c \
              srcs/get_next_line/get_next_line.c srcs/get_next_line/get_next_line_utils.c \
			  srcs/ft_itoa_bonus.c srcs/ft_manage_next_bonus.c srcs/init_collec_bonus.c \
			  srcs/init_player_bonus.c srcs/check_extention_args.c

BONUS_OBJS  = $(BONUS_SRCS:.c=.o)
FT_PRINTF   = ./srcs/ft_printf/libftprintf.a
MLX         = ./srcs/minilibx-linux/libmlx.a
MLX_FLAGS   = -Lsrcs/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./srcs/ft_printf
	make -C ./srcs/minilibx-linux
	$(CC) $(OBJS) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	make -C ./srcs/ft_printf
	make -C ./srcs/minilibx-linux
	$(CC) $(BONUS_OBJS) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C ./srcs/ft_printf
	make clean -C ./srcs/minilibx-linux

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C ./srcs/ft_printf
	make clean -C ./srcs/minilibx-linux

re: fclean all

.PHONY: all clean fclean re bonus
