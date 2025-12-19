/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_lib_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:00:02 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/19 14:13:50 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_LIB_BONUS_H
# define SO_LONG_LIB_BONUS_H
# include "struct_bonus.h"

int		get_map_height(char *filename);
void	*init_map(char *filename, t_data *data);
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
void	clean_sprites(t_data *data);
int		init_images(t_data *data);
int		init_images2(t_data *data);
void	put_sprite(char c, t_data *data, int i, int height);
int		render_map(t_data *data);
char	*ft_itoa(int n);
int		ft_manage_next(t_data *data, int new_y, int new_x);
int		init_collec(t_data *data);
int		init_player(t_data *data);
int		clean_sprites3(t_data *data);
void	ft_player_rotation(t_data *data, int x_offset, int y_offset);
int		check_extention_args(char *str);
int		check_argc(int argc);
int		check_map_size(t_data *data);

#endif
