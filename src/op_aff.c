/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:29:40 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 10:31:25 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void	op_aff(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	value = cursor->reg[INDEX(r_id)];
	cursor->step += REG_LEN;
	if (vm->display_aff)
		ft_printf("Aff: %c\n", (char)value);
}
