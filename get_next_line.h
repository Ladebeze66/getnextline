/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:41:38 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/04/12 17:45:17 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
void	ft_read_line(int fd, char **keep, char **tmp);
char	*ft_gnl_recal(char **keep, char **tmp);
char	*rec_line_before_nl(const char *s);
char	*rec_after_nl(const char *s);

int		find_newline(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin_gnl(const char *s1, const char *s2);
void	*ft_calloc_gnl(size_t count, size_t size);
void	ft_free(char **str, char **str2, char **str3);

#endif
