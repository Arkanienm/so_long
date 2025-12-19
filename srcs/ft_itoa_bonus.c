/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:09:01 by amurtas           #+#    #+#             */
/*   Updated: 2025/12/01 15:36:09 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_lib_bonus.h"

static int	ft_intlen(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	long int	n1;
	char		*str;
	int			len;

	len = ft_intlen(n);
	n1 = (long int)n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n1 *= -1;
	}
	str[len] = '\0';
	len--;
	while (n1 > 0)
	{
		str[len] = (n1 % 10) + 48;
		n1 /= 10;
		len--;
	}
	return (str);
}
