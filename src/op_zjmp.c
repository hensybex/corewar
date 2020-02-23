/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:30:04 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 10:30:07 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				op_zjmp(t_vm *vm, t_cursor *cursor)
{
	int32_t addr;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, 1);
	if (cursor->carry)
	{
		cursor->pc = calc_addr(cursor->pc + (addr % IDX_MOD));
		cursor->step = 0;
	}
}
