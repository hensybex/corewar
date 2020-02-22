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

	cursor->step += OP_CODE_LEN;
    cursor->last_live = vm->cycles;
    arg = get_value(vm, cursor, 0, 0);
    if (arg < 0 && arg >= (-1) * vm->players_num)
    {
        player = vm->players[((-1) * arg) - 1];
		player->current_lives_num++;
        player->last_live = vm->cycles;
        vm->last_alive = player;
    }
    vm->lives_num++;
}
