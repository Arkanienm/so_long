/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:09:37 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/04 17:58:29 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_verifformat(char *form)
{
	size_t	formlen;

	formlen = ft_strlen(form);
	if (ft_strnstr(form, "%c", formlen))
		return (1);
	else if (ft_strnstr(form, "%s", formlen))
		return (2);
	else if (ft_strnstr(form, "%p", formlen))
		return (3);
	else if (ft_strnstr(form, "%d", formlen))
		return (4);
	else if (ft_strnstr(form, "%i", formlen))
		return (5);
	else if (ft_strnstr(form, "%u", formlen))
		return (6);
	else if (ft_strnstr(form, "%x", formlen))
		return (7);
	else if (ft_strnstr(form, "%X", formlen))
		return (8);
	else if (ft_strnstr(form, "%%", formlen))
		return (9);
	else
		return (0);
}

static int	ft_callft(int form, va_list *arg_ptr)
{
	int	len;

	len = 0;
	if (form == 0)
		return (len);
	if (form == 1)
		len += ft_putchar(va_arg(*arg_ptr, int));
	if (form == 2)
		len += ft_putstr(va_arg(*arg_ptr, char *));
	if (form == 3)
		len += ft_ptoh(va_arg(*arg_ptr, void *));
	if (form == 4)
		len += ft_putnbr(va_arg(*arg_ptr, int));
	if (form == 5)
		len += ft_putnbr(va_arg(*arg_ptr, int));
	if (form == 6)
		len += ft_putunbr(va_arg(*arg_ptr, unsigned int));
	if (form == 7)
		len += ft_itoh_down(va_arg(*arg_ptr, unsigned int));
	if (form == 8)
		len += ft_itoh_up(va_arg(*arg_ptr, unsigned int));
	if (form == 9)
		len += ft_putchar('%');
	return (len);
}

int	ft_putformat(const char *format, va_list *arg_ptr)
{
	int		i;
	char	form[2];
	int		type;
	int		len;

	len = 0;
	type = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			form[0] = format[i];
			form[1] = format[i + 1];
			type = ft_verifformat(form);
			len += ft_callft(type, arg_ptr);
			i += 2;
		}
		if (format[i] != '%' && format[i] != '\0')
			len ++;
		if (format[i] != '\0' && format[i] != '%')
			write(1, &format[i++], 1);
	}
	return (len);
}
