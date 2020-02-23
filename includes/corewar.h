/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 10:31:47 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/23 14:57:21 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../ft_printf/ft_printf.h"
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

void					error(char *str);
void					init_cursors(t_vm *vm);
void					print_cursors(t_vm *vm);
void					print_arena(uint8_t *arena, int print_mode);
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
t_cursor				*init_cursor(t_player *player, int32_t pc);
int32_t					modul(int32_t id);
void					run_operation(t_vm *vm, t_cursor *cursor);
int32_t					get_op_arg(t_vm *vm, t_cursor *cursor,
						uint8_t index, int mod);
void					byte_4_to_bytecode(uint8_t *arena,
						int32_t addr, int32_t value, int32_t size);
int32_t					bytecode_to_4_byte(const uint8_t
						*arena, int32_t addr, int32_t size);
int8_t					get_byte(t_vm *vm, int32_t pc, int32_t step);
int32_t					calc_addr(int32_t addr);
void					add_cursorr(t_cursor **list, t_cursor *new);
void					introduction(t_player **p, int32_t num);
void					print_winner(t_vm *vm);
void					free_players(t_player **players, int32_t players_num);
void					update_lives_num(t_vm *vm);
void					add_player(t_player **list, t_player *new);
void					*mem_cpy(void *dst, const void *src, size_t n);
t_player				*find_player(t_player *list, int32_t id);
void					update_players_id(t_player *list);
void					set_players(t_vm *vm, t_player *list);
void					parse_aff(int *ac, char ***av, t_vm *vm);
void					parse_dump(int *ac, char ***av, t_vm *vm);
void					parse_corewar_args(int ac, char **av, t_vm *vm);
void					run_cycles(t_vm *vm);
int32_t					calc_addr(int32_t addr);
void					update_op_code(t_vm *vm, t_cursor *cursor);
void					move_cursor(t_cursor *cursor);
void					run_operation(t_vm *vm, t_cursor *cursor);
void					parse_file(int *ac, char ***av, t_vm *vm,
						t_player **list);

#endif
