/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobytheturtle <noobytheturtle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:54:46 by ablizniu          #+#    #+#             */
/*   Updated: 2020/02/15 13:52:47 by noobythetur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				op_lfork(t_vm *vm, t_cursor *cursor)
{
	int32_t		addr;
	t_cursor	*new;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, true);
	new = duplicate_cursor(cursor, addr);
	add_cursor(&(vm->cursors), new);
	vm->cursors_num++;
}
