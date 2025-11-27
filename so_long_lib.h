/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_lib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:00:02 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/27 16:16:22 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_LIB_H
#define SO_LONG_LIB_H
#include "struct.h"

int		get_map_height(char *filename);
void	*init_map(char *filename, t_data *data);
void	debug_print_map(t_data *data);
size_t	ft_strlent(const char *s);
int		close_window(t_data *lst);
int		key_handler(int keycode, t_data *lst);
int		check_rectangular(t_data *data);
int		check_wall(t_data *data);
void	content_verif(t_data *data, int height, int width, int tab[3]);
int		wrong_caracter(t_data *data, int height, int width);
int		check_content(t_data *data);
char	**copy_map(t_data *data);
void	flood_fill(char **tab, int x, int y);
void	pathing(t_data *data, int *x, int *y);
int		flood_verif(char **tab, t_data *data);
void	free_tab(char **tab);
int		check_path(t_data *data);

#endif