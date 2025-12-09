/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:36:34 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/09 16:51:40 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int	check_argc(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error\nWrong quantity of arguments\n");
		return (0);
	}
	return (1);
}

int	check_extention_args(char *str)
{
	int	i;
	int	verif;

	verif = 0;
	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b'
		&& str[i - 3] == '.')
		verif = 1;
	if (verif == 0)
	{
		ft_printf("Error\n");
		ft_printf("Wrong map extention");
		return (0);
	}
	return (1);
}
