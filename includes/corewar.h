#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/libft.h"
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

#define print_error ft_putendl("--------------------------HEWSTON, A PROBLEM UP HERE!!!--------------------------");
#define print_start ft_putendl("--------------------------START--------------------------");
#define print_end ft_putendl("--------------------------END--------------------------");
typedef struct			s_player
{
	int32_t				id;
	char				*name;
	char				*comment;
	int32_t				code_size;
	uint8_t				*code;
	size_t				current_lives_num;
	size_t				previous_lives_num;
	ssize_t				last_live;
	struct s_player		*next;
}						t_player;

typedef struct			s_cursor
{
	uint32_t			id;
	int					carry;
	uint8_t				op_code;
	ssize_t				last_live;
	int					cycles_to_exec;
	uint8_t				args_types[3];
	int32_t				pc;
	uint32_t			step;
	int32_t				reg[REG_NUMBER];
	t_player			*player;
	struct s_cursor		*next;
}						t_cursor;

typedef struct			s_vm
{
	uint8_t				arena[MEM_SIZE];
	t_player			*players[MAX_PLAYERS];
	int32_t				players_num;
	t_player			*last_alive;
	t_cursor			*cursors;
	size_t				cursors_num;
	size_t				lives_num;
	ssize_t				cycles;
	ssize_t				cycles_to_die;
	ssize_t				cycles_after_check;
	size_t				checks_num;
	//struct s_vs			*vs;
	ssize_t				dump_cycle;
	int					dump_print_mode;
	ssize_t				show_cycle;
	int					show_print_mode;
	//t_bool				display_aff;
	int					log;
}						t_vm;

void					error(char *str);
void					init_cursors(t_vm *vm);
void					print_cursors(t_vm *vm);
void					print_arena_full(t_vm *vm);
void					print_info_for_player(t_vm *vm);
void					entry_arena(t_vm *vm);
void					parse_corewar_args(int ac, char **av, t_vm *vm);
t_player				*find_player(t_player *list, int32_t id);
t_player				*init_player(int id);
int						ft_max_min_int(char *buff);
int						is_cor(char *av);
t_vm					*init_vm(void);

#endif