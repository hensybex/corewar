/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:30:40 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 10:30:41 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				op_lldi(t_vm *vm, t_cursor *cursor)
{
	int32_t	addr_1;
	int32_t	addr_2;
	int32_t	r_id;

	cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
	addr_1 = get_op_arg(vm, cursor, 1, 1);
	addr_2 = get_op_arg(vm, cursor, 2, 1);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r_id)] = bytecode_to_4_byte(vm->arena,
			cursor->pc + (addr_1 + addr_2), DIR_SIZE);
	cursor->step += REG_LEN;
}
