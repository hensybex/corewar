/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:29:19 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:40:08 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include "../includes/corewar_op.h"

static int	is_register(t_vm *vm, int32_t pc, int32_t step)
{
	int8_t	r_id;

	r_id = get_byte(vm, pc, step);
	return (int)(r_id >= 1 && r_id <= REG_NUMBER);
}

uint32_t	step_size(uint8_t arg_type, t_op *op)
{
	if (arg_type & T_REG)
		return (1);
	else if (arg_type & T_DIR)
		return (op->t_dir_size);
	else if (arg_type & T_IND)
		return (IND_SIZE);
	return (0);
}

uint32_t	calc_step(t_cursor *cursor, t_op *op)
{
	int32_t		i;
	uint32_t	step;

	i = 0;
	step = 0;
	step += 1 + (op->args_types_code ? 1 : 0);
	while (i < g_op[cursor->op_code - 1].args_num)
	{
		step += step_size(cursor->args_types[i], op);
		i++;
	}
	return (step);
}

int8_t		get_byte(t_vm *vm, int32_t pc, int32_t step)
{
	return (vm->arena[calc_addr(pc + step)]);
}

int			are_args_valid(t_cursor *cursor, t_vm *vm, t_op *op)
{
	int32_t		i;
	uint32_t	step;

	i = 0;
	step = (1 + (op->args_types_code ? 1 : 0));
	while (i < op->args_num)
	{
		if ((cursor->args_types[i] == T_REG)
			&& !is_register(vm, cursor->pc, step))
			return (0);
		step += step_size(cursor->args_types[i], op);
		i++;
	}
	return (1);
}
