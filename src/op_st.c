/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:30:31 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 10:30:32 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				op_st(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	r_value;
	int32_t	addr;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	r_value = cursor->reg[INDEX(r_id)];
	cursor->step += REG_LEN;
	if (cursor->args_types[1] == T_REG)
	{
		addr = get_byte(vm, cursor->pc, cursor->step);
		cursor->reg[INDEX(addr)] = r_value;
		cursor->step += REG_LEN;
	}
	else
	{
		addr = bytecode_to_4_byte(vm->arena,
							cursor->pc + cursor->step, IND_SIZE);
		byte_4_to_bytecode(vm->arena, cursor->pc + (addr % IDX_MOD),
							r_value, DIR_SIZE);
		cursor->step += IND_SIZE;
	}
}
