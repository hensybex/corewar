/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:12:37 by smanhack          #+#    #+#             */
/*   Updated: 2020/01/31 14:13:23 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_or(t_command *cmd, char *line, t_parse *champ)
{
	line += 2;
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in or command", champ->line_num);
	add_command(cmd, champ);
}

void	check_xor(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in xor command", champ->line_num);
	add_command(cmd, champ);
}

void	check_zjmp(t_command *cmd, char *line, t_parse *champ)
{
	line += 4;
	line = is_dir(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in zjmp command", champ->line_num);
	add_command(cmd, champ);
}

void	check_ldi(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_regdir(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in ldi command", champ->line_num);
	add_command(cmd, champ);
}

void	check_sti(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_reg(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_regdir(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in sti command", champ->line_num);
	add_command(cmd, champ);
}
