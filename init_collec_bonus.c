/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collec_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:51:35 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/03 15:36:35 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"
#include "so_long_lib_bonus.h"

int	init_collec(t_data *data)
{
	data->collec2 = mlx_xpm_file_to_image (data->mlx, "sprites/collec1.xpm",
			&data->img_width, &data->img_height);
	if (!data->collec)
	{
		clean_sprites (data);
		return (0);
	}
	data->collec3 = mlx_xpm_file_to_image (data->mlx, "sprites/collec2.xpm",
			&data->img_width, &data->img_height);
	if (!data->collec3)
	{
		clean_sprites (data);
		return (0);
	}
	data->collec4 = mlx_xpm_file_to_image (data->mlx, "sprites/collec3.xpm",
			&data->img_width, &data->img_height);
	if (!data->collec4)
	{
		clean_sprites (data);
		return (0);
	}
	if (data->collec)
		data->cur_coll = data->collec;
	return (1);
}
