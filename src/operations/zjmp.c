/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:06:30 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:06:48 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        	zjmp(t_vm *vm, t_cursor *cursor)
{
	int32_t 	arg_1;

	cursor->step += OP_CODE_LEN;
	arg_1 = get_value(vm, cursor, 0, 0);
	if (cursor->carry)
	{
		cursor->pc = get_address(cursor->pc + arg_1 % IDX_MOD);
		cursor->step = 0;
	}
}
