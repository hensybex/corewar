#include "../includes/corewar.h"
#include <stdio.h>

void		print_cursors(t_vm *vm)
{
	t_cursor	*buff;
	int			i;

	i = 0;
	buff = vm->cursors;
	while (buff != NULL)
	{
		buff = buff->next;
		i++;
	}
}

void		print_info_for_player(t_vm *vm)
{
	t_player	*player;
	int32_t		i;
	int32_t		j;

	j = 0;
	printf("Dump cycle: %zd\nPrint_mode: %d\n\n", vm->dump_cycle, vm->dump_print_mode);
	while (j < vm->players_num)
	{
		player = vm->players[j];
		printf("Меня зовут: %s\n", player->name);
		printf("Мой комментарий: %s\n", player->comment);
		printf("Мой размер кода: %d\n", player->code_size);
		i = 0;
		while (i < player->code_size)
		{
			if (i % 16 == 0)
				printf("\n");
			else if (i % 2 == 0)
				printf(" ");
			printf("%02x", player->code[i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

void		print_arena_full(t_vm *vm)
{
	ssize_t i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % (MEM_SIZE / 32) == 0)
			printf("\n");
		else if (i % 2 == 0)
			printf (" ");
		printf("%01x", vm->arena[i]);
		i++;
	}
	printf("\n");
}