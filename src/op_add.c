/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:29:35 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 10:31:28 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_op.h"

void				op_add(t_vm *vm, t_cursor *cursor)
{
	int32_t	r1_id;
	int32_t	r2_id;
	int32_t	r3_id;
	int32_t	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r1_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	r2_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	value = cursor->reg[r1_id - 1] + cursor->reg[r2_id - 1];
	cursor->carry = (int)(!value);
	r3_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[r3_id - 1] = value;
	cursor->step += REG_LEN;
}
