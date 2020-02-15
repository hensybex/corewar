/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noobytheturtle <noobytheturtle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:23:16 by ablizniu          #+#    #+#             */
/*   Updated: 2020/02/15 13:59:17 by noobythetur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				op_live(t_vm *vm, t_cursor *cursor)
{
	int32_t		player_id;
	t_player	*player;

	cursor->step += OP_CODE_LEN;
	player_id = get_op_arg(vm, cursor, 1, false);
	vm->lives_num++;
	cursor->last_live = vm->cycles;
	player = NULL;
	if (player_id <= -1 && player_id >= -((int32_t)vm->players_num))
	{
		player = vm->players[INDEX(FT_ABS(player_id))];
		player->last_live = vm->cycles;
		player->current_lives_num++;
		vm->last_alive = player;
	}
}
