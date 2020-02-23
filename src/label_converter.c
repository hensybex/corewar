/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:10:43 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 11:17:54 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		find_label_part(t_command *buff, int *fl, char *arg)
{
	t_labels	*buff_l;

	if (buff->labels != NULL)
	{
		buff_l = buff->labels;
		while (buff_l && *fl == 0)
		{
			if (ft_strcmp(arg, buff_l->label) == 0)
				*fl = 1;
			buff_l = buff_l->next;
		}
	}
}

int			find_label(char *arg, t_parse *champ)
{
	t_command	*buff;
	int			i;
	int			fl;

	fl = 0;
	i = 0;
	buff = champ->list_cmd;
	while (buff != NULL && fl == 0)
	{
		find_label_part(buff, &fl, arg);
		i++;
		buff = buff->next;
	}
	free(arg);
	if (fl == 0)
		i++;
	return (i);
}

static char	*add_percent_at_start(char *line)
{
	size_t		i;
	char		*new_line;

	i = 0;
	new_line = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	new_line[0] = '%';
	while (i < ft_strlen(line))
	{
		new_line[i + 1] = line[i];
		i++;
	}
	free(line);
	new_line[i + 1] = '\0';
	return (new_line);
}

void		label_conversion(t_parse *champ)
{
	t_command	*buff;
	int			i;
	int			needed_arg;

	buff = champ->list_cmd;
	i = 0;
	while (buff != NULL)
	{
		if ((needed_arg = label_in_arg(buff)) != -1)
		{
			buff->label_size = calculate_sizing(champ, buff, i, needed_arg);
			free(buff->arg[needed_arg]);
			if (buff->arg[needed_arg][0] == DIRECT_CHAR)
				buff->arg[needed_arg] =
				add_percent_at_start(ft_itoa(buff->label_size));
			else
				buff->arg[needed_arg] = ft_itoa(buff->label_size);
		}
		buff = buff->next;
		i++;
	}
}
