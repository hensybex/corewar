/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:29:54 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 10:34:14 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		introduction(t_player **p, int32_t num)
{
	int32_t i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < num)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		i + 1, p[i]->code_size, p[i]->name, p[i]->comment);
		i++;
	}
}

void		print_winner(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
	modul(vm->last_alive->id), vm->last_alive->name);
}

void		free_players(t_player **players, int32_t players_num)
{
	int32_t i;

	i = 0;
	while (i < players_num)
	{
		ft_strdel(&(players[i]->name));
		ft_strdel(&(players[i]->comment));
		ft_memdel((void **)&(players[i]->code));
		ft_memdel((void **)&players[i]);
		i++;
	}
}
