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

void	init_cursors(t_vm *vm)
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
	ft_putendl("End of cursor init\n");
}