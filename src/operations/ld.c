/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:54:56 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 14:54:57 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void            ld(t_vm *vm, t_cursor *cursor)
{
    int32_t     arg_1;
    int32_t     arg_2;
    int32_t     pc;

    if (cursor->args_types[0] & DIR_CODE)
    {
        arg_1 = (int32_t)ft_memcpy(ft_memalloc(DIR_SIZE), &vm->arena[cursor->pc + 1], DIR_SIZE);
        arg_2 = (int32_t)ft_memcpy(ft_memalloc(REG_SIZE), &vm->arena[cursor->pc + 1 + DIR_SIZE], REG_SIZE);
    }
    else if (cursor->args_types[0] & IND_CODE)
    {
        arg_1 = (int32_t)ft_memcpy(ft_memalloc(IND_SIZE), &vm->arena[cursor->pc + 1], IND_SIZE);
        arg_2 = (int32_t)ft_memcpy(ft_memalloc(REG_SIZE), &vm->arena[cursor->pc + 1 + IND_SIZE], REG_SIZE);
        pc = cursor->pc + arg_1 % IDX_MOD;
        free(arg_1);
        arg_1 = (int32_t)ft_memcpy(ft_memalloc(DIR_SIZE), &vm->arena[pc], DIR_SIZE);
    }
    cursor->reg[arg_2 - 1] = arg_1;
    cursor->carry = (arg_1 == 0) ? (1) : (0);
    free(arg_1);
    free(arg_2);
}
