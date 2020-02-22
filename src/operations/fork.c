/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:07:42 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:07:49 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        fork(t_vm *vm, t_cursor *cursor)
{
	int32_t 	arg_1;
	t_cursor	*copy;

	cursor->step += OP_CODE_LEN;
	arg_1 = get_value(vm, cursor, 0, 1);
	//need to duplicate
	vm->cursors_num++;
}
