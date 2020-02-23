/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_comment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:40:28 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 11:19:08 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	comment_search_part_1(char *buff, t_parse *champ)
{
	int i;

	i = 0;
	while (buff[i] != '"')
	{
		if (buff[i] != ' ' && buff[i] != '	')
		{
			if (buff[i] == '\0')
				error("Comment missing", champ->line_num);
			else
				error("Smth before comment", champ->line_num);
		}
		i++;
	}
}

void	comment_search_part_2(char *buff, t_parse *champ)
{
	int i;

	i = 0;
	while (buff[i] != '"')
		i++;
	champ->comment = ft_strndup(buff, i);
	if (i > COMMENT_LENGTH)
		error("Comment length beyound limits", champ->line_num);
	if (buff[i + 1] != '\0')
		error("Simbols after comment", champ->line_num);
}

void	comment_search(char *line, t_parse *champ, int fd)
{
	char *buff;

	if (champ->comment != NULL)
		error("Double comment", champ->line_num);
	buff = ft_strstr(line, COMMENT_CMD_STRING) + ft_strlen(COMMENT_CMD_STRING);
	comment_search_part_1(buff, champ);
	buff = ft_strchr(line, '"');
	buff++;
	while (ft_strchr(buff, '"') == NULL && get_next_line(fd, &line) > 0)
	{
		champ->line_num++;
		buff = ft_strjoin(buff, "\n");
		buff = ft_strjoin(buff, line);
	}
	if (ft_strchr(buff, '"') == NULL)
		error("Quotation mark after comment missing", champ->line_num);
	comment_search_part_2(buff, champ);
}

char	*line_processing_part(char *new_line,
char *line, t_parse *champ, int fd)
{
	char *buff_l;

	if (is_label(new_line))
	{
		free(new_line);
		buff_l = cut_comment(line);
		new_line = ft_strdup(buff_l);
		label_processing(new_line, fd, champ);
	}
	else
	{
		free(new_line);
		buff_l = cut_comment(line);
		new_line = ft_strdup(buff_l);
		command_search(new_line, champ, NULL);
	}
	return (new_line);
}

void	line_processing(char *line, t_parse *champ, int fd)
{
	char	*new_line;

	if (line[0] == COMMENT_CHAR
	|| line[0] == ALT_COMMENT_CHAR || line[0] == '\0')
		return ;
	new_line = ft_strdup(line);
	if (ft_strstr(new_line, NAME_CMD_STRING))
		name_search(new_line, champ, fd);
	else if (ft_strstr(new_line, COMMENT_CMD_STRING))
		comment_search(new_line, champ, fd);
	else
		new_line = line_processing_part(new_line, line, champ, fd);
	free(new_line);
}
