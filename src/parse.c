/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:29:58 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:31:31 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int32_t		parse_4_byte(int fd)
{
	ssize_t		size;
	uint8_t		buff[4];
	int32_t		res;

	res = 0;
	size = read(fd, &buff, 4);
	if (size == -1)
		error("Error reading file");
	if (size < 4)
		error("Invalid file");
	mem_cpy(&res, buff, 4);
	return (res);
}

char		*parse_str(int fd, size_t len)
{
	ssize_t	size;
	char	*buff;

	if (!(buff = ft_strnew(len)))
		error("Memory Allocation Error");
	size = read(fd, buff, len);
	if (size == -1)
		error("Error reading file");
	if (size < (ssize_t)len)
		error("Invalid file");
	return (buff);
}

uint8_t		*parse_exec_code(int fd, size_t len)
{
	ssize_t	size;
	uint8_t	*buff;
	uint8_t	byte;

	if (!(buff = malloc(len)))
		error("Memory Allocation Error");
	if ((size = read(fd, buff, len)) == -1)
		error("Error reading file");
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		error("Invalid file");
	return (buff);
}

t_player	*parse_champion(char *str, int id)
{
	t_player	*player;
	int			fd;

	player = init_player(id);
	if ((fd = open(str, O_RDONLY)) < 0)
		error("Error opening file");
	if (parse_4_byte(fd) != COREWAR_EXEC_MAGIC)
		error("Invalid magic header");
	player->name = parse_str(fd, PROG_NAME_LENGTH);
	if (parse_4_byte(fd) != 0)
		error("No separator - NULL");
	if ((player->code_size = parse_4_byte(fd)) < 0
	|| player->code_size > CHAMP_MAX_SIZE)
		error("Invalid code size");
	player->comment = parse_str(fd, COMMENT_LENGTH);
	if (parse_4_byte(fd) != 0)
		error("No separator - NULL");
	player->code = parse_exec_code(fd, (size_t)player->code_size);
	return (player);
}

void		parse_file(int *ac, char ***av, t_vm *vm, t_player **list)
{
	int32_t		id;

	id = 0;
	if (*ac >= 3 && !ft_strcmp(**av, "-n"))
	{
		if (!ft_max_min_int(*(*av + 1))
			|| (id = ft_atoi(*(*av + 1))) < 1
			|| id > MAX_PLAYERS
			|| find_player(*list, id)
			|| !is_cor(*(*av + 2)))
			error("Not valid -n arg");
		add_player(list, parse_champion(*(*av + 2), id));
		vm->players_num++;
		(*ac) -= 3;
		(*av) += 3;
	}
	else if (is_cor(**av))
	{
		add_player(list, parse_champion(**av, id));
		vm->players_num++;
		(*ac)--;
		(*av)++;
	}
}
