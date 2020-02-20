/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:07:42 by enikole           #+#    #+#             */
/*   Updated: 2020/02/19 15:07:49 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void        fork(t_vm *vm, t_cursor *cursor)
{
	int32_t 	arg_1;
	t_cursor	*copy;


	arg_1 = (int32_t)ft_memcpy(ft_memalloc(IND_SIZE), &vm->arena[cursor->pc], IND_SIZE);
	copy = (t_cursor *)ft_memcpy(ft_memalloc(sizeof(t_cursor)), cursor, sizeof(t_cursor));
	free(arg_1);
}
