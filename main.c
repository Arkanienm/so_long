/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:26:01 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/26 18:11:49 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>

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

int get_map_height(char *filename)
{
	int		fd; 
	char	*line;
	int		height;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	while ((line = get_next_line(fd)))
	{
		height ++;
		free(line);
	}
	close(fd);
	return (height);
}

void init_map(char *filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	data->map_height = get_map_height(filename);
	if (data->map_height == 0)
		return ;
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		return ;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free (data->map);
		return ;		
	}
	while ((line = get_next_line(fd)))
	{
		data->map[i] = line;
		if (i == 0)
			data->map_width = ft_strlent(line) - 1;
		i++;
	}
	data->map[i] = NULL;
	close(fd);
}

void debug_print_map(t_data *data)
{
    int i = 0;

    printf("--- DEBUT DEBUG MAP ---\n");
    printf("Largeur: %d | Hauteur: %d\n", data->map_width, data->map_height);
    
    if (!data->map)
    {
        printf("Erreur: Map est NULL\n");
        return;
    }

    while (data->map[i])
    {
        printf("Ligne %d : %s", i, data->map[i]); 
        i++;
    }
    printf("--- FIN DEBUG MAP ---\n");
}

int	check_rectangular(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < data->map_height)
	{
		len = ft_strlent(data->map[i]);
		if (len > 0 && data->map[i][len - 1] == '\n')
			len --;
		if (len != data->map_width)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_width - 1)
	{
		if (data->map[0][i] != '1' || data->map[data->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->map_height)
	{
		if (data->map[i][0] != '1' || data->map[i][data->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void content_verif(t_data *data, int height, int width, int tab[3])
{
	char	c;
	
	c = data->map[height][width];
	if (c == 'P')
		tab[0] += 1;
	if (c == 'E')
		tab[1] += 1;
	if (c == 'C')
		tab[2] += 1;
}

int	wrong_caracter(t_data *data, int height, int width)
{
	char	c;

	c = data->map[height][width];
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
		return (0);
	return (1);
}

int	check_content(t_data *data)
{
	int	height;
	int	width;
	int tab[3];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	height = 0;
	width = 0;
	while (height < data->map_height)
	{
		width = 0;
		while (width < data->map_width)
		{
			content_verif(data, height, width, tab);
			if (wrong_caracter(data, height, width))
				return (0);
			width ++;
		}
		height++;
	}
	if (tab[0] == 1 && tab[1] == 1 && tab[2] >= 1)
		return (1);
	else
		return (0);
}

char **copy_map(t_data *data)
{
	char **copy;
	int	i;

	i = 0;
	copy = malloc(sizeof(char *) * (data->map_height + 1));
	if (!copy)
		return (NULL);
	while (i < data->map_height)
	{
		copy[i] = ft_strdup(data->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void flood_fill(char **tab, int x, int y)
{
	if (tab[y][x] == '1' || tab[y][x] == 'v')
		return ;
	tab[y][x] = 'v';
	flood_fill(tab, x + 1, y);
	flood_fill(tab, x - 1, y);
	flood_fill(tab, x, y + 1);
	flood_fill(tab, x, y - 1);
}

int *pathing(char **tab, t_data *data)
{
	int	tab[2];
	int	height;
	int i;
	
	height = 0;
	i = 0;
	tab[0] = 0;
	tab[1] = 0;
	while (height < data->map_height)
	{
		while (i < data->map_width)
		{
			if (tab[height][i] == 'P')
			{
				tab[0] = i;
				tab[1] = height;
				return (0);
			}
			i++;
		}
		i = 0;
		height++;		
	}
	return (0);
}

int	flood_verif(char **tab, t_data *data)
{
	int	height;
	int i;
	
	height = 0;
	i = 0;
	while (height < data->map_height)
	{
		while (i < data->map_width)
		{
			if (tab[height][i] == 'C' || tab[height][i] == 'E')
				return (0);
			i++;
		}
		i = 0;
		height++;		
	}
	return (1);
}

int	check_path(char	**tab, t_data *data)
{
	int	i;
	int	height;
	int	p_x;
	int	p_y;

	i = 0;
	if (!tab)
		return (NULL);
	p_x = pathing(tab, data)[0];
	p_y	= pathing(tab, data)[1];
	flood_fill(tab, p_x, p_y);
	flood_verif(tab, data);
}

int main(void)
{
	t_data	lst;


	lst.mlx = mlx_init();
	if (lst.mlx == NULL)
		return (0);
	init_map("map1.ber", &lst); 
	lst.window = mlx_new_window(lst.mlx, 800, 800, "So_long");
	if (lst.window == NULL)
		return (0);
    debug_print_map(&lst);
	mlx_hook(lst.window, 17, 0, close_window, &lst);
	mlx_hook(lst.window, 2, 1L<<0, key_handler, &lst);
	lst.img = mlx_xpm_file_to_image(lst.mlx, "idle_down00.xpm", &lst.img_width, &lst.img_height);
	mlx_put_image_to_window(lst.mlx, lst.window, lst.img, 0, 0);
	printf("check_content = %d", check_content(&lst));
	if (check_rectangular(&lst) == 0)
	{
		printf("\nmap non rectangulaire");
		close_window(&lst);
		return (0);
	}
	if (check_wall(&lst) == 0)
	{
		printf("\nmap non entourées de murs");
		close_window(&lst);
		return (0);
	}
	mlx_loop(lst.mlx);
}
