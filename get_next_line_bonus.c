/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:02:03 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/04/12 18:08:04 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*rec_line_before_nl(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	res = ft_calloc_gnl(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*rec_after_nl(const char *s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	while (s && s[j])
		j++;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	res = ft_calloc_gnl((j - i) + 1, sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		res[j] = s[i + j];
		j++;
	}
	return (res);
}

void	ft_read_line(int fd, char **keep, char **tmp)
{
	char	*buf;
	int		byte_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
		{
			ft_free(&buf, keep, tmp);
			return ;
		}
		buf[byte_read] = '\0';
		*tmp = ft_strdup(*keep);
		ft_free(keep, 0, 0);
		*keep = ft_strjoin_gnl(*tmp, buf);
		ft_free(tmp, 0, 0);
		if (find_newline(*keep))
			break ;
	}
	ft_free(&buf, 0, 0);
}

char	*ft_gnl_recal(char **keep, char **tmp)
{
	char	*line;

	*tmp = ft_strdup(*keep);
	ft_free(keep, 0, 0);
	*keep = rec_after_nl(*tmp);
	line = rec_line_before_nl(*tmp);
	ft_free(tmp, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*keep[1024];
	char		*tmp;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	tmp = NULL;
	ft_read_line(fd, &keep[fd], &tmp);
	if (keep[fd] != NULL && *keep[fd] != '\0')
		line = ft_gnl_recal(&keep[fd], &tmp);
	if (!line || *line == '\0')
	{
		ft_free(&keep[fd], &line, &tmp);
		return (NULL);
	}
	return (line);
}
