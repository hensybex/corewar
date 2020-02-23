/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizing_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:16:14 by smanhack          #+#    #+#             */
/*   Updated: 2020/01/31 15:16:40 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

size_t		calculate_sizing_search_part(int cmd_num,
int needed_arg, t_command *buff, int label_place)
{
	int		i;
	size_t	size;

	size = 0;
	i = 0;
	while (i != cmd_num + 1)
	{
		if (i == cmd_num)
			size += sizing_line_down(buff, needed_arg);
		i++;
		buff = buff->next;
	}
	while (i != label_place - 1)
	{
		size += sizing(buff);
		buff = buff->next;
		i++;
	}
	return (size);
}

size_t		calculate_sizing_search(int cmd_num,
int needed_arg, t_command *buff, int label_place)
{
	size_t		size;
	int			i;

	i = 0;
	size = 0;
	if (cmd_num < label_place)
		size += calculate_sizing_search_part(cmd_num,
		needed_arg, buff, label_place);
	else
	{
		while (i != label_place - 1)
		{
			i++;
			buff = buff->next;
		}
		while (i != cmd_num)
		{
			size += sizing(buff);
			i++;
			buff = buff->next;
		}
		size *= -1;
	}
	return (size);
}

size_t		calculate_sizing(t_parse *champ,
t_command *command, int cmd_num, int needed_arg)
{
	int			label_place;
	t_command	*buff;

	buff = champ->list_cmd;
	if (command->arg[needed_arg][0] == '%')
		label_place = find_label(
			cut_first_two_symbols(command->arg[needed_arg]), champ);
	else
		label_place = find_label(
			cut_first_symbol(command->arg[needed_arg]), champ);
	if (cmd_num + 1 == label_place)
		return (0);
	return (calculate_sizing_search(cmd_num, needed_arg, buff, label_place));
}
