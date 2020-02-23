/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:30:04 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:15:27 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				zjmp(t_vm *vm, t_cursor *cursor)
{
	int32_t addr;

	cursor->step += 1;
	addr = get_op_arg(vm, cursor, 1, 1);
	if (cursor->carry)
	{
		cursor->pc = calc_addr(cursor->pc + (addr % IDX_MOD));
		cursor->step = 0;
	}
}
