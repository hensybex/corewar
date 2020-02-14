/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:22:59 by enikole           #+#    #+#             */
/*   Updated: 2020/02/12 14:23:06 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void    		op_live(t_vm *vm, t_cursor *cursor)
{
	uint32_t	arg_player;

    cursor->last_live = vm->cycles;
    arg_player = (uint32_t)ft_memcpy(ft_memalloc(DIR_SIZE), vm->arena[cursor->pc], DIR_SIZE);
    if (arg_player )
    //vm->lives_num++;
}
