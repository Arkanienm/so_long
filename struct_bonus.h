/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:26:06 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/03 16:22:41 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*img;
	int		img_width;
	int		img_height;
	char	**map;
	int		map_width;
	int		map_height;
	void	*wall;
	void	*floor;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*cur_play;
	void	*collec;
	void	*collec2;
	void	*collec3;
	void	*collec4;
	void	*cur_coll;
	void	*exit;
	void	*enemy;
	int		moves_count;
	int		collectibles_left;
	int		player_x;
	int		player_y;
	int		loop_count;
	int		anim_frame;
}	t_data;

#endif
