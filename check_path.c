/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:14:45 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/28 17:39:48 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "so_long_lib.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

int	check_path(t_data *data)
{
	char	**tab;
	int		p_x;
	int		p_y;
	int		i;

	i = 0;
	p_x = 0;
	p_y = 0;
	tab = copy_map(data);
	if (!tab)
		return (0);
	pathing(data, &p_x, &p_y);
	flood_fill(tab, p_x, p_y);
	if (!flood_verif(tab, data))
	{
		free_tab(tab);
		return (0);
	}
	free_tab(tab);
	return (1);
}
