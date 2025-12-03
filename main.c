/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:26:01 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/03 15:46:13 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "so_long_lib.h"

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
	mlx_loop(lst.mlx);
}
