/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:03:17 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:04:05 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        st(t_vm *vm, t_cursor *cursor)
{
    int32_t     arg_1;
    int32_t     arg_2;
    int32_t     pc;

    arg_1 = (int32_t)ft_memcpy(ft_memalloc(REG_SIZE), &vm->arena[cursor->pc + 1], REG_SIZE);
    if (cursor->args_types[1] & T_REG)
    {
        arg_2 = (int32_t)ft_memcpy(ft_memalloc(REG_SIZE), &vm->arena[cursor->pc + 1 + REG_SIZE], REG_SIZE);
        cursor->reg[arg_2 - 1] = cursor->reg[arg_1 - 1];
    }
    else if (cursor->args_types[1] & T_IND)
    {
        arg_2 = (int32_t)ft_memcpy(ft_memalloc(IND_SIZE), &vm->arena[cursor->pc + 1 + IND_SIZE], IND_SIZE);
        pc = cursor->pc + arg_2 % IDX_MOD;
		vm->arena[pc] = cursor->reg[arg_1 - 1];
    }
    free(arg_1);
    free(arg_2);
}
