# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 18:27:40 by smanhack          #+#    #+#              #
#    Updated: 2019/10/29 13:00:09 by smanhack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libftprintf.a

INC =			.

LIST =			f_cps \
				ft_diouxx_up \
				ft_printf \
				ft_second \
				ft_third \
				doublf \
				ldoublf \
				doublf_part_2 \
				doublf_part_3 \
				doublf_part_4 \
				doublf_part_5 \
				ldoublf_part_2 \
				ldoublf_part_3 \
				ldoublf_part_4 \
				ldoublf_part_5 \
				ldoublf_part_6 \
				ft_fourth \
				ldoublf_part_7 \
				ft_rainbow \
				bonus_part

LIST_LIB =		ft_atoi \
				ft_lstiter \
				ft_putchar \
				ft_strcmp \
				ft_strmapi \
				ft_strtrim \
				ft_bzero \
				ft_lstmap \
				ft_putchar_fd \
				ft_strcpy \
				ft_strncat \
				ft_tolower \
				ft_isalnum \
				ft_lstnew \
				ft_putendl \
				ft_strdel \
				ft_strncmp \
				ft_toupper \
				ft_isalpha \
				ft_memalloc \
				ft_putendl_fd \
				ft_strdup \
				ft_strncpy \
				ft_isascii \
				ft_memccpy \
				ft_putnbr \
				ft_strequ \
				ft_strnequ \
				ft_isdigit \
				ft_memchr \
				ft_putnbr_fd \
				ft_striter \
				ft_strnew \
				ft_isprint \
				ft_memcmp \
				ft_putstr \
				ft_striteri \
				ft_strnstr \
				ft_itoa \
				ft_memcpy \
				ft_putstr_fd \
				ft_strjoin \
				ft_strrchr \
				ft_lstadd \
				ft_memdel \
				ft_strcat \
				ft_strlcat \
				ft_strsplit \
				ft_lstdel \
				ft_memmove \
				ft_strchr \
				ft_strlen \
				ft_strstr \
				ft_lstdelone \
				ft_memset \
				ft_strclr \
				ft_strmap \
				ft_strsub \
				ft_realloc \
				ft_number_of_digits \
				ft_itoa_base_ull \
				ft_putnbr_endl \
				ft_itoa_ll \
				ft_strsizeupdata \
				ft_strset \
				get_next_line \
				ft_number_of_word \
				ft_freesplit \
				ft_itoa_base_size_t \
				ft_itoa_base_uintmax_t \
				ft_itoa_intmax_t \
				ft_itoa_ssize_t \
				ft_is_space \
				ft_strndup \
				ft_strdeljoin \

OBJ_LIB = $(addprefix libft/obj/, $(addsuffix .o, $(LIST_LIB)))

OBJ_PRINTF = $(addsuffix .o, $(LIST))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_PRINTF)
	@make -C libft
	@ar rc $(NAME) $(OBJ_LIB) $(OBJ_PRINTF)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I $(INC)

clean:
	@rm -rf $(OBJ_PRINTF)
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re