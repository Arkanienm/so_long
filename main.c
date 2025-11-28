/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:26:01 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/28 13:14:23 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "so_long_lib.h"

int	all_map_verif(t_data *data)
{
	if (check_rectangular(data) == 0)
	{
		ft_printf("\nmap non rectangulaire");
		return (0);
	}
	if (check_wall(data) == 0)
	{
		ft_printf("\nmap non entourées de murs");
		return (0);
	}
	if (!check_content(data))
		return (0);
	if (!check_path(data))
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_data	lst;

	lst.map = 0;
	lst.mlx = 0;
	lst.window = 0;
	if (argc != 2)
		return (0);
	lst.mlx = mlx_init();
	if (lst.mlx == NULL)
		return (0);
	init_map(argv[1], &lst);
	if (!lst.map)
		return (0);
	if (!all_map_verif(&lst))
	{
		ft_printf("Error");
		return (0);
	}
	lst.window = mlx_new_window(lst.mlx, 800, 800, "So_long");
	if (lst.window == NULL)
		return (0);
    debug_print_map(&lst);
	if (!init_images(&lst))
	{
		close_window(&lst);
		ft_printf("Error");
		return (0);
	}
	render_map(&lst);
	mlx_hook(lst.window, 17, 0, close_window, &lst);
	mlx_hook(lst.window, 2, 1L<<0, key_handler, &lst);
	mlx_loop(lst.mlx);
}
