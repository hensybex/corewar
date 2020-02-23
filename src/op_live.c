/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:30:54 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 10:30:55 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void				op_live(t_vm *vm, t_cursor *cursor)
{
	int32_t		player_id;
	t_player	*player;

	cursor->step += OP_CODE_LEN;
	player_id = get_op_arg(vm, cursor, 1, 0);
	vm->lives_num++;
	cursor->last_live = vm->cycles;
	player = NULL;
	if (player_id <= -1 && player_id >= -((int32_t)vm->players_num))
	{
		player = vm->players[INDEX(modul(player_id))];
		player->last_live = vm->cycles;
		player->current_lives_num++;
		vm->last_alive = player;
	}
}
