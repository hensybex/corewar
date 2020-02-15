#include "../includes/corewar.h"


void		print_intro(t_player **players, int32_t players_num)
{
	int32_t id;

	id = 1;
	printf("Introducing contestants...\n");
	while (id <= players_num)
	{
		printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
												id,
												players[INDEX(id)]->code_size,
												players[INDEX(id)]->name,
												players[INDEX(id)]->comment);
		id++;
	}
}

void	print_last_alive(t_vm *vm)
{
	printf("Contestant %d, \"%s\", has won !\n",
													FT_ABS(vm->last_alive->id),
													vm->last_alive->name);
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
		//print_cursors(vm);
		print_intro(vm->players, vm->players_num);
		//print_arena_full(vm);
		battle(vm);
		print_last_alive(vm);
		//print_info_for_player(vm);
		//print_arena_full(vm);
	}
	return (0);
}