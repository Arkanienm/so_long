/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:58:47 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/15 17:58:44 by amurtas          ###   ########.fr       */
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

int	return_error(int fd, t_data	*data)
{
	if (fd < 0)
	{
		free (data->map);
		data->map = NULL;
		ft_printf("Error\nCan't open the file\n");
		return (0);
	}
	return (1);
}

int	verif_line(char *line, int fd)
{
	if (!line)
	{
		ft_printf("Error\nEmpty file\n");
		close (fd);
		return (0);
	}
	return (1);
}

void	*init_map(char *filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (!return_error(fd, data))
		return (NULL);
	call_map_height(data, filename);
	line = get_next_line(fd);
	if (!verif_line(line, fd))
		return (0);
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
