/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 05:29:28 by medesmon          #+#    #+#             */
/*   Updated: 2020/02/23 11:17:22 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			is_empty(char *line)
{
	line = skip_whitespace(line);
	if (line == '\0')
		return (1);
	else
		return (0);
}

char		*pass_label(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (str[i] != LABEL_CHAR)
		i++;
	i++;
	new_str = (char *)gmalloc(sizeof(char) * (ft_strlen(str) - i + 1));
	j = 0;
	while (str[i])
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

t_labels	*add_label_row(char *line, t_labels *labels_row)
{
	t_labels	*buff;
	char		*tmp;

	if (labels_row == NULL)
	{
		labels_row = (t_labels *)gmalloc(sizeof(t_labels));
		tmp = cut_label(line);
		labels_row->label = ft_strdup(tmp);
		free(tmp);
		labels_row->next = NULL;
	}
	else
	{
		buff = labels_row;
		while (buff->next != NULL)
			buff = buff->next;
		buff->next = (t_labels *)gmalloc(sizeof(t_labels));
		tmp = cut_label(line);
		buff->next->label = ft_strdup(tmp);
		free(tmp);
		buff->next->next = NULL;
	}
	return (labels_row);
}

static char	*ft_strxjoin(char const *s1, char const *s2)
{
	char			*mem;
	int				len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	mem = (char *)gmalloc(sizeof(*mem) * len);
	if (mem == NULL)
		return (NULL);
	ft_strcpy(mem, s1);
	ft_strcat(mem, s2);
	return (mem);
}

void		label_processing(char *line, int fd, t_parse *champ)
{
	char		*buff;
	char		*buff_j;
	t_labels	*labels_row;

	labels_row = NULL;
	labels_row = add_label_row(line, labels_row);
	buff = skip_whitespace(ft_strchr(line, LABEL_CHAR) + 1);
	while ((is_empty(buff) || buff[0] == '\0') && get_next_line(fd, &line) > 0)
	{
		buff_j = ft_strxjoin(buff, line);
		buff = cut_comment(buff_j);
		champ->line_num++;
		if (is_label(buff))
		{
			labels_row = add_label_row(buff, labels_row);
			buff = pass_label(buff);
		}
		free(line);
	}
	command_search(cut_comment(buff), champ, labels_row);
}
