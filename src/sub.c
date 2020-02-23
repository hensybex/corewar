/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:30:20 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:15:14 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				sub(t_vm *vm, t_cursor *cursor)
{
	int32_t	r1_id;
	int32_t	r2_id;
	int32_t	r3_id;
	int32_t	value;

	cursor->step += 2;
	r1_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += 1;
	r2_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += 1;
	value = cursor->reg[r1_id - 1] - cursor->reg[r2_id - 1];
	cursor->carry = (int)(!value);
	r3_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[r3_id - 1] = value;
	cursor->step += 1;
}
