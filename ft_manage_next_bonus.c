/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_next_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:05:36 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/03 17:20:08 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"
#include "so_long_lib_bonus.h"

int	ft_manage_next(t_data *data, int new_y, int new_x)
{
	if (data->map[new_y][new_x] == 'N')
	{
		ft_printf("GAME OVER");
		close_window(data);
		return (0);
	}
	if (data->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	ft_player_rotation(t_data *data, int x_offset, int y_offset)
{
	if (y_offset == -1)
		data->cur_play = data->player_up;
	if (y_offset == 1)
		data->cur_play = data->player_down;
	if (x_offset == -1)
		data->cur_play = data->player_left;
	if (x_offset == 1)
		data->cur_play = data->player_right;
}
