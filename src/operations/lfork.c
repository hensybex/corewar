/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:08:40 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:08:50 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        	lfork(t_vm *vm, t_cursor *cursor)
{
	int32_t 	arg_1;

	cursor->step += OP_CODE_LEN;
	arg_! = get_value(vm, cursor, 0, 1);
	//duplixate
	//add cursor
	vm->cursors_num++;
}
