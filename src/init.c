#include "../includes/corewar.h"

t_vm		*init_vm(void)
{
	t_vm *vm;

	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		error("Memory Allocation Error");
	vm->players_num = 0;
	vm->last_alive = NULL;
	vm->cursors = NULL;
	vm->cursors_num = 0;
	vm->lives_num = 0;
	vm->cycles = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->cycles_after_check = 0;
	vm->checks_num = 0;
	vm->dump_cycle = -1;
	vm->dump_print_mode = 0;
	vm->show_cycle = -1;
	vm->show_print_mode = 0;
	vm->log = 0;
	return (vm);
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
