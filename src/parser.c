/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 03:20:48 by medesmon          #+#    #+#             */
/*   Updated: 2020/02/23 11:15:33 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_last_symbols(char *file, int fd)
{
	char	*line;
	int		i;
	char	buff[2];
	int		fl;

	(void)file;
	fl = 0;
	line = NULL;
	while ((i = read(fd, buff, 1)) > 0)
	{
		if (buff[0] == '#')
			fl = 1;
		if (buff[0] == '\n')
			fl = 0;
		if (fl == 0)
		{
			if (line == NULL)
				line = ft_strdup(buff);
			else
				line = ft_strdeljoin(line, buff);
		}
	}
	check_last_symbols_part(line);
}

void	print_labels(t_parse *champ)
{
	t_labels	*buff;

	buff = champ->labels;
	while (buff)
	{
		ft_putendl(buff->label);
		buff = buff->next;
	}
}

void	parse(char *file, t_parse *champ)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		error("Cannot open file", -1);
	check_last_symbols(file, fd);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		label_search(line, champ, fd);
		free(line);
		champ->line_num++;
	}
	champ->line_num = 1;
	fd = open(file, O_RDWR | O_APPEND);
	while (get_next_line(fd, &line) > 0)
	{
		line_processing(line, champ, fd);
		free(line);
		champ->line_num++;
	}
	if (champ->name == NULL || champ->comment == NULL)
		error("Undefined parsing error", champ->line_num);
	close(fd);
}
