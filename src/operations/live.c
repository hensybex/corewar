/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:51:53 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 14:51:58 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void    		live(t_vm *vm, t_cursor *cursor)
{
	int32_t     arg;
	t_player    *player;

    cursor->last_live = vm->cycles;
    arg = (int32_t)ft_memcpy(ft_memalloc(DIR_SIZE), &vm->arena[cursor->pc], DIR_SIZE);
    if (arg < 0 && arg >= (-1) * vm->players_num)
    {
        player = vm->players[((-1) * arg) - 1];
        player->last_live = vm->cycles;
        player->current_lives_num++;
        vm->last_alive = player;
    }
    vm->lives_num++;
    free(arg);
}
