/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:06:13 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:06:24 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        xor(t_vm *vm, t_cursor *cursor)
{
	int32_t    	arg_1;
	int32_t     arg_2;
	int32_t		r3;

	cursor->step += (OP_CODE_LEN + ARG_CODE_LEN);
	arg_1 = get_value(vm, cursor, 0, 1);
	arg_2 = get_value(vm, cursor, 1, 1);
	r3 = (int8_t)(vm->arena[get_address(cursor->pc + cursor->step)];
	cursor->reg[r3 - 1] = arg_1 ^ arg_2;
	cursor->carry = (cursor->reg[r3 - 1]) ? (0) : (1);
	cursor->step += REG_LEN;
}
