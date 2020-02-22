/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:03:17 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:04:05 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        st(t_vm *vm, t_cursor *cursor)
{
    int32_t     r1;
    int32_t     arg_2;

	cursor->step += (OP_CODE_LEN + ARG_CODE_LEN);
	r1 = get_value(vm, cursor, 0, 0);
	cursor->step += REG_LEN;
	if (cursor->args_types[1] & T_REG)
	{
		arg_2 = (int8_t)(vm->arena[get_address(cursor->pc + cursor->step)];
		cursor->reg[arg_2 - 1] = r1;
		cursor->step += REG_LEN;
	}
	else
	{
		arg_2 = get_value(vm, cursor, 1, 1);
		//... дописать
		cursor->step += IND_SIZE;
	}
}
