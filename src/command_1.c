/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:07:06 by smanhack          #+#    #+#             */
/*   Updated: 2020/01/31 14:09:10 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_fork(t_command *cmd, char *line, t_parse *champ)
{
	line += 4;
	line = is_dir(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in fork command", champ->line_num);
	add_command(cmd, champ);
}

void	check_lld(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_dirindir(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in lld command", champ->line_num);
	add_command(cmd, champ);
}

void	check_lldi(t_command *cmd, char *line, t_parse *champ)
{
	line += 4;
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_regdir(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in lldi command", champ->line_num);
	add_command(cmd, champ);
}

void	check_lfork(t_command *cmd, char *line, t_parse *champ)
{
	line += 5;
	line = is_dir(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in lfork command", champ->line_num);
	add_command(cmd, champ);
}

void	check_aff(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in aff command", champ->line_num);
	add_command(cmd, champ);
}
