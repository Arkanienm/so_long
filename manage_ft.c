/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:03:44 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/27 16:36:05 by amurtas          ###   ########.fr       */
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

int	close_window(t_data *lst)
{
	if (lst->img)
		mlx_destroy_image(lst->mlx, lst->img);
	if (lst->window)
		mlx_destroy_window(lst->mlx, lst->window);
	mlx_destroy_display(lst->mlx);
	free(lst->mlx);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_data *lst)
{
	if (!keycode)
		return (0);
	if (keycode == 65307)
		close_window(lst);
	return (0);
}