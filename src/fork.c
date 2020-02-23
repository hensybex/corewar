/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:31:14 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:14:41 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				fork_1(t_vm *vm, t_cursor *cursor)
{
	int32_t		addr;
	t_cursor	*new;

	cursor->step += 1;
	addr = get_op_arg(vm, cursor, 1, 1);
	new = duplicate_cursor(cursor, addr % IDX_MOD);
	add_cursorr(&(vm->cursors), new);
	vm->cursors_num++;
}
