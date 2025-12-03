/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtas <amurtas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:45:37 by amurtas           #+#    #+#             */
/*   Updated: 2025/11/13 14:47:56 by amurtas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*cs;

	if (!s1 || !s2)
		return (NULL);
	cs = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cs)
		return (NULL);
	i = 0;
	while ((s1)[i] != '\0')
	{
		cs[i] = (s1)[i];
		i++;
	}
	i = 0;
	while ((s2)[i] != '\0')
	{
		cs[ft_strlen(s1) + i] = (s2)[i];
		i++;
	}
	cs[ft_strlen(s1) + i] = '\0';
	return (cs);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sbstr;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		sbstr = ft_strdup("");
		return (sbstr);
	}
	sbstr = malloc(sizeof(char) * len + 1);
	if (!sbstr)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sbstr[i] = s[start + i];
		i++;
	}
	sbstr[i] = '\0';
	return (sbstr);
}

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

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cs;

	cs = (unsigned char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == cs)
			return ((char *)s + i);
		i++;
	}
	if (cs == 0 && !s[i])
		return ((char *)s + i);
	return (NULL);
}
