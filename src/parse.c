#include "../includes/corewar.h"

void		add_player(t_player **list, t_player *new)
{
	t_player *current;

	if (list && new)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
			*list = new;
	}
}

void	*mem_cpy(void *dst, const void *src, size_t n)
{
	char			*ptr1;
	char			*ptr2;
	unsigned int	i;

	i = 0;
	if (dst == src)
		return (dst);
	ptr1 = (char*)dst;
	ptr2 = (char*)src;
	while (i < n)
	{
		ptr1[n - i - 1] = ptr2[i];
		i++;
	}
	return (dst);
}

int32_t			parse_4_byte(int fd)
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

uint8_t	*parse_exec_code(int fd, size_t len)
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

t_player		*parse_champion(char *str, int id)
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
	if ((player->code_size = parse_4_byte(fd)) < 0 || player->code_size > CHAMP_MAX_SIZE)
		error("Invalid code size");
	player->comment = parse_str(fd, COMMENT_LENGTH);
	if (parse_4_byte(fd) != 0)
		error("No separator - NULL");
	player->code = parse_exec_code(fd, (size_t)player->code_size);
	return (player);
}

t_player	*find_player(t_player *list, int32_t id)
{
	t_player *player;

	player = NULL;
	if (id >= 1 && id <= MAX_PLAYERS)
	{
		player = list;
		while (player)
		{
			if (player->id == id)
				return (player);
			player = player->next;
		}
	}
	return (player);
}

void	update_players_id(t_player *list)
{
	t_player	*player;
	int32_t		id;

	id = 1;
	player = list;
	while (player)
	{
		if (player->id == 0)
		{
			while (find_player(list, id))
				id++;
			player->id = id;
		}
		player = player->next;
	}
}

void	set_players(t_vm *vm, t_player *list)
{
	int32_t id;

	id = 1;
	update_players_id(list);
	while (id <= vm->players_num)
	{
		if (!(vm->players[id - 1] = find_player(list, id)))
			error("Что-то пошло не так в set_players");
		id++;
	}
	vm->last_alive = vm->players[vm->players_num - 1];
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

void	parse_aff(int *ac, char ***av, t_vm *vm)
{
	vm->display_aff = 1; // поменять на 1
	(*ac)--;
	(*av)++;
}

void	parse_dump(int *ac, char ***av, t_vm *vm)
{
	if (!vm->dump_print_mode && *ac >= 2 && ft_max_min_int(*(*av + 1)))
	{
		if ((vm->dump_cycle = ft_atoi(*(*av + 1))) < 0)
			vm->dump_cycle = -1;
		if (!ft_strcmp(**av, "-d"))
			vm->dump_print_mode = 64;
		else
			vm->dump_print_mode = 32;
		(*ac) -= 2;
		(*av) += 2;
	}
	else
		error("Not valid -dump/-d arg");
}

void		parse_corewar_args(int ac, char **av, t_vm *vm)
{
	t_player *list;

	list = NULL;

	while (ac >= 1)
	{
		if (!ft_strcmp(*av, "-dump") || !ft_strcmp(*av, "-d"))
			parse_dump(&ac, &av, vm);
		else if (!ft_strcmp(*av, "-n") || is_cor(*av))
			parse_file(&ac, &av, vm, &list);
		else if (!ft_strcmp(*av, "-a"))
			parse_aff(&ac, &av, vm);
		else
			error("Error arg");
	}
	if (vm->players_num < 1 || vm->players_num > MAX_PLAYERS)
		error("Error arg");
	set_players(vm, list);
}
