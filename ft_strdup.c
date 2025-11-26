/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:44:37 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/26 14:05:20 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;

	i = ft_strlen(s);
	cpy = malloc (sizeof(char) * (i + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
