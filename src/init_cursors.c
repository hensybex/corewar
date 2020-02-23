/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cursors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:29:14 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 10:29:15 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_cursor	new_cursor(t_vm *vm, int player_num, int pc)
{
	t_cursor	buff;

	buff.carry = 0;
	buff.id = player_num;
	buff.cycles_to_exec = 0;
	buff.last_live = 0;
	buff.next = NULL;
	buff.op_code = 0;
	buff.pc = pc;
	buff.player = vm->players[player_num];
	buff.reg[0] = 0;
	return (buff);
}

void		add_cursorr(t_cursor **list, t_cursor *new)
{
	if (new)
		new->next = *list;
	*list = new;
}

t_cursor	*init_cursor(t_player *player, int32_t pc)
{
	t_cursor		*cursor;
	static uint32_t	cursor_id;

	if (!(cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor))))
		error("Memory Allocation Error");
	cursor->id = ++cursor_id;
	cursor->carry = 0;
	cursor->op_code = 0;
	cursor->last_live = 0;
	cursor->cycles_to_exec = 0;
	cursor->pc = pc;
	cursor->next = NULL;
	cursor->reg[0] = -(player->id);
	cursor->player = player;
	return (cursor);
}

void		init_cursors(t_vm *vm)
{
	int32_t		id;
	uint32_t	pc;

	id = 1;
	pc = 0;
	while (id <= vm->players_num)
	{
		add_cursorr(&(vm->cursors), init_cursor(vm->players[id - 1], pc));
		vm->cursors_num++;
		pc += MEM_SIZE / vm->players_num;
		id++;
	}
}
