/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:28:43 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:30:21 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		add_player(t_player **list, t_player *new)
{
	t_player *current;

	if (list && new)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
			*list = new;
	}
}

void		*mem_cpy(void *dst, const void *src, size_t n)
{
	char			*ptr1;
	char			*ptr2;
	unsigned int	i;

	i = 0;
	if (dst == src)
		return (dst);
	ptr1 = (char*)dst;
	ptr2 = (char*)src;
	while (i < n)
	{
		ptr1[n - i - 1] = ptr2[i];
		i++;
	}
	return (dst);
}

t_player	*find_player(t_player *list, int32_t id)
{
	t_player *player;

	player = NULL;
	if (id >= 1 && id <= MAX_PLAYERS)
	{
		player = list;
		while (player)
		{
			if (player->id == id)
				return (player);
			player = player->next;
		}
	}
	return (player);
}

void		update_players_id(t_player *list)
{
	t_player	*player;
	int32_t		id;

	id = 1;
	player = list;
	while (player)
	{
		if (player->id == 0)
		{
			while (find_player(list, id))
				id++;
			player->id = id;
		}
		player = player->next;
	}
}

void		set_players(t_vm *vm, t_player *list)
{
	int32_t id;

	id = 1;
	update_players_id(list);
	while (id <= vm->players_num)
	{
		if (!(vm->players[id - 1] = find_player(list, id)))
			error("Что-то пошло не так в set_players");
		id++;
	}
	vm->last_alive = vm->players[vm->players_num - 1];
}
