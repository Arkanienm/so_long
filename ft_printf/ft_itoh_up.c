/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:26:05 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/04 17:58:21 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ftcount_len(unsigned int nb)
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

static void	ft_write_up_letter(unsigned int nb)
{
	if (nb == 10)
		write(1, "A", 1);
	if (nb == 11)
		write(1, "B", 1);
	if (nb == 12)
		write(1, "C", 1);
	if (nb == 13)
		write(1, "D", 1);
	if (nb == 14)
		write(1, "E", 1);
	if (nb == 15)
		write(1, "F", 1);
}

int	ft_itoh_up(unsigned int nb)
{
	int	len;
	int	zero;

	zero = 0;
	len = ftcount_len(nb);
	if (nb < zero)
		nb *= -1;
	if (nb <= 9)
	{
		nb += 48;
		write(1, &nb, 1);
	}
	else if (nb >= 16)
	{
		ft_itoh_up(nb / 16);
		ft_itoh_up(nb % 16);
	}
	ft_write_up_letter(nb);
	return (len);
}
