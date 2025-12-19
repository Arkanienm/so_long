/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:11:32 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/05 11:14:58 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		len;

	len = 0;
	va_start(arg_ptr, format);
	if (!format)
		return (-1);
	if (format)
		len = ft_putformat(format, &arg_ptr);
	va_end(arg_ptr);
	return (len);
}
