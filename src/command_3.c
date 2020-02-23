/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:16:06 by smanhack          #+#    #+#             */
/*   Updated: 2020/01/31 21:34:03 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_ld(t_command *cmd, char *line, t_parse *champ)
{
	line += 2;
	line = is_dirindir(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in ld command", champ->line_num);
	add_command(cmd, champ);
}

void	check_st(t_command *cmd, char *line, t_parse *champ)
{
	line += 2;
	line = is_reg(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_regindir(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in st command", champ->line_num);
	add_command(cmd, champ);
}

void	check_add(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_reg(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in add command", champ->line_num);
	add_command(cmd, champ);
}

void	check_sub(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_reg(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in sub command", champ->line_num);
	add_command(cmd, champ);
}

void	check_and(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in and command", champ->line_num);
	add_command(cmd, champ);
}
