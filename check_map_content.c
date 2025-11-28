/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:07:58 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/28 15:14:53 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "so_long_lib.h"

void	content_verif(t_data *data, int height, int width, int tab[3])
{
	char	c;

	c = data->map[height][width];
	if (c == 'P')
	{
		tab[0] += 1;
		data->player_x = width;
		data->player_y = height;
	}
	if (c == 'E')
		tab[1] += 1;
	if (c == 'C')
	{
		tab[2] += 1;
		data->collectibles_left += 1;
	}
}

int	wrong_caracter(t_data *data, int height, int width)
{
	char	c;

	c = data->map[height][width];
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
		return (0);
	return (1);
}

int	check_content(t_data *data)
{
	int	height;
	int	width;
	int	tab[3];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	height = 0;
	width = 0;
	while (height < data->map_height)
	{
		width = 0;
		while (width < data->map_width)
		{
			content_verif(data, height, width, tab);
			if (wrong_caracter(data, height, width))
				return (0);
			width ++;
		}
		height++;
	}
	if (tab[0] == 1 && tab[1] == 1 && tab[2] >= 1)
		return (1);
	else
		return (0);
}
