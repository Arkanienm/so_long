/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:52:17 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/03 16:04:06 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"
#include "so_long_lib_bonus.h"

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
		mlx_put_image_to_window(data->mlx, data->window, data->cur_play, x, y);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->exit, x, y);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->window, data->cur_coll, x, y);
	if (c == 'N')
		mlx_put_image_to_window(data->mlx, data->window, data->enemy, x, y);
}

void	render_step(t_data *data)
{
	char	*str;
	char	*fstr;

	str = ft_itoa(data->moves_count);
	fstr = ft_strjoin("step = ", str);
	put_sprite('1', data, 0, 0);
	mlx_string_put(data->mlx, data->window, 10, 32, 0xFFFFFF, fstr);
	free (fstr);
	free (str);
	fstr = NULL;
	str = NULL;
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
			if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C'
				|| c == 'N')
				put_sprite(c, data, i, height);
			i++;
		}
		i = 0;
		height++;
	}
	render_step(data);
	return (1);
}
