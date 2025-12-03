/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:26:01 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/03 16:22:38 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"
#include "so_long_lib_bonus.h"

int	anim_loop(t_data *data)
{
	data->loop_count++;
	if (data->loop_count < 10000)
		return (0);
	data->loop_count = 0;
	data->anim_frame ++;
	if (data->anim_frame > 3)
		data->anim_frame = 0;
	if (data->anim_frame == 0)
		data->cur_coll = data->collec;
	else if (data->anim_frame == 1)
		data->cur_coll = data->collec2;
	else if (data->anim_frame == 2)
		data->cur_coll = data->collec3;
	else if (data->anim_frame == 3)
		data->cur_coll = data->collec4;
	render_map(data);
	return (0);
}

int	all_map_verif(t_data *data)
{
	if (check_rectangular(data) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (check_wall(data) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!check_content(data))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!check_path(data))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int	img_verif(t_data *lst)
{
	if (!init_images(lst))
	{
		close_window(lst);
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

void	init_struct(t_data *lst)
{
	lst->map = NULL;
	lst->mlx = NULL;
	lst->window = NULL;
	lst->wall = NULL;
	lst->floor = NULL;
	lst->player_up = NULL;
	lst->collec = NULL;
	lst->exit = NULL;
	lst->moves_count = 0;
	lst->collectibles_left = 0;
	lst->collec2 = NULL;
	lst->collec3 = NULL;
	lst->collec4 = NULL;
	lst->cur_coll = lst->collec;
	lst->loop_count = 0;
	lst->anim_frame = 0;
}

int	main(int argc, char **argv)
{
	t_data	lst;

	init_struct(&lst);
	if (argc != 2)
		return (0);
	lst.mlx = mlx_init();
	if (lst.mlx == NULL)
		return (0);
	if (!init_map(argv[1], &lst))
		close_window(&lst);
	if (!lst.map)
		return (0);
	if (!all_map_verif(&lst))
		return (0);
	lst.window = mlx_new_window(lst.mlx, 1220, 1220, "So_long");
	if (lst.window == NULL)
		return (0);
	if (!img_verif(&lst))
		return (0);
	render_map(&lst);
	mlx_hook(lst.window, 17, 0, close_window, &lst);
	mlx_hook(lst.window, 2, 1L << 0, key_handler, &lst);
	mlx_loop_hook(lst.mlx, &anim_loop, &lst);
	mlx_loop(lst.mlx);
}
