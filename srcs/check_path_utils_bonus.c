/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:10:35 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/19 15:25:17 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "so_long_lib.h"

char	**copy_map(t_data *data)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (data->map_height + 1));
	if (!copy)
		return (NULL);
	while (i < data->map_height)
	{
		copy[i] = ft_strdup(data->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **tab, int x, int y)
{
	if (tab[y][x] == '1' || tab[y][x] == 'v' || tab[y][x] == 'N')
		return ;
	tab[y][x] = 'v';
	flood_fill (tab, x + 1, y);
	flood_fill (tab, x - 1, y);
	flood_fill (tab, x, y + 1);
	flood_fill (tab, x, y - 1);
}

void	pathing(t_data *data, int *x, int *y)
{
	int	height;
	int	i;

	height = 0;
	i = 0;
	while (height < data->map_height)
	{
		while (i < data->map_width)
		{
			if (data->map[height][i] == 'P')
			{
				*x = i;
				*y = height;
				return ;
			}
			i++;
		}
		i = 0;
		height ++;
	}
}

int	flood_verif(char **tab, t_data *data)
{
	int	height;
	int	i;

	height = 0;
	i = 0;
	while (height < data->map_height)
	{
		while (i < data->map_width)
		{
			if (tab[height][i] == 'C' || tab[height][i] == 'E')
				return (0);
			i++;
		}
		i = 0;
		height ++;
	}
	return (1);
}
