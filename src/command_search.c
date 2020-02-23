/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 03:22:21 by medesmon          #+#    #+#             */
/*   Updated: 2020/02/23 11:15:51 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_command_part(t_command *cmd, char *line, t_parse *champ)
{
	if (cmd->type == 8)
		check_zjmp(cmd, line, champ);
	else if (cmd->type == 9)
		check_ldi(cmd, line, champ);
	else if (cmd->type == 10)
		check_sti(cmd, line, champ);
	else if (cmd->type == 11)
		check_fork(cmd, line, champ);
	else if (cmd->type == 12)
		check_lld(cmd, line, champ);
	else if (cmd->type == 13)
		check_lldi(cmd, line, champ);
	else if (cmd->type == 14)
		check_lfork(cmd, line, champ);
	else
		check_aff(cmd, line, champ);
}

void	check_command(t_command *cmd, char *line, t_parse *champ)
{
	if (cmd->type == 0)
		check_live(cmd, line, champ);
	else if (cmd->type == 1)
		check_ld(cmd, line, champ);
	else if (cmd->type == 2)
		check_st(cmd, line, champ);
	else if (cmd->type == 3)
		check_add(cmd, line, champ);
	else if (cmd->type == 4)
		check_sub(cmd, line, champ);
	else if (cmd->type == 5)
		check_and(cmd, line, champ);
	else if (cmd->type == 6)
		check_or(cmd, line, champ);
	else if (cmd->type == 7)
		check_xor(cmd, line, champ);
	else
		check_command_part(cmd, line, champ);
}

void	command_search(char *line, t_parse *champ, t_labels *labels)
{
	int			i;
	t_command	*cmd;
	char		*buff;

	buff = NULL;
	line = skip_whitespace(line);
	if (line[0] != '\0')
	{
		cmd = command_init();
		i = 0;
		while (ft_strcmp((buff = cut_command(line)),
		g_op[i].name) != 0 && i < 16)
		{
			free(buff);
			i++;
		}
		free(buff);
		if (i == 16)
			error("Undefined command", champ->line_num);
		cmd->type = i;
		check_command(cmd, line, champ);
		if (labels != NULL)
			cmd->labels = labels;
	}
}
