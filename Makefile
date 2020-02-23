# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 10:50:47 by smanhack          #+#    #+#              #
#    Updated: 2020/02/23 10:51:28 by smanhack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM_NAME =			corewar

INC =			-I ./includes/ \
				-I ./ft_printf/ \

LIB =			-L ./ft_printf -lftprintf

FLAGS = 		-O3 -Wall -Wextra -Werror

LIST =			corewar \
				error \
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

OBJ =			$(addprefix obj/, $(addsuffix .o, $(LIST)))

all: $(VM_NAME)

obj/%.o: src/%.c
	@gcc $(FLAGS) -c $< -o $@ $(INC)

$(VM_NAME): obj $(OBJ)
	@make -C ft_printf
	@gcc $(OBJ) -o $(VM_NAME) $(LIB)

obj:
	@mkdir obj

clean:
	@make -C ft_printf clean
	@rm -rf obj
	
fclean: clean
	@make -C ft_printf fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re