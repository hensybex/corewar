/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_op.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:31:36 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:57:13 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_OP_H

# define COREWAR_OP_H

# include "../ft_printf/ft_printf.h"
# include "corewar.h"
# include <stdio.h>
# include "op.h"
# include "corewar_vm.h"

typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_num;
	int			args_types_code;
	uint8_t		args_types[3];
	int			modify_carry;
	uint8_t		t_dir_size;
	uint32_t	cycles;
	void		(*func)(t_vm *, t_cursor *);

}				t_op;
void			live(t_vm *vm, t_cursor *pc);
void			ld(t_vm *vm, t_cursor *pc);
void			st(t_vm *vm, t_cursor *pc);
void			add(t_vm *vm, t_cursor *pc);
void			sub(t_vm *vm, t_cursor *pc);
void			and(t_vm *vm, t_cursor *cursor);
void			or(t_vm *vm, t_cursor *cursor);
void			xor(t_vm *vm, t_cursor *cursor);
void			zjmp(t_vm *vm, t_cursor *cursor);
void			ldi(t_vm *vm, t_cursor *cursor);
void			sti(t_vm *vm, t_cursor *cursor);
void			fork_1(t_vm *vm, t_cursor *cursor);
void			lld(t_vm *vm, t_cursor *cursor);
void			lldi(t_vm *vm, t_cursor *cursor);
void			lfork(t_vm *vm, t_cursor *cursor);
void			aff(t_vm *vm, t_cursor *cursor);

static t_op		g_op[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &live
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &ld
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &st
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &add
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &sub
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &and
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &or
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &xor
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 20,
		.func = &zjmp
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &ldi
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &sti
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 800,
		.func = &fork_1
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &lld
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = 1,
		.t_dir_size = 2,
		.cycles = 50,
		.func = &lldi
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 1000,
		.func = &lfork
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = 1,
		.args_types = {T_REG, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 2,
		.func = &aff
	}
};

t_cursor		*duplicate_cursor(t_cursor *cursor, int32_t addr);
int				are_args_valid(t_cursor *cursor, t_vm *vm, t_op *op);
int				are_args_types_valid(t_cursor *cursor, t_op *op);
uint32_t		calc_step(t_cursor *cursor, t_op *op);
uint32_t		step_size(uint8_t arg_type, t_op *op);
int32_t			bytecode_to_4_byte(const uint8_t *arena,
									int32_t addr,
									int32_t size);
void			byte_4_to_bytecode(uint8_t *arena,
									int32_t addr,
									int32_t value,
									int32_t size);
int				are_args_types_valid(t_cursor *cursor, t_op *op);
void			parse_types_code(t_vm *vm, t_cursor *cursor, t_op *op);

#endif
