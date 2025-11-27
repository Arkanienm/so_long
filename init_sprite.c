/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:16:35 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/27 18:11:37 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "so_long_lib.h"

void clean_sprites(t_data *data)
{
	if (data->wall)
		data->wall = NULL;
	else
		return ;
	if (data->floor)
		data->floor = NULL;
	else
		return ;
	if (data->collectible)
		data->collectible = NULL;
	else
		return ;
	if (data->player)
		data->player = NULL;
	else
		return ;
	if (data->exit)
		data->exit = NULL;
	else
		return ;
}

int init_images(t_data *data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, "sprites/tile1.xmp", 32, 32);
		if (!data->wall)
		{
			clean_sprites(data);
			return (0);
		}	
	data->floor = mlx_xpm_file_to_image(data->mlx, "sprites/tile0.xmp", 32, 32);
	if (!data->wall)
		{
			clean_sprites(data);
			return (0);
		}	
	data->collectible = mlx_xpm_file_to_image(data->mlx, "sprites/key.xmp", 32, 32);
	if (!data->collectible)
		{
			clean_sprites(data);
			return (0);
		}
	if (!init_images2(data))
		return(0);
	return (1);
}
int init_images2(t_data *data)
{
	data->player = mlx_xpm_file_to_image(data->mlx, "sprites/idle_down.xmp", 32, 32);
	if (!data->player)
		{
			clean_sprites(data);
			return (0);
		}	
	data->exit = mlx_xpm_file_to_image(data->mlx, "sprites/door.xmp", 32, 32);
	if (!data->exit)
		{
			clean_sprites(data);
			return (0);
		}
	return (1);
}