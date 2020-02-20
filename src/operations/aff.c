/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:09:00 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:09:13 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        aff(t_vm *vm, t_cursor *cursor)
{
    int32_t 	r1;
    char        value;

    r1 = (int32_t)ft_memcpy(ft_memalloc(REG_SIZE), &vm->arena[cursor->pc + 1], REG_SIZE);
    value = (char)cursor->reg[r1 - 1];
    write(1, &value, 1);
    free(r1);
}
