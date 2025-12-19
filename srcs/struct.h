/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:26:06 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/15 18:02:16 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
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
	void	*collec;
	void	*exit;
	int		moves_count;
	int		collectibles_left;
	int		player_x;
	int		player_y;
	int		e_verif;
}	t_data;

#endif
