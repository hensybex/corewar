#include "../includes/corewar.h"

void	run_cycles(t_vm *vm)
{
	t_cursor	*cursor;

	vm->cycles++;
	vm->cycles_after_check++;
	cursor = vm->cursors;
	while (cursor != NULL)
	{
		run_operation(vm, cursor);
		cursor = cursor->next;
	}
}

int32_t		calc_addr(int32_t addr)
{
	addr %= MEM_SIZE;
	if (addr < 0)
		addr += MEM_SIZE;
	return (addr);
}

void	update_op_code(t_vm *vm, t_cursor *cursor)
{
	cursor->op_code = vm->arena[cursor->pc];
	if (vm->arena[cursor->pc] >= 1 && vm->arena[cursor->pc] <= 16)
		cursor->cycles_to_exec = g_op[cursor->op_code - 1].cycles;
}

void	move_cursor(t_cursor *cursor)
{
	cursor->pc += cursor->step;
	cursor->pc = calc_addr(cursor->pc);
	cursor->step = 0;
	ft_bzero(cursor->args_types, 3);
}

void	run_operation(t_vm *vm, t_cursor *cursor)
{
	t_op	*op;

	if (cursor->cycles_to_exec == 0)
		update_op_code(vm, cursor);
	if (cursor->cycles_to_exec > 0)
		cursor->cycles_to_exec--;
	if (cursor->cycles_to_exec == 0)
	{
		op = NULL;
		if (cursor->op_code >= 1 && cursor->op_code <= 16)
			op = &g_op[cursor->op_code - 1];
		if (op != NULL)
		{
			parse_types_code(vm, cursor, op);
			if (are_args_types_valid(cursor, op) && are_args_valid(cursor, vm, op))
				op->func(vm, cursor);
			else
				cursor->step +=  calc_step(cursor, op);
		}
		else
			cursor->step = OP_CODE_LEN;
		move_cursor(cursor);
	}
}

static int	is_dead(t_vm *vm, t_cursor *cursor)
{
	return (vm->cycles_to_die <= 0
			|| vm->cycles - cursor->last_live >= vm->cycles_to_die);
}

static void		delete_dead_cursors(t_vm *vm)
{
	t_cursor	*previous;
	t_cursor	*current;
	t_cursor	*delete;

	previous = NULL;
	current = vm->cursors;
	while (current)
		if (is_dead(vm, (delete = current)) && vm->cursors_num--)
		{
			current = current->next;
			if (vm->cursors == delete)
				vm->cursors = current;
			if (previous)
				previous->next = current;
			ft_memdel((void **)&delete);
		}
		else
		{
			previous = current;
			current = current->next;
		}
}

void	update_lives_num(t_vm *vm)
{
	int32_t		i;

	i = 0;
	while (i < vm->players_num)
	{
		vm->players[i]->previous_lives_num = vm->players[i]->current_lives_num;
		vm->players[i]->current_lives_num = 0;
		i++;
	}
	vm->lives_num = 0;
}

void	cycles_to_die_handler(t_vm *vm)
{
	vm->checks_num++;
	delete_dead_cursors(vm);
	if (vm->checks_num == MAX_CHECKS || vm->lives_num >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->checks_num = 0;
	}
	update_lives_num(vm);
	vm->cycles_after_check = 0;
}

void		print_arena(uint8_t *arena, int print_mode)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		printf("%.4p : ", i);
		j = 0;
		while (j < print_mode)
		{
			printf("%.2x ", arena[i + j]);//прикрутить принтф
			j++;
		}
		printf("\n");
		i += print_mode;
	}
}

void	battle(t_vm *vm)
{
	while (vm->cursors_num != 0)
	{
		if (vm->dump_cycle == vm->cycles)
		{
			print_arena(vm->arena, vm->dump_print_mode);
			exit(0);
		}
		run_cycles(vm);
		if (vm->cycles_to_die == vm->cycles_after_check || vm->cycles_to_die <= 0)
			cycles_to_die_handler(vm);
	}
}