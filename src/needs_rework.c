#include "../includes/corewar.h"
#include "../includes/corewar_op.h"

static void	set_arg_type(int8_t arg_type, int8_t index, t_cursor *cursor)
{
	cursor->args_types[INDEX(index)] = g_arg_code[INDEX(arg_type)];
}

void		parse_types_code(t_vm *vm, t_cursor *cursor, t_op *op)
{
	int8_t args_types_code;

	if (op->args_types_code)
	{
		args_types_code = get_byte(vm, cursor->pc, 1);
		if (op->args_num >= 1)
			set_arg_type((int8_t)((args_types_code & 0xC0) >> 6), 1, cursor);
		if (op->args_num >= 2)
			set_arg_type((int8_t)((args_types_code & 0x30) >> 4), 2, cursor);
		if (op->args_num >= 3)
			set_arg_type((int8_t)((args_types_code & 0xC) >> 2), 3, cursor);
	}
	else
		cursor->args_types[0] = op->args_types[0];
}

int		are_args_types_valid(t_cursor *cursor, t_op *op)
{
	int	i;

	i = 0;
	while (i < op->args_num)
	{
		if (!(cursor->args_types[i] & op->args_types[i])) //ЛЁХА ПОФИКСИ ЭТО ПЛЗ!!!!!! И ЛИБУ НЕ УДАЛЯЙ!!!!
			return (0);
		i++;
	}
	return (1);
}

static t_bool	is_register(t_vm *vm, int32_t pc, int32_t step)
{
	int8_t r_id;

	r_id = get_byte(vm, pc, step);
	return (t_bool)(r_id >= 1 && r_id <= REG_NUMBER);
}

uint32_t	step_size(uint8_t arg_type, t_op *op)
{
	if (arg_type & T_REG)
		return (REG_LEN);
	else if (arg_type & T_DIR)
		return (op->t_dir_size);
	else if (arg_type & T_IND)
		return (IND_SIZE);
	return (0);
}

uint32_t	calc_step(t_cursor *cursor, t_op *op)
{
	int32_t		i;
	uint32_t	step;

	i = 0;
	step = 0;
	step += OP_CODE_LEN + (op->args_types_code ? ARGS_CODE_LEN : 0);
	while (i < g_op[INDEX(cursor->op_code)].args_num)
	{
		step += step_size(cursor->args_types[i], op);
		i++;
	}
	return (step);
}

inline int8_t	get_byte(t_vm *vm, int32_t pc, int32_t step)
{
	return (vm->arena[calc_addr(pc + step)]);
}

int		are_args_valid(t_cursor *cursor, t_vm *vm, t_op *op)
{
	int	step;
	int	i;

	i = 0;
	step = (OP_CODE_LEN + (op->args_types_code ? ARGS_CODE_LEN : 0));
	while (i < op->args_num)
	{
		if ((cursor->args_types[i] == T_REG) && !is_register(vm, cursor->pc, step))
			return (0);
		step += step_size(cursor->args_types[i], op);
		i++;
	}
	return (1);
}