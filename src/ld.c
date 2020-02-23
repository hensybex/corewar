/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:31:09 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:14:45 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				ld(t_vm *vm, t_cursor *cursor)
{
	int32_t	value;
	int32_t	r_id;

	cursor->step += 2;
	value = get_op_arg(vm, cursor, 1, 1);
	cursor->carry = (int)(!value);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[r_id - 1] = value;
	cursor->step += 1;
}
