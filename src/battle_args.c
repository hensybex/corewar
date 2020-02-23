/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:26:41 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:26:50 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/corewar_op.h"

void		update_lives_num(t_vm *vm)
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

static void	set_arg_type(int8_t arg_type, int8_t i, t_cursor *cursor)
{
	cursor->args_types[i] = g_arg_code[arg_type - 1];
}

void		parse_types_code(t_vm *vm, t_cursor *cursor, t_op *op)
{
	int8_t args_types_code;

	if (op->args_types_code)
	{
		args_types_code = get_byte(vm, cursor->pc, 1);
		if (op->args_num >= 1)
			set_arg_type((int8_t)((args_types_code & 192) >> 6), 0, cursor);
		if (op->args_num >= 2)
			set_arg_type((int8_t)((args_types_code & 48) >> 4), 1, cursor);
		if (op->args_num >= 3)
			set_arg_type((int8_t)((args_types_code & 12) >> 2), 2, cursor);
	}
	else
		cursor->args_types[0] = op->args_types[0];
}

int			are_args_types_valid(t_cursor *cursor, t_op *op)
{
	int32_t i;

	i = 0;
	while (i < op->args_num)
	{
		if (!(cursor->args_types[i] & op->args_types[i]))
			return (0);
		i++;
	}
	return (1);
}
