/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:29:50 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/04 17:57:22 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *s);
int		ft_itoh_down(unsigned int nb);
int		ft_itoh_up(unsigned int nb);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
int		ft_putchar(char c);
int		ft_putformat(const char *format, va_list *arg_ptr);
int		ft_ptoh(void *ptr);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int nb);

#endif
