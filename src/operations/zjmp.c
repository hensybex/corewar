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

	arg_1 = (int32_t)ft_memcpy(ft_memalloc(IND_SIZE), &vm->arena[cursor->pc], IND_SIZE);
	if (cursor->carry)
		cursor->pc += arg_1 % IDX_MOD;
	free(arg_1);
}
