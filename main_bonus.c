/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:26:01 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/09 16:52:03 by amurtas          ###   ########.fr       */
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
		ft_printf("The map isn't rectangular\n");
		return (0);
	}
	if (check_wall(data) == 0)
	{
		ft_printf("Error\n");
		ft_printf("The map isn't surrounded by walls\n");
		return (0);
	}
	if (!check_content(data))
	{
		ft_printf("Error\n");
		ft_printf("Wrong quantity of contents\n");
		return (0);
	}
	if (!check_path(data))
	{
		ft_printf("Error\n");
		ft_printf("Impossible path\n");
		return (0);
	}
	return (1);
}

int	img_verif(t_data *lst)
{
	if (!init_images(lst))
	{
		ft_printf("Error\n");
		ft_printf("Can't properly load sprites\n");
		close_window(lst);
		return (0);
	}
	return (1);
}

int	init_struct(t_data *lst)
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
	lst->player_down = NULL;
	lst->player_left = NULL;
	lst->player_right = NULL;
	lst->player_up = NULL;
	lst->enemy = NULL;
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	lst;

	init_struct(&lst);
	lst.mlx = mlx_init();
	if (lst.mlx == NULL)
		return (0);
	if (!check_argc(argc) || !init_map(argv[1], &lst)
		|| !check_extention_args(argv[1]))
	{
		close_window(&lst);
		return (0);
	}
	if (!lst.map || !all_map_verif(&lst))
	{
		close_window(&lst);
		return (0);
	}
	lst.window = mlx_new_window(lst.mlx, 1220, 1220, "So_long");
	if (lst.window == NULL || !img_verif(&lst))
		return (0);
	render_map(&lst);
	mlx_hook(lst.window, 17, 0, close_window, &lst);
	mlx_hook(lst.window, 2, 1L << 0, key_handler, &lst);
	mlx_loop_hook(lst.mlx, &anim_loop, &lst);
	mlx_loop(lst.mlx);
}
