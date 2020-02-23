/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:22:25 by smanhack          #+#    #+#             */
/*   Updated: 2020/02/01 17:35:14 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "asm_op.h"
# include "../ft_printf/ft_printf.h"
# include "garbage_collector.h"

typedef struct			s_labels
{
	char				*label;
	struct s_labels		*next;
}						t_labels;

typedef struct			s_command
{
	int					type;
	char				*arg[3];
	struct s_command	*next;
	t_labels			*labels;
	int					arg_num;
	size_t				label_size;
}						t_command;

typedef struct			s_parse
{
	int					line_num;
	char				*name;
	char				*comment;
	t_command			*list_cmd;
	t_labels			*labels;
	int32_t				size;
	uint8_t				*exec_code;
}						t_parse;

void					parse(char *file, t_parse *champ);
void					command_search(char *line,
						t_parse *champ, t_labels *labels);
void					label_search(char *line, t_parse *champ, int fd);
char					*skip_whitespace(char *line);
void					label_processing(char *line, int fd, t_parse *champ);
int						is_label(char *line);
char					*cut_label(char *str);
size_t					sizing(t_command *buff);
void					label_conversion(t_parse *champ);
void					to_asm_code(t_parse *champ);
void					write_bytecode_file(int fd, t_parse *champ);
void					mem_cpy(void *dst, void *src, int n);
char					*cut_comment(char *line);
int						check_num(char *line);
void					print_labels(t_parse *champ);
int						is_whitespace(int c);
size_t					add_arg(t_command *buff, size_t i, t_parse *champ);
uint8_t					args_type_code(t_command *buff);
void					memory_clearing(t_parse *champ);
void					error(char *error, int line);
void					check_exception(char *line, int line_num);
void					check_label_symbols(char *line, int line_num);
void					check_label_symbol(char symbol, int line_num);
void					free_buff_l(char *buff_l, char *buff);
char					*is_dir(char *line, t_command *cmd, t_parse *champ);
char					*is_indir(char *line, t_command *cmd, t_parse *champ);
char					*is_reg(char *line, t_command *cmd, t_parse *champ);
char					*is_regindir(char *line,
						t_command *cmd, t_parse *champ);
char					*is_regdir(char *line, t_command *cmd, t_parse *champ);
char					*is_dirindir(char *line,
						t_command *cmd, t_parse *champ);
char					*is_any(char *line, t_command *cmd, t_parse *champ);
char					*find_separator(char *line, int line_num);
void					check_aff(t_command *cmd, char *line, t_parse *champ);
void					check_lfork(t_command *cmd, char *line, t_parse *champ);
void					check_lldi(t_command *cmd, char *line, t_parse *champ);
void					check_lld(t_command *cmd, char *line, t_parse *champ);
void					check_fork(t_command *cmd, char *line, t_parse *champ);
void					check_or(t_command *cmd, char *line, t_parse *champ);
void					check_xor(t_command *cmd, char *line, t_parse *champ);
void					check_zjmp(t_command *cmd, char *line, t_parse *champ);
void					check_ldi(t_command *cmd, char *line, t_parse *champ);
void					check_sti(t_command *cmd, char *line, t_parse *champ);
void					add_command(t_command *cmd, t_parse *champ);
void					check_ld(t_command *cmd, char *line, t_parse *champ);
void					check_st(t_command *cmd, char *line, t_parse *champ);
void					check_add(t_command *cmd, char *line, t_parse *champ);
void					check_sub(t_command *cmd, char *line, t_parse *champ);
void					check_and(t_command *cmd, char *line, t_parse *champ);
void					check_live(t_command *cmd, char *line, t_parse *champ);
char					*cut_arg(char *line);
char					*is_any(char *line, t_command *cmd, t_parse *champ);
void					add_cmd_arg(char *line, t_command *cmd);
void					check_label_validity(char *line, t_parse *champ);
t_command				*command_init(void);
char					*cut_command(char *line);
void					name_search(char *line, t_parse *champ, int fd);
void					comment_search(char *line, t_parse *champ, int fd);
void					line_processing(char *line, t_parse *champ, int fd);
size_t					sizing_line_down(t_command *buff, int location);
int						label_in_arg(t_command *command);
char					*cut_first_symbol(char *line);
char					*cut_first_two_symbols(char *line);
int						find_label(char *arg, t_parse *champ);
size_t					calculate_sizing(t_parse *champ,
						t_command *command, int cmd_num, int needed_arg);
char					*new_l(char *line);
void					check_last_symbols_part(char *line);
char					*cut_label(char *str);
int						is_label(char *line);

#endif
