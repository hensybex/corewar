#include "../includes/corewar.h"

t_cursor	new_cursor(t_vm *vm, int player_num, int pc)
{
	t_cursor	buff;

	buff.carry = 0;
	buff.id = player_num;
	buff.cycles_to_exec = 0;
	buff.last_live = 0;
	buff.next = NULL;
	buff.op_code = 0;
	buff.pc = pc;
	buff.player = vm->players[player_num];
	buff.reg[0] = 0;
	return (buff);
}

void	add_cursor(t_vm *vm, int player_num, int pc)
{
	t_cursor	buff;
	t_cursor	*bbuff;

	buff = new_cursor(vm, player_num, pc);
	if (vm->cursors == NULL)
	{
		vm->cursors = (t_cursor *)malloc(sizeof(t_cursor));
		*(vm->cursors) = buff;
		vm->cursors->next = NULL;
	}
	else
	{
		bbuff = vm->cursors;
		while (bbuff->next != NULL)
			bbuff = bbuff->next;
		bbuff->next = (t_cursor *)malloc(sizeof(t_cursor));
		*(bbuff->next) = buff;
		bbuff->next->next = NULL;
	}
}

void	add_cursorr(t_cursor **list, t_cursor *new)
{
	if (new)
		new->next = *list;
	*list = new;
}

/* void	init_cursors(t_vm *vm)
{
	int	player_num;
	int	pc;

	pc = 0;
	player_num = 0;
	while (player_num < vm->players_num)
	{
		vm->cursors_num++;
		add_cursor(vm, player_num, pc);
		pc += MEM_SIZE / vm->players_num;
		player_num++;
	}
} */


t_cursor	*init_cursor(t_player *player, int32_t pc)
{
	t_cursor		*cursor;
	static uint32_t	cursor_id;

	cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	cursor->id = ++cursor_id;
	cursor->carry = false;
	cursor->op_code = 0;
	cursor->last_live = 0;
	cursor->cycles_to_exec = 0;
	cursor->pc = pc;
	cursor->next = NULL;
	cursor->reg[INDEX(1)] = -(player->id);
	cursor->player = player;
	return (cursor);
}

void	init_cursors(t_vm *vm)
{
	int32_t		id;
	uint32_t	pc;

	id = 1;
	pc = 0;
	while (id <= vm->players_num)
	{
		add_cursorr(&(vm->cursors), init_cursor(vm->players[INDEX(id)], pc));
		vm->cursors_num++;
		pc += MEM_SIZE / vm->players_num;
		id++;
	}
}
