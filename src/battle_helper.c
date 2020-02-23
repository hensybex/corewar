/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:24:54 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:25:09 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		run_cycles(t_vm *vm)
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

void		update_op_code(t_vm *vm, t_cursor *cursor)
{
	cursor->op_code = vm->arena[cursor->pc];
	if (vm->arena[cursor->pc] >= 1 && vm->arena[cursor->pc] <= 16)
		cursor->cycles_to_exec = g_op[cursor->op_code - 1].cycles;
}

void		move_cursor(t_cursor *cursor)
{
	cursor->pc += cursor->step;
	cursor->pc = calc_addr(cursor->pc);
	cursor->step = 0;
	ft_bzero(cursor->args_types, 3);
}

void		run_operation(t_vm *vm, t_cursor *cursor)
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
			if (are_args_types_valid(cursor, op)
				&& are_args_valid(cursor, vm, op))
				op->func(vm, cursor);
			else
				cursor->step += calc_step(cursor, op);
		}
		else
			cursor->step = 1;
		move_cursor(cursor);
	}
}
