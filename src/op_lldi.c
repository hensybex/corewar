/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobytheturtle <noobytheturtle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:49:45 by ablizniu          #+#    #+#             */
/*   Updated: 2020/02/15 13:54:13 by noobythetur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				op_lldi(t_vm *vm, t_cursor *cursor)
{
	int32_t	addr_1;
	int32_t	addr_2;
	int32_t	r_id;

	cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
	addr_1 = get_op_arg(vm, cursor, 1, true);
	addr_2 = get_op_arg(vm, cursor, 2, true);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r_id)] = bytecode_to_int32(vm->arena,
			cursor->pc + (addr_1 + addr_2), DIR_SIZE);
	cursor->step += REG_LEN;
}