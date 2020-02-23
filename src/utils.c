/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:29:47 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 10:29:51 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

int32_t		bytecode_to_4_byte(const uint8_t *arena, int32_t addr, int32_t size)
{
	int32_t		result;
	int			sign;
	int			i;

	result = 0;
	sign = (int)(arena[calc_addr(addr)] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((arena[calc_addr(addr + size - 1)] ^ 0xFF) << (i++ * 8));
		else
			result += arena[calc_addr(addr + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

void		byte_4_to_bytecode(uint8_t *arena, int32_t addr, int32_t value,
						int32_t size)
{
	int8_t i;

	i = 0;
	while (size)
	{
		arena[calc_addr(addr + size - 1)] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

int32_t		get_op_arg(t_vm *vm, t_cursor *cursor, uint8_t index, int mod)
{
	t_op		*op;
	int32_t		value;
	int32_t		addr;

	op = &g_op[cursor->op_code - 1];
	value = 0;
	if (cursor->args_types[index - 1] & T_REG)
		value = cursor->reg[get_byte(vm, cursor->pc, cursor->step) - 1];
	else if (cursor->args_types[index - 1] & T_DIR)
		value = bytecode_to_4_byte(vm->arena,
								cursor->pc + cursor->step,
								op->t_dir_size);
	else if (cursor->args_types[index - 1] & T_IND)
	{
		addr = bytecode_to_4_byte(vm->arena,
								cursor->pc + cursor->step,
								IND_SIZE);
		value = bytecode_to_4_byte(vm->arena,
							cursor->pc + (mod ? (addr % IDX_MOD) : addr),
							DIR_SIZE);
	}
	cursor->step += step_size(cursor->args_types[index - 1], op);
	return (value);
}

t_cursor	*duplicate_cursor(t_cursor *cursor, int32_t addr)
{
	t_cursor	*new;
	int			i;

	addr = calc_addr(cursor->pc + addr);
	new = init_cursor(cursor->player, addr);
	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = cursor->reg[i];
		i++;
	}
	new->carry = cursor->carry;
	new->last_live = cursor->last_live;
	return (new);
}

int32_t		modul(int32_t id)
{
	if (id < 0)
		return (-id);
	return (id);
}
