/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:26:06 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/25 11:26:07 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>

#include <stdio.h>

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*img;
	int		img_width;
	int		img_height;
	char	**map;
	int		map_width;
	int		map_height;
}	t_data;

#endif