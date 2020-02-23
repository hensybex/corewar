/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:30:25 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:15:11 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				sti(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	value;
	int32_t	addr_1;
	int32_t	addr_2;

	cursor->step += 2;
	r_id = get_byte(vm, cursor->pc, cursor->step);
	value = cursor->reg[r_id - 1];
	cursor->step += 1;
	addr_1 = get_op_arg(vm, cursor, 2, 1);
	addr_2 = get_op_arg(vm, cursor, 3, 1);
	byte_4_to_bytecode(vm->arena,
			(cursor->pc + ((addr_1 + addr_2) % IDX_MOD)), value, DIR_SIZE);
}
