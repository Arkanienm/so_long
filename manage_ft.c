/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:03:44 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/15 18:02:21 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "so_long_lib.h"

size_t	ft_strlent(const char *s)
{
	size_t	i;

	i = 0;
	while (*s && s[i] != '\0')
		i++;
	return (i);
}

int	close_window(t_data *data)
{
	if (data->map)
	{
		free_tab(data->map);
		data->map = NULL;
	}
	clean_sprites(data);
	if (data->window)
	{
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	exit(0);
}

void	set_new_var(t_data *data, int new_y, int new_x)
{
	if (data->map[new_y][new_x] == '1')
		return ;
	if (data->map[new_y][new_x] == 'E')
		data->e_verif ++;
	if (data->e_verif == 0)
		data->map[data->player_y][data->player_x] = '0';
	if (data->e_verif == 1)
	{
		data->map[data->player_y][data->player_x] = '0';
		data->e_verif++;
	}
	else if (data->e_verif == 2)
	{
		data->map[data->player_y][data->player_x] = 'E';
		data->e_verif = 0;
	}
	data->map[new_y][new_x] = 'P';
	data->player_x = new_x;
	data->player_y = new_y;
	data->moves_count += 1;
	ft_printf("nombre de pas = %d\n", data->moves_count);
	render_map(data);
}

void	move_player(t_data *data, int x_offset, int y_offset)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x + x_offset;
	new_y = data->player_y + y_offset;
	if (data->map[new_y][new_x] == 'E')
	{
		if (data->collectibles_left == 0)
		{
			ft_printf("VICTOIRE\n");
			close_window(data);
		}
	}
	if (data->map[new_y][new_x] == 'C')
	{
		data->collectibles_left -= 1;
		data->map[new_y][new_x] = '0';
	}
	set_new_var(data, new_y, new_x);
}

int	key_handler(int keycode, t_data *lst)
{
	if (!keycode)
		return (0);
	if (keycode == 65307)
		close_window(lst);
	if (keycode == 119)
		move_player(lst, 0, -1);
	if (keycode == 97)
		move_player(lst, -1, 0);
	if (keycode == 115)
		move_player(lst, 0, 1);
	if (keycode == 100)
		move_player(lst, 1, 0);
	return (0);
}
