/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:58:47 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/27 17:28:00 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "so_long_lib.h"

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

void *init_map(char *filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	data->map_height = get_map_height(filename);
	if (data->map_height == 0)
		return (NULL);
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free (data->map);
		return (NULL);		
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
	return (NULL);
}

void debug_print_map(t_data *data)
{
    int i = 0;

    ft_printf("--- DEBUT DEBUG MAP ---\n");
    ft_printf("Largeur: %d | Hauteur: %d\n", data->map_width, data->map_height);
    
    if (!data->map)
    {
        ft_printf("Erreur: Map est NULL\n");
        return;
    }

    while (data->map[i])
    {
        ft_printf("Ligne %d : %s", i, data->map[i]); 
        i++;
    }
    ft_printf("--- FIN DEBUG MAP ---\n");
}