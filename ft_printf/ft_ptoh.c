/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:26:05 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/04 17:58:26 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_0x(void)
{
	write(1, "0x", 2);
	return (2);
}

static int	ft_puthex(void *ptr)
{
	unsigned long long	nb;
	unsigned long long	nb2;
	int					len;

	nb = (unsigned long long)ptr;
	nb2 = nb % 16;
	len = 0;
	if (nb >= 16)
		len += ft_puthex((void *)(nb / 16));
	if (nb2 <= 9)
		len += ft_putchar(nb2 + 48);
	else if (nb2 == 10)
		len += ft_putchar('a');
	else if (nb2 == 11)
		len += ft_putchar('b');
	else if (nb2 == 12)
		len += ft_putchar('c');
	else if (nb2 == 13)
		len += ft_putchar('d');
	else if (nb2 == 14)
		len += ft_putchar('e');
	else if (nb2 == 15)
		len += ft_putchar('f');
	return (len);
}

int	ft_ptoh(void *ptr)
{
	int					len;
	unsigned long long	nb;

	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len += ft_0x();
	nb = (unsigned long long)ptr;
	len += ft_puthex((void *)nb);
	return (len);
}
