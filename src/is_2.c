/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:23:36 by smanhack          #+#    #+#             */
/*   Updated: 2020/01/31 21:35:47 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*is_dir(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] != DIRECT_CHAR)
		error("Invalid argument [T_DIR]", champ->line_num);
	tmp_line++;
	if (tmp_line[0] == LABEL_CHAR)
		check_label_validity(tmp_line, champ);
	else if (check_num(tmp_line) != 1)
		error("Invalid argument [T_DIR]", champ->line_num);
	tmp_line--;
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}

char	*is_indir(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] == LABEL_CHAR)
	{
		check_label_validity(tmp_line, champ);
		tmp_line--;
	}
	else if (check_num(tmp_line) != 1)
		error("Invalid argument [T_IND]", champ->line_num);
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}

char	*is_reg(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] != 'r')
		error("Letter r missing in [T_REG]", champ->line_num);
	tmp_line++;
	if (check_num(tmp_line) != 1)
		error("Invalid argument [T_REG]", champ->line_num);
	if (ft_atoi(tmp_line) > REG_NUMBER)
		error("Reg number beyound limit!", champ->line_num);
	else if (ft_atoi(tmp_line) <= 0)
		error("Min reg number is '1'", champ->line_num);
	tmp_line--;
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}

char	*is_regindir(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] != 'r')
	{
		if (tmp_line[0] == LABEL_CHAR)
			check_label_validity(tmp_line, champ);
		else if (check_num(tmp_line) != 1)
			error("Invalid aargument [T_REG/T_IND]", champ->line_num);
	}
	else
	{
		tmp_line++;
		if (ft_atoi(tmp_line) > REG_NUMBER)
			error("Reg number beyound limit", champ->line_num);
		if (check_num(tmp_line) != 1)
			error("Invalid argument [T_REG/T_IND]", champ->line_num);
		tmp_line--;
	}
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}
