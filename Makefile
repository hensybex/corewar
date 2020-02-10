NAME =			corewar

INC =			-I ./includes \
				-I ./libft/
LIB =			-L ./libft -lft

FLAGS =			

LIST =			corewar \
				error \

OBJ =			$(addprefix obj/, $(addsuffix .o, $(LIST)))

all: $(NAME)

obj/%.o: src/%.c
	@gcc $(FLAGS) -c $< -o $@ $(INC)

$(NAME): obj $(OBJ)
	@make -C libft
	@gcc $(OBJ) -o $(NAME) $(LIB)

obj:
	@mkdir obj

clean:
	@make -C libft clean
	@rm -rf obj
	
fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re