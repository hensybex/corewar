#include "../includes/corewar.h"

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
		//WAR!!!!
		print_info_for_player(vm);
		//print_arena_full(vm);
	}
	return (0);
}