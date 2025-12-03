/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:51:35 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/03 17:24:06 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"
#include "so_long_lib_bonus.h"

int	clean_sprites3(t_data *data)
{
	if (data->player_down)
	{
		mlx_destroy_image (data->mlx, data->player_down);
		data->player_down = NULL;
	}
	if (data->player_left)
	{
		mlx_destroy_image (data->mlx, data->player_left);
		data->player_left = NULL;
	}
	if (data->player_right)
	{
		mlx_destroy_image (data->mlx, data->player_right);
		data->player_right = NULL;
	}
	return (1);
}

int	init_player2(t_data *data)
{
	if (!data->player_down)
	{
		clean_sprites (data);
		return (0);
	}
	if (data->player_up)
		data->cur_play = data->player_up;
	return (1);
}

int	init_player(t_data *data)
{
	data->player_right = mlx_xpm_file_to_image (data->mlx,
			"sprites/player_right.xpm",
			&data->img_width, &data->img_height);
	if (!data->player_right)
	{
		clean_sprites (data);
		return (0);
	}
	data->player_left = mlx_xpm_file_to_image (data->mlx,
			"sprites/player_left.xpm",
			&data->img_width, &data->img_height);
	if (!data->player_left)
	{
		clean_sprites (data);
		return (0);
	}
	data->player_down = mlx_xpm_file_to_image (data->mlx,
			"sprites/player_down.xpm",
			&data->img_width, &data->img_height);
	if (!init_player2(data))
		return (0);
	return (1);
}
