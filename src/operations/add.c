/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:04:17 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:04:31 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        add(t_vm *vm, t_cursor *cursor)
{
	int32_t    	r1;
	int32_t     r2;
	int32_t 	r3;

	r1 = (int32_t)ft_memcpy(ft_memalloc(REG_SIZE), &vm->arena[cursor->pc + 1], REG_SIZE);
	r2 = (int32_t)ft_memcpy(ft_memalloc(REG_SIZE), &vm->arena[cursor->pc + 1 + REG_SIZE], REG_SIZE);
	r3 = (int32_t)ft_memcpy(ft_memalloc(REG_SIZE), &vm->arena[cursor->pc + 1 + 2 * REG_SIZE], REG_SIZE);
	cursor->reg[r3 - 1] = cursor->reg[r1 - 1] + cursor->reg[r2 - 1];
	cursor->carry = (cursor->reg[r3 - 1]) ? (0) : (1);
	free(r1);
	free(r2);
	free(r3);
}
