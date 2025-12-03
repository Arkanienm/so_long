/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:26:05 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/04 17:58:19 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_len(unsigned int nb)
{
	int	len;

	len = 1;
	while (nb / 16 > 0)
	{
		nb /= 16;
		len ++;
	}
	return (len);
}

static void	ft_low_write_letter(unsigned int nb)
{
	if (nb == 10)
		write(1, "a", 1);
	if (nb == 11)
		write(1, "b", 1);
	if (nb == 12)
		write(1, "c", 1);
	if (nb == 13)
		write(1, "d", 1);
	if (nb == 14)
		write(1, "e", 1);
	if (nb == 15)
		write(1, "f", 1);
}

int	ft_itoh_down(unsigned int nb)
{
	int	len;
	unsigned int	zero;

	zero = 0;
	len = count_len(nb);
	if (nb < zero)
		nb *= -1;
	if (nb <= 9)
	{
		nb += 48;
		write(1, &nb, 1);
	}
	else if (nb >= 16)
	{
		ft_itoh_down(nb / 16);
		ft_itoh_down(nb % 16);
	}
	ft_low_write_letter(nb);
	return (len);
}
