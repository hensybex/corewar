/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobytheturtle <noobytheturtle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:50:27 by ablizniu          #+#    #+#             */
/*   Updated: 2020/02/15 18:49:36 by noobythetur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_op.h"

void				op_add(t_vm *vm, t_cursor *cursor)
{
	int32_t	r1_id;
	int32_t	r2_id;
	int32_t	r3_id;
	int32_t	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r1_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	r2_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	value = cursor->reg[INDEX(r1_id)] + cursor->reg[INDEX(r2_id)];
	cursor->carry = (t_bool)(!value);
	r3_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r3_id)] = value;
	cursor->step += REG_LEN;
}
