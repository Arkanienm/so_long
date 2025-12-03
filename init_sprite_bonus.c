/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:16:35 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/03 16:06:39 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"
#include "so_long_lib_bonus.h"

void	clean_sprites2(t_data *data)
{
	if (data->exit)
	{
		mlx_destroy_image (data->mlx, data->exit);
		data->exit = NULL;
	}
	if (data->enemy)
	{
		mlx_destroy_image (data->mlx, data->enemy);
		data->exit = NULL;
	}
	if (data->collec2)
	{
		mlx_destroy_image (data->mlx, data->collec2);
		data->exit = NULL;
	}
	if (data->collec3)
	{
		mlx_destroy_image (data->mlx, data->collec3);
		data->exit = NULL;
	}
	if (data->collec4)
	{
		mlx_destroy_image (data->mlx, data->collec4);
		data->exit = NULL;
	}
}

void	clean_sprites(t_data *data)
{
	if (data->wall)
	{
		mlx_destroy_image (data->mlx, data->wall);
		data->wall = NULL;
	}
	if (data->floor)
	{
		mlx_destroy_image (data->mlx, data->floor);
		data->floor = NULL;
	}
	if (data->collec)
	{
		mlx_destroy_image (data->mlx, data->collec);
		data->collec = NULL;
	}
	if (data->player_up)
	{
		mlx_destroy_image (data->mlx, data->player_up);
		data->player_up = NULL;
	}
	clean_sprites2(data);
	clean_sprites3(data);
}

int	init_images(t_data *data)
{
	data->wall = mlx_xpm_file_to_image (data->mlx, "sprites/tile1.xpm",
			&data->img_width, &data->img_height);
	if (!data->wall)
	{
		clean_sprites (data);
		return (0);
	}
	data->floor = mlx_xpm_file_to_image (data->mlx, "sprites/tile0.xpm",
			&data->img_width, &data->img_height);
	if (!data->floor)
	{
		clean_sprites (data);
		return (0);
	}
	data->collec = mlx_xpm_file_to_image (data->mlx, "sprites/collec0.xpm",
			&data->img_width, &data->img_height);
	if (!data->collec)
	{
		clean_sprites (data);
		return (0);
	}
	if (!init_collec(data) || !init_images2(data) || !init_player(data))
		return (0);
	return (1);
}

int	init_images2(t_data *data)
{
	data->player_up = mlx_xpm_file_to_image(data->mlx, "sprites/player_up.xpm",
			&data->img_width, &data->img_height);
	if (!data->player_up)
	{
		clean_sprites(data);
		return (0);
	}
	data->exit = mlx_xpm_file_to_image(data->mlx, "sprites/door.xpm",
			&data->img_width, &data->img_height);
	if (!data->exit)
	{
		clean_sprites(data);
		return (0);
	}
	data->enemy = mlx_xpm_file_to_image(data->mlx, "sprites/enemy.xpm",
			&data->img_width, &data->img_height);
	if (!data->exit)
	{
		clean_sprites(data);
		return (0);
	}
	return (1);
}
