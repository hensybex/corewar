/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:09:27 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/01 17:35:28 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	error(char *error, int line_num)
{
	ft_putstr(error);
	if (line_num != -1)
	{
		ft_putstr(" in line");
		ft_putnbr(line_num);
		ft_putchar('\n');
	}
	exit(1);
}

void	check_last_symbols_part(char *line)
{
	int		i;
	int		counter;

	i = 0;
	while (line[i])
		i++;
	i--;
	counter = 0;
	while (line[i] == '\n' || line[i] == '\t' || line[i] == ' ')
	{
		counter++;
		i--;
	}
	free(line);
	if (counter == 0)
		error("Wrong amount of empty lines at the end of file", -1);
}

char	*cut_label(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] != LABEL_CHAR)
		i++;
	new_str = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (str[i] != LABEL_CHAR)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int		is_label(char *line)
{
	int	i;

	line = skip_whitespace(line);
	i = 0;
	while (line[i] != LABEL_CHAR && line[i] && line[i] != ' ')
		i++;
	if (line[i - 1] == DIRECT_CHAR && line[i] == LABEL_CHAR)
		return (0);
	else if (line[i] == LABEL_CHAR && line[i - 1]
	!= SEPARATOR_CHAR && line[i - 1] != ' ' && line[i - 1] != '\t')
		return (1);
	else
		return (0);
}
