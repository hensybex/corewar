/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:02:02 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 11:13:24 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_parse		*init_champ(t_parse *champ)
{
	champ = (t_parse *)malloc(sizeof(t_parse));
	champ->name = NULL;
	champ->comment = NULL;
	champ->list_cmd = NULL;
	champ->labels = NULL;
	champ->line_num = 1;
	champ->size = 0;
	champ->exec_code = NULL;
	return (champ);
}

char		*cor_file(char *filename)
{
	char *str;
	char *buff;

	str = NULL;
	if (ft_strstr(filename, ".s") != NULL && filename[ft_strlen(filename) - 1]
	&& filename[ft_strlen(filename) - 2]
	&& filename[ft_strlen(filename) - 1] == 's'
	&& filename[ft_strlen(filename) - 2] == '.')
	{
		str = ft_strndup(filename, ft_strlen(filename) - 2);
		buff = str;
		str = ft_strjoin(str, ".cor");
		free(buff);
	}
	else
		error("Файл не корректный!", -1);
	return (str);
}

void		check_file_extension(int ac, char *line)
{
	int	i;

	if (ac != 2)
		error("Too much arguments in argv", 0);
	i = 0;
	while (line[i])
		i++;
	if (line[i - 1] != 's' || line[i] != '\0' || line[i - 2] != '.')
		error("Wrong file extension in argv", 0);
}

int			main(int ac, char **av)
{
	t_parse *champ;
	int		fd;
	char	*filename;

	champ = NULL;
	init_gc();
	champ = init_champ(champ);
	check_file_extension(ac, av[1]);
	parse(av[1], champ);
	label_conversion(champ);
	to_asm_code(champ);
	filename = cor_file(av[1]);
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		error("Файл не создался!\n", -1);
	write_bytecode_file(fd, champ);
	memory_clearing(champ);
	ft_printf("Writing output program to %s\n", filename);
	free(filename);
	del_gc();
	return (0);
}
