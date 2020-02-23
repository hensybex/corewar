/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:18:05 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 11:18:46 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_label_validity(char *line, t_parse *champ)
{
	t_labels	*buff;
	int			fl;

	fl = 0;
	buff = champ->labels;
	line++;
	while (buff != NULL && fl == 0)
	{
		if (ft_strcmp(buff->label, line) == 0)
			fl = 1;
		buff = buff->next;
	}
	if (fl == 0)
		error("Usage of undeclared label", champ->line_num);
}

void	is_any_part(char *tmp_line, t_parse *champ, char *line)
{
	tmp_line++;
	if (line[0] == 'r' && ft_atoi(tmp_line) > REG_NUMBER)
		error("Reg number beyound limit", champ->line_num);
	else
	{
		if (tmp_line[0] == LABEL_CHAR)
			check_label_validity(tmp_line, champ);
		else if (check_num(tmp_line) != 1)
			error("Invalid argument [T_REG/T_DIR/T_IND]", champ->line_num);
	}
	tmp_line--;
}

char	*is_any(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] == DIRECT_CHAR || tmp_line[0] == 'r')
		is_any_part(tmp_line, champ, line);
	else
	{
		if (tmp_line[0] == LABEL_CHAR)
			check_label_validity(tmp_line, champ);
		else if (check_num(tmp_line) != 1)
			error("Invalid aargument [T_REG/T_DIR/T_IND]", champ->line_num);
	}
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}

char	*find_separator(char *line, int line_num)
{
	line = skip_whitespace(line);
	if (line[0] != SEPARATOR_CHAR)
		error("Separator char missing or invalid", line_num);
	line++;
	return (line);
}

void	check_live(t_command *cmd, char *line, t_parse *champ)
{
	line += 4;
	line = is_dir(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in live command", champ->line_num);
	add_command(cmd, champ);
}
