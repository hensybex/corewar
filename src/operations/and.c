/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:05:00 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:05:50 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        and(t_vm *vm, t_cursor *cursor)
{
	//
	// !!! OPTIMISATION NEEDED !!!
	//
	int32_t    	arg_1;
	int32_t     arg_2;
	int32_t 	r3;

	if (cursor->args_types[0] & REG_CODE)
		arg_1 = (int32_t)ft_memcpy(ft_memalloc(REG_SIZE), &vm->arena[cursor->pc + 1], REG_SIZE);
	else if (cursor->args_types[0] & DIR_CODE)
		arg_1 = (int32_t)ft_memcpy(ft_memalloc(DIR_SIZE), &vm->arena[cursor->pc + 1], DIR_SIZE);
	else if (cursor->args_types[0] & IND_CODE)
		arg_1 = (int32_t)ft_memcpy(ft_memalloc(IND_SIZE), &vm->arena[cursor->pc + 1], IND_SIZE);
	if (cursor->args_types[1] & REG_CODE)
		arg_1 = (int32_t)ft_memcpy(ft_memalloc(REG_SIZE), &vm->arena[cursor->pc + 1], REG_SIZE);
	else if (cursor->args_types[1] & DIR_CODE)
		arg_1 = (int32_t)ft_memcpy(ft_memalloc(DIR_SIZE), &vm->arena[cursor->pc + 1], DIR_SIZE);
	else if (cursor->args_types[1] & IND_CODE)
		arg_1 = (int32_t)ft_memcpy(ft_memalloc(IND_SIZE), &vm->arena[cursor->pc + 1], IND_SIZE);

	r3 = (int32_t)ft_memcpy(ft_memalloc(REG_SIZE), &vm->arena[cursor->pc + 1 + 2 * REG_SIZE], REG_SIZE);

	cursor->carry = (cursor->reg[r3 - 1]) ? (0) : (1);
	free(arg_1);
	free(arg_2);
	free(r3);
}
