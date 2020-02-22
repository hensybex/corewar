/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:04:35 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:04:53 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        sub(t_vm *vm, t_cursor *cursor)
{
	int32_t    	r1;
	int32_t     r2;
	int32_t 	r3;

	cursor->step += (OP_CODE_LEN + ARG_CODE_LEN);
	r1 = get_value(vm, cursor, 0, 0);
	cursor->step += REG_LEN;
	r2 = get_value(vm, cursor, 1, 0);
	cursor->step += REG_LEN;
	r3 = (int8_t)(vm->arena[get_address(cursor->pc + cursor->step)];
	cursor->reg[r3 - 1] = r1 - r2;
	cursor->carry = (cursor->reg[r3 - 1]) ? (0) : (1);
	cursor->step += REG_LEN;
}
