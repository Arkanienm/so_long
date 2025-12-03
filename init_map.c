/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:58:47 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/28 17:54:01 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "so_long_lib.h"

int	get_map_height(char *filename)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height ++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (height);
}

int	call_map_height(t_data *data, char *filename)
{
	data->map_height = get_map_height(filename);
	if (data->map_height == 0)
	{
		data->map = NULL;
		return (0);
	}
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		return (0);
	return (1);
}

void	*init_map(char *filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free (data->map);
		data->map = NULL;
		return (NULL);
	}
	call_map_height(data, filename);
	line = get_next_line(fd);
	while (line != NULL)
	{
		data->map[i] = line;
		if (i == 0)
			data->map_width = ft_strlent(line) - 1;
		i++;
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	close(fd);
	return (data->map);
}
