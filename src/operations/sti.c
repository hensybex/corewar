/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:07:29 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:07:37 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        	sti(t_vm *vm, t_cursor *cursor)
{
	int32_t 	r1;
	int32_t 	adr_1;
	int32_t 	adr_2;

	cursor->step += (OP_CODE_LEN + ARG_CODE_LEN);
	r1 = get_value(vm, cursor, 0, 0);
	cursor->step += REG_LEN;
	adr_1 = get_value(vm, cursor, 1, 1);
	adr_2 = get_value(vm, cursor, 2, 1);
	//smth to do
}