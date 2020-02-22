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
    int32_t     r2;

    cursor->step += (OP_CODE_LEN + ARG_CODE_LEN);
    arg_1 = get_value(vm, cursor, 0, 1);
    r2 = get_value(vm, cursor, 1, 0);
    cursor->reg[r2 - 1] = arg_1;
    cursor->carry = (arg_1) ? (0) : (1);
    cursor->step += REG_LEN;
}
