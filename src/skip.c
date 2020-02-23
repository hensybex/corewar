/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 14:27:53 by smanhack          #+#    #+#             */
/*   Updated: 2020/01/31 14:30:19 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_command	*command_init(void)
{
	t_command *cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	cmd->type = -1;
	cmd->arg[0] = 0;
	cmd->arg[1] = 0;
	cmd->arg[2] = 0;
	cmd->next = NULL;
	cmd->labels = NULL;
	cmd->arg_num = 0;
	cmd->label_size = 0;
	return (cmd);
}

int			is_whitespace(int c)
{
	return (c == '\t' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}

char		*skip_whitespace(char *line)
{
	while (is_whitespace(*line))
		line++;
	return (line);
}

char		*skip_command(char *line)
{
	while (!is_whitespace(*line))
		line++;
	return (line);
}

char		*cut_command(char *line)
{
	char	*command;
	int		i;
	int		j;

	i = 0;
	while (line[i] != '%' && line[i] != '\t' && line[i]
	!= '\v' && line[i] != '\f' && line[i] != '\r' && line[i]
	!= ' ' && line[i] != '\0' && line[i] != SEPARATOR_CHAR && line[i] != '-')
		i++;
	j = 0;
	command = (char *)malloc(sizeof(char) * i);
	while (j < i)
	{
		command[j] = line[j];
		j++;
	}
	command[j] = '\0';
	return (command);
}
