NAME =			corewar

INC =			-I ./includes/ \
				-I ./ft_printf/ \

LIB =			-L ./ft_printf -lftprintf

FLAGS = 		-O3 -Wall -Wextra -Werror

LIST =			corewar \
				error \
				init_cursors \
				info \
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

all: $(NAME)

obj/%.o: src/%.c
	@gcc $(FLAGS) -c $< -o $@ $(INC)

$(NAME): obj $(OBJ)
	@make -C ft_printf
	@gcc $(OBJ) -o $(NAME) $(LIB)

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