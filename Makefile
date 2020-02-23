# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 10:50:47 by smanhack          #+#    #+#              #
#    Updated: 2020/02/23 11:10:48 by smanhack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM_NAME =			corewar
ASM_NAME =			asm

INC =			-I ./includes/ \
				-I ./ft_printf/ \

LIB =			-L ./ft_printf -lftprintf

FLAGS = 		-O3 -Wall -Wextra -Werror

VM_LIST =		corewar \
				error_vm \
				init_cursors \
				init \
				parse \
				help_func \
				battle \
				needs_rework \
				op_add \
				op_aff \
				op_and \
				op_fork \
				op_ld \
				op_ldi \
				op_lfork \
				op_live \
				op_lld \
				op_lldi \
				op_or \
				op_st \
				op_sti \
				op_sub \
				op_xor \
				op_zjmp \
				utils \
				print_info \

ASM_LIST =		asm \
				error \
				parser \
				command_search \
				label_search \
				label_processing \
				label_converter \
				to_asm_code \
				file \
				checks \
				add_arg \
				memory_clearing \
				command_1 \
				command_2 \
				command_3 \
				command_4 \
				is_1 \
				is_2 \
				skip \
				search_name \
				search_comment \
				sizing_1 \
				sizing_2 \
				garbage_collector \

VM_OBJ =			$(addprefix obj/, $(addsuffix .o, $(VM_LIST)))
ASM_OBJ =			$(addprefix obj/, $(addsuffix .o, $(ASM_LIST)))

all: $(VM_NAME) $(ASM_NAME)

obj/%.o: src/%.c
	@gcc $(FLAGS) -c $< -o $@ $(INC)

$(VM_NAME): obj $(VM_OBJ)
	@make -C ft_printf
	@gcc $(VM_OBJ) -o $(VM_NAME) $(LIB)

$(ASM_NAME): obj $(ASM_OBJ)
	@make -C ft_printf
	@gcc $(ASM_OBJ) -o $(ASM_NAME) $(LIB)

obj:
	@mkdir obj

clean:
	@make -C ft_printf clean
	@rm -rf obj
	
fclean: clean
	@make -C ft_printf fclean
	@rm -f $(VM_NAME)
	@rm -f $(ASM_NAME)

re: fclean all

.PHONY: all clean fclean re