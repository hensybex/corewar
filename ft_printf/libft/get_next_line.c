/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 04:23:01 by medesmon          #+#    #+#             */
/*   Updated: 2020/01/31 15:28:38 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static size_t	ft_strclen(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char		*ft_strdel1join(char *s1, char *s2)
{
	char			*mem;
	int				len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	mem = (char *)malloc(sizeof(*mem) * len);
	if (mem == NULL)
		return (NULL);
	ft_strcpy(mem, s1);
	ft_strcat(mem, s2);
	ft_strdel(&s1);
	return (mem);
}

static int		divide_tmp(char **line,
		char *fd_lines[FD_MAX_NUM], char **tmp, int fd)
{
	int		len;

	if (!**tmp)
	{
		ft_strdel(tmp);
		return (0);
	}
	len = ft_strclen(*tmp, '\n');
	*line = ft_strsub(*tmp, 0, len);
	if (!(tmp[0][len]))
		fd_lines[fd] = ft_strnew(0);
	else
	{
		fd_lines[fd] =
			ft_strsub(*tmp, len + 1, ft_strlen(*tmp + len + 1));
		if (!fd_lines[fd])
			return (-1);
	}
	ft_strdel(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	ssize_t		ret;
	static char	*fd_lines[FD_MAX_NUM];

	if (!line || BUFF_SIZE <= 0 || fd < 0 || fd > FD_MAX_NUM - 1 ||
			(ret = read(fd, buff, 0)) < 0)
		return (-1);
	if (fd_lines[fd])
		tmp = ft_strdup(fd_lines[fd]);
	else
		tmp = ft_strnew(0);
	ft_strdel(&fd_lines[fd]);
	if (!ft_strchr(tmp, '\n'))
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			tmp = ft_strdel1join(tmp, buff);
			if (ft_strchr(buff, '\n'))
				break ;
		}
	if (ret < 0 || !tmp)
		return (-1);
	return (divide_tmp(line, fd_lines, &tmp, fd));
}
