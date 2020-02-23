/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:14:28 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/01 20:26:01 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_label_symbol(char symbol, int line_num)
{
	int	i;
	int	fl;

	fl = 0;
	i = 0;
	while (i < 37 && fl == 0)
	{
		if (symbol == LABEL_CHARS[i])
			fl = 1;
		i++;
	}
	if (fl == 0)
		error("Undefined label symbol", line_num);
}

void	check_label_symbols(char *line, int line_num)
{
	int	i;

	i = 0;
	while (line[i] == '	' || line[i] == ' ')
		i++;
	while (line[i] != LABEL_CHAR)
	{
		check_label_symbol(line[i], line_num);
		i++;
	}
}

void	check_exception(char *line, int line_num)
{
	int	i;

	i = 0;
	while (!ft_strstr(line, g_op[i].name) && i < 16)
		i++;
	if (i == 16)
		error("Undefined label symbol", line_num);
}

int		check_num(char *line)
{
	if (*line != '-' && ft_strlen(line) == ft_strlen("9223372036854775807"))
	{
		if (ft_strcmp(line, "9223372036854775807") > 0)
			return (0);
	}
	else if (*line != '-' && ft_strlen(line) > ft_strlen("9223372036854775807"))
	{
		return (0);
	}
	else if (ft_strlen(line) == ft_strlen("-9223372036854775808"))
	{
		if (ft_strcmp(line, "-9223372036854775808") > 0)
			return (0);
	}
	else if (ft_strlen(line) > ft_strlen("-9223372036854775808"))
		return (0);
	return (1);
}
