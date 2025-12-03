/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:48:04 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/04 17:58:32 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	f_count_len(unsigned int nb)
{
	int	len;
	unsigned int	zero;

	zero = 0;
	len = 0;
	if (nb < zero)
	{
		nb *= -1;
		len ++;
	}
	while (nb > 9)
	{
		nb /= 10;
		len ++;
	}
	return (len + 1);
}

int	ft_putunbr(unsigned int nb)
{
	int	len;

	len = f_count_len(nb);
	if (nb <= 9)
	{
		nb += 48;
		write(1, &nb, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (len);
}
