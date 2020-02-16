#include "../includes/corewar.h"


void		print_intro(t_player **p, int32_t num)
{
	int32_t i;

	i = 0;
	printf("Introducing contestants...\n");
	while (i < num)
	{
		printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		i + 1, p[i]->code_size, p[i]->name, p[i]->comment);
		i++;
	}
}

void	print_last(t_vm *vm)
{
	printf("Contestant %d, \"%s\", has won !\n",
	modul(vm->last_alive->id), vm->last_alive->name);
}

static void	free_players(t_player **players, int32_t players_num)
{
	int32_t i;

	i = 0;
	while (i < players_num)
	{
		ft_strdel(&(players[i]->name));
		ft_strdel(&(players[i]->comment));
		ft_memdel((void **)&(players[i]->code));
		ft_memdel((void **)&players[i]);
		i++;
	}
}

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
		print_intro(vm->players, vm->players_num);
		battle(vm);
		print_last(vm);
		free_vm(&vm);
	}
	return (0);
}