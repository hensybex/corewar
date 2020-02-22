#include "corewar.h"
#include "libft.h"

int32_t 		get_address(int32_t curr)
{
	curr %= MEM_SIZE;
	if (curr < 0)
		curr += MEM_SIZE;
	return (curr);
}

int32_t			get_value(t_vm *vm, t_cursor *cursor, uint8_t index_arg, char is_mod)
{
	int32_t 	value;
	int32_t 	mem;

	value = 0;
	if (cursor->args_types[index_arg] & T_REG)
		value = cursor->reg[(int8_t)(vm->arena[get_address(cursor->pc + cursor->step)]];
	else if (cursor->args_types[index_arg] & T_DIR)
	{
		//...дописать
		mem = (int32_t)ft_memcpy(ft_memalloc(REG_SIZE), &vm->arena[cursor->pc + 1], REG_SIZE);
		value = vm->arena[];
	}
	else if (cursor->args_types[index_arg] & T_IND)
	{
		//...дописать
	}
	free(mem);
	return (value);
}
