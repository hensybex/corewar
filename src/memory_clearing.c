/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_clearing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:03:32 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/01 17:32:50 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		free_buff_l(char *buff_l, char *buff)
{
	if (buff_l != buff)
		free(buff_l);
}

void		list_cmd_clear(t_parse *champ)
{
	int			i;
	t_command	*buff;
	t_labels	*buff_l;

	while (champ->list_cmd != NULL)
	{
		i = 0;
		while (i < 3)
			free(champ->list_cmd->arg[i++]);
		while (champ->list_cmd->labels)
		{
			free(champ->list_cmd->labels->label);
			buff_l = champ->list_cmd->labels;
			champ->list_cmd->labels = champ->list_cmd->labels->next;
		}
		buff = champ->list_cmd;
		champ->list_cmd = champ->list_cmd->next;
		free(buff);
	}
}

void		memory_clearing(t_parse *champ)
{
	t_labels	*buff_l;

	free(champ->name);
	free(champ->comment);
	free(champ->exec_code);
	while (champ->labels)
	{
		free(champ->labels->label);
		buff_l = champ->labels;
		champ->labels = champ->labels->next;
		free(buff_l);
	}
	list_cmd_clear(champ);
	free(champ);
}
