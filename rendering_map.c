/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:52:17 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/03 15:46:13 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "so_long_lib.h"

void	put_sprite(char c, t_data *data, int i, int height)
{
	int	x;
	int	y;

	x = i * data->img_width;
	y = height * data->img_height;
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->window, data->floor, x, y);
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->wall, x, y);
	if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->floor, x, y);
		mlx_put_image_to_window(data->mlx, data->window, data->player_up, x, y);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->floor, x, y);
		mlx_put_image_to_window(data->mlx, data->window, data->exit, x, y);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->floor, x, y);
		mlx_put_image_to_window(data->mlx, data->window, data->collec, x, y);
	}
}

int	render_map(t_data *data)
{
	int		i;
	int		height;
	char	c;

	c = ' ';
	i = 0;
	height = 0;
	while (height < data->map_height)
	{
		while (i < data->map_width)
		{
			c = data->map[height][i];
			if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
				put_sprite(c, data, i, height);
			i++;
		}
		i = 0;
		height++;
	}
	return (1);
}
