/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizing_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:02:59 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 11:20:14 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

size_t		sizing(t_command *buff)
{
	size_t	size;
	size_t	i;

	size = 1;
	if (g_op[buff->type].args_types_code)
		size++;
	i = 0;
	while (i < 3)
	{
		if (buff->arg[i])
		{
			if (*(buff->arg[i]) == 'r')
				size++;
			else if (*(buff->arg[i]) == DIRECT_CHAR)
				size += g_op[buff->type].t_dir_size;
			else
				size += 2;
		}
		i++;
	}
	return (size);
}

size_t		sizing_line_down(t_command *buff, int location)
{
	size_t	size;
	size_t	i;

	(void)location;
	size = 1;
	if (g_op[buff->type].args_types_code)
		size++;
	i = 0;
	while (i < 3)
	{
		if (buff->arg[i])
		{
			if (*(buff->arg[i]) == 'r')
				size++;
			else if (*(buff->arg[i]) == DIRECT_CHAR)
				size += g_op[buff->type].t_dir_size;
			else
				size += 2;
		}
		i++;
	}
	return (size);
}

int			label_in_arg(t_command *command)
{
	int	i;

	i = 0;
	while (i < command->arg_num)
	{
		if ((command->arg[i][1] == LABEL_CHAR
		&& command->arg[i][0] == DIRECT_CHAR)
		|| command->arg[i][0] == LABEL_CHAR)
			return (i);
		i++;
	}
	return (-1);
}

char		*cut_first_symbol(char *line)
{
	unsigned long		i;
	char				*new_line;

	i = 0;
	new_line = (char *)malloc(sizeof(char) * ft_strlen(line));
	while (i < ft_strlen(line) - 1)
	{
		new_line[i] = line[i + 1];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char		*cut_first_two_symbols(char *line)
{
	unsigned long		i;
	char				*new_line;

	i = 0;
	new_line = (char *)malloc(sizeof(char) * ft_strlen(line));
	while (i < ft_strlen(line) - 2)
	{
		new_line[i] = line[i + 2];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}
