/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:54:36 by medesmon          #+#    #+#             */
/*   Updated: 2020/02/23 11:16:46 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	add_label(char *line, t_parse *champ)
{
	t_labels	*buff;
	char		*buff_c;

	if (champ->labels == NULL)
	{
		champ->labels = (t_labels *)malloc(sizeof(t_labels));
		buff_c = cut_label(line);
		champ->labels->label = ft_strdup(buff_c);
		free(buff_c);
		champ->labels->next = NULL;
	}
	else
	{
		buff = champ->labels;
		while (buff->next != NULL)
			buff = buff->next;
		buff->next = (t_labels *)malloc(sizeof(t_labels));
		buff_c = cut_label(line);
		buff->next->label = ft_strdup(buff_c);
		free(buff_c);
		buff->next->next = NULL;
	}
}

int		skip_whitespace_i(char *line)
{
	int i;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	return (i);
}

void	skip_lc(int *i, char *line)
{
	while (line[*i] && line[*i] != LABEL_CHAR
	&& line[*i] != ' ' && line[*i] != '\t')
		(*i)++;
}

char	*new_l(char *line)
{
	size_t		i;
	char		*new_line;

	i = 0;
	i = ft_strlen(line);
	new_line = (char *)gmalloc(sizeof(char) * (i + 1));
	i = 0;
	while (i < ft_strlen(line))
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

void	label_search(char *line, t_parse *champ, int fd)
{
	int		i;
	char	*buff;
	char	*buff_l;
	char	*new_line;

	(void)fd;
	if (line[0] == COMMENT_CHAR || line[0] == ALT_COMMENT_CHAR)
		return ;
	buff = line;
	buff_l = cut_comment(line);
	new_line = new_l(buff_l);
	i = skip_whitespace_i(new_line);
	skip_lc(&i, new_line);
	if (new_line[i - 1] == DIRECT_CHAR && new_line[i] == LABEL_CHAR)
		check_exception(new_line, champ->line_num);
	else if (new_line[i] == LABEL_CHAR)
	{
		check_label_symbols(new_line, champ->line_num);
		add_label(new_line, champ);
	}
}
