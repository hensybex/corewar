#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/libft.h"
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "corewar_op.h"
# include "corewar_vm.h"


static uint8_t			g_arg_code[3] = {
	T_REG,
	T_DIR,
	T_IND
};

# define INDEX(X)		((X) - 1)
# define FT_ABS(X)		(((X) < 0) ? (-(X)) : (X))
# define OP_CODE_LEN	1
# define ARGS_CODE_LEN	1
# define REG_LEN		1

#define print_error ft_putendl("--------------------------HEWSTON, A PROBLEM UP HERE!!!--------------------------");
#define print_start ft_putendl("--------------------------START--------------------------");
#define print_end ft_putendl("--------------------------END--------------------------");

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
void					add_cursor(t_vm *vm, int player_num, int pc);
void					battle(t_vm *vm);

void		run_operation(t_vm *vm, t_cursor *cursor);

int32_t		get_op_arg(t_vm *vm, t_cursor *cursor, uint8_t index, t_bool mod);
void		int32_to_bytecode(uint8_t *arena, int32_t addr, int32_t value,int32_t size);
int32_t		bytecode_to_int32(const uint8_t *arena, int32_t addr, int32_t size);
int8_t		get_byte(t_vm *vm, int32_t pc, int32_t step);
int32_t		calc_addr(int32_t addr);

#endif