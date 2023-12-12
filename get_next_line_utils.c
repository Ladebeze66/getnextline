/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:03:41 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/04/12 17:47:26 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*new_s;

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[len])
		len++;
	i = 0;
	while (s2 && s2[i])
		i++;
	new_s = ft_calloc_gnl(len + i + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	len = -1;
	while (s1 && s1[++len])
		new_s[len] = s1[len];
	i = -1;
	while (s2 && s2[++i])
		new_s[len + i] = s2[i];
	return (new_s);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
		return (ft_strdup("\0"));
	i = 0;
	while (s1[i])
		i++;
	s2 = ft_calloc_gnl(i + 1, sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void			*r;
	unsigned char	*p;
	size_t			total;
	size_t			i;

	total = count * size;
	r = malloc(total);
	if (!r)
		return (NULL);
	p = (unsigned char *)r;
	i = 0;
	while (i < total)
	{
		p[i] = '\0';
		i++;
	}
	return (r);
}

void	ft_free(char **str, char **str2, char **str3)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
}
