/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:07:53 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:08:08 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        	lld(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t 	r2;

	cursor->step += (OP_CODE_LEN + ARG_CODE_LEN);
	arg_1 = get_value(vm, cursor, 0, 0);
	cursor->carry = (arg_1) ? (0) : (1);
	r2 = (int8_t)(vm->arena[get_address(cursor->pc + cursor->step)];
	cursor->reg[r2 - 1] = arg_1;
	cursor->step += REG_LEN;
}
