/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:33:48 by smanhack          #+#    #+#             */
/*   Updated: 2020/01/31 22:31:55 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	name_search_part_2(char *buff, t_parse *champ)
{
	int i;

	if (ft_strchr(buff, '"') == NULL)
		error("Quotation mark after name missing", champ->line_num);
	i = 0;
	while (buff[i] != '"')
		i++;
	champ->name = ft_strndup(buff, i);
	if (i > PROG_NAME_LENGTH)
		error("Name length beyound limit", champ->line_num);
	if (buff[i + 1] != '\0')
		error("Simbols after name", champ->line_num);
}

void	name_search_part_1(char *buff, t_parse *champ)
{
	int i;

	i = 0;
	while (buff[i] != '"')
	{
		if (buff[i] != ' ' && buff[i] != '	')
		{
			if (buff[i] == '\0')
				error("Name missing", champ->line_num);
			else
				error("Smth before name", champ->line_num);
		}
		i++;
	}
}

void	name_search(char *line, t_parse *champ, int fd)
{
	char	*buff;

	if (champ->name != NULL)
		error("Double name", champ->line_num);
	buff = ft_strstr(line, NAME_CMD_STRING) + ft_strlen(NAME_CMD_STRING);
	name_search_part_1(buff, champ);
	buff = ft_strchr(line, '"');
	buff++;
	while (ft_strchr(buff, '"') == NULL && get_next_line(fd, &line) > 0)
	{
		champ->line_num++;
		buff = ft_strjoin(buff, "\n");
		buff = ft_strjoin(buff, line);
	}
	name_search_part_2(buff, champ);
}

char	*cut_before(char *str, int place)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)gmalloc(sizeof(char) * (place + 1));
	while (i < place)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*cut_comment(char *line)
{
	int	i;
	int	fl;
	int	place;

	i = 0;
	fl = 0;
	while (line[i] && fl == 0)
	{
		if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR)
		{
			fl = 1;
			place = i;
		}
		i++;
	}
	if (fl == 0)
		return (line);
	else
		return (cut_before(line, place));
}
