/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:30:31 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:15:08 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				st(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	r_value;
	int32_t	addr;

	cursor->step += 2;
	r_id = get_byte(vm, cursor->pc, cursor->step);
	r_value = cursor->reg[r_id - 1];
	cursor->step += 1;
	if (cursor->args_types[1] == T_REG)
	{
		addr = get_byte(vm, cursor->pc, cursor->step);
		cursor->reg[addr - 1] = r_value;
		cursor->step += 1;
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
