/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:25:43 by smanhack          #+#    #+#             */
/*   Updated: 2020/01/31 21:35:11 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*is_dirindir(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] != DIRECT_CHAR)
	{
		if (tmp_line[0] == LABEL_CHAR)
			check_label_validity(tmp_line, champ);
		else if (check_num(tmp_line) != 1)
			error("Invalid argument [T_IND/T_DIR]", champ->line_num);
	}
	else
	{
		tmp_line++;
		if (tmp_line[0] == LABEL_CHAR)
			check_label_validity(tmp_line, champ);
		else if (check_num(tmp_line) != 1)
			error("Invalid argument [T_IND/T_DIR]", champ->line_num);
		tmp_line--;
	}
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}

char	*is_regdir(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] == 'r' || tmp_line[0] == DIRECT_CHAR)
	{
		tmp_line++;
		if (line[0] == 'r' && ft_atoi(tmp_line) > REG_NUMBER)
			error("Reg number beyound limit", champ->line_num);
		else
		{
			if (tmp_line[0] == LABEL_CHAR)
				check_label_validity(tmp_line, champ);
			else if (check_num(tmp_line) != 1)
				error("Invalid argument [T_REG/T_DIR]", champ->line_num);
		}
		tmp_line--;
	}
	else
		error("Invalid argument [T_REG/T_DIR]", champ->line_num);
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}

void	add_command(t_command *cmd, t_parse *champ)
{
	t_command *buff;

	if (champ->list_cmd == NULL)
		champ->list_cmd = cmd;
	else
	{
		buff = champ->list_cmd;
		while (buff->next != NULL)
			buff = buff->next;
		buff->next = cmd;
	}
}

void	add_cmd_arg(char *line, t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->arg[i] != NULL)
		i++;
	cmd->arg[i] = ft_strdup(line);
	cmd->arg_num++;
}

char	*cut_arg(char *line)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (line[i] != ' ' && line[i] != '	'
	&& line[i] != '\0' && line[i] != SEPARATOR_CHAR)
		i++;
	new_line = (char *)gmalloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		new_line[j] = line[j];
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}
