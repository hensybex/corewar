#include "../includes/corewar.h"
#include <stdio.h>

t_vm		*init_vm(void)
{
	t_vm *vm;

	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		error("Memory Allocation Error");
	vm->players_num = 0;
	//vm->last_alive = NULL;
	//vm->cursors = NULL;
	vm->cursors_num = 0;
	vm->lives_num = 0;
	vm->cycles = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->cycles_after_check = 0;
	vm->checks_num = 0;
	//vm->vs = NULL;
	vm->dump_cycle = -1;
	vm->dump_print_mode = 0;
	vm->show_cycle = -1;
	vm->show_print_mode = 0;
	//vm->display_aff = false;
	vm->log = 0;
	return (vm);
}

int			is_cor(char *av)
{
	if (av && ft_strstr(av, ".cor") && (ft_strlen(av) >= 4))
		return (1);
	return (0);
}

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
	size = read(fd, buff, len);
	if (size == -1)
		error("Error reading file");
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		error("Invalid file");
	return (buff);
}

t_player	*init_player(int id)
{
	t_player *player;

	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		error("Memory Allocation Error");
	player->id = id;
	player->name = NULL;
	player->comment = NULL;
	player->code_size = 0;
	player->code = NULL;
	player->last_live = 0;
	player->current_lives_num = 0;
	player->previous_lives_num = 0;
	player->next = NULL;
	return (player);
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

void	update_players_ids(t_player *list)
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
	update_players_ids(list);
	while (id <= vm->players_num)
	{
		if (!(vm->players[id - 1] = find_player(list, id)))
			error("Что-то пошло не так в set_players");
		id++;
	}
	vm->last_alive = vm->players[vm->players_num - 1];
}

void		parse_champion_filename(int *ac, char ***av, t_vm *vm, t_player **list)
{
	int32_t		id;

	id = 0;
	// обработка флага n

	if (is_cor(**av))
	{
		//printf("%s %d\n", (**av), *ac);
		add_player(list, parse_champion(**av, id));
		vm->players_num++;
		(*ac)--;
		(*av)++;
	}
}

void		parse_corewar_args(int ac, char **av, t_vm *vm)
{
	t_player *list;

	list = NULL;
	// считывание флагов
	while (ac >= 1)
	{
		if (is_cor(*av))
		{
			parse_champion_filename(&ac, &av, vm, &list);
		}
	}
	set_players(vm, list);
}

void		print_info_for_player(t_vm *vm)
{
	t_player	*player;
	int32_t		i;
	int32_t		j;

	j = 0;
	printf("%d\n", vm->players_num);
	while (j < vm->players_num)
	{
		player = vm->players[j];
		printf("Меня зовут: %s\n", player->name);
		printf("Мой комментарий: %s\n", player->comment);
		printf("Мой размер: %d\n", player->code_size);
		i = 0;
		while (i < player->code_size)
		{
			if (i % 16 == 0)
				printf("\n");
			else if (i % 2 == 0)
				printf(" ");
			printf("%02x", player->code[i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

void		print_arena(t_vm *vm)
{
	ssize_t i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % (MEM_SIZE / 32) == 0)
			printf("\n");
		else if (i % 2 == 0)
			printf (" ");
		printf("%01x", vm->arena[i]);
		i++;
	}
	printf("\n");
}

void		entry_arena(t_vm *vm)
{
	int			i;
	uint32_t	pc;

	i = 0;
	pc = 0;
	while (i < vm->players_num)
	{
		ft_memcpy(&(vm->arena[pc]), vm->players[i]->code, vm->players[i]->code_size);
		pc += MEM_SIZE / vm->players_num;
		i++;
	}
}

void		print_cursors(t_vm *vm)
{
	t_cursor	*buff;
	int			i;

	i = 0;
	buff = vm->cursors;
	while (buff != NULL)
	{
		buff = buff->next;
		i++;
	}
}

int			main(int ac, char **av)
{
	t_vm	*vm;

	vm = NULL;
	if (ac >= 2)
	{
		ac--;
		av++;
		vm = init_vm();
		parse_corewar_args(ac, av, vm);
		entry_arena(vm);
		init_cursors(vm);
		print_cursors(vm);
		//WAR!!!!
		//print_info_for_player(vm);
		//print_arena(vm);
	}
	return (0);
}