/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:29:40 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:14:27 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void	aff(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	value;

	cursor->step += 2;
	r_id = get_byte(vm, cursor->pc, cursor->step);
	value = cursor->reg[r_id - 1];
	cursor->step += 1;
	if (vm->display_aff)
		ft_printf("Aff: %c\n", (char)value);
}
