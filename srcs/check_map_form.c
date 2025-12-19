/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:06:08 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/19 15:25:41 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "so_long_lib.h"

int	check_rectangular(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < data->map_height)
	{
		len = ft_strlent(data->map[i]);
		if (len > 0 && data->map[i][len - 1] == '\n')
			len --;
		if (len != data->map_width)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_data *data)
{
	int	i;

	i = 0;
	check_map_size(data);
	while (i < data->map_width - 1)
	{
		if (data->map[0][i] != '1' || data->map[data->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->map_height)
	{
		if (data->map[i][0] != '1' || data->map[i][data->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_size(t_data *data)
{
	if (data->map_width > 30)
	{
		ft_printf("Error\nThe map is too big");
		close_window(data);
	}
	if (data->map_height > 17)
	{
		ft_printf("Error\nThe map is too big");
		close_window(data);
	}
	return (1);
}
