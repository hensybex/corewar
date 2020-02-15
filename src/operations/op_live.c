/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:48:45 by enikole           #+#    #+#             */
/*   Updated: 2020/02/14 16:48:47 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void    		op_live(t_vm *vm, t_cursor *cursor)
{
	int32_t     arg;
	t_player    *player;

    cursor->last_live = vm->cycles;
    arg = (int32_t)ft_memcpy(ft_memalloc(DIR_SIZE), &vm->arena[cursor->pc], DIR_SIZE);
    if (arg < 0 && arg >= (-1) * vm->players_num)
    {
        player = vm->players[(-1) * arg]);
        player->last_live = vm->cycles;
        player->current_lives_num++;
    }
    //vm->lives_num++;
}
