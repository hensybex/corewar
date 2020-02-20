#include "../includes/corewar.h"

static void	free_cursors(t_cursor **list)
{
	t_cursor	*current;
	t_cursor	*delete;

	current = *list;
	while (current)
	{
		delete = current;
		current = current->next;
		ft_memdel((void **)&delete);
	}
	*list = NULL;
}

void		free_vm(t_vm **vm)
{
	free_players((*vm)->players, (*vm)->players_num);
	free_cursors(&((*vm)->cursors));
	ft_memdel((void **)vm);
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
		introduction(vm->players, vm->players_num);
		battle(vm);
		print_winner(vm);
		free_vm(&vm);
	}
	return (0);
}
