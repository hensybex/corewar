/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:31:08 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:31:51 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		parse_aff(int *ac, char ***av, t_vm *vm)
{
	vm->display_aff = 1;
	(*ac)--;
	(*av)++;
}

void		parse_dump(int *ac, char ***av, t_vm *vm)
{
	if (!vm->dump_print_mode && *ac >= 2 && ft_max_min_int(*(*av + 1)))
	{
		if ((vm->dump_cycle = ft_atoi(*(*av + 1))) < 0)
			vm->dump_cycle = -1;
		if (!ft_strcmp(**av, "-d"))
			vm->dump_print_mode = 64;
		else
			vm->dump_print_mode = 32;
		(*ac) -= 2;
		(*av) += 2;
	}
	else
		error("Not valid -dump/-d arg");
}

void		parse_corewar_args(int ac, char **av, t_vm *vm)
{
	t_player *list;

	list = NULL;
	while (ac >= 1)
	{
		if (!ft_strcmp(*av, "-dump") || !ft_strcmp(*av, "-d"))
			parse_dump(&ac, &av, vm);
		else if (!ft_strcmp(*av, "-n") || is_cor(*av))
			parse_file(&ac, &av, vm, &list);
		else if (!ft_strcmp(*av, "-a"))
			parse_aff(&ac, &av, vm);
		else
			error("Error arg");
	}
	if (vm->players_num < 1 || vm->players_num > MAX_PLAYERS)
		error("Error arg");
	set_players(vm, list);
}
