# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 18:27:40 by smanhack          #+#    #+#              #
#    Updated: 2019/10/29 12:46:45 by smanhack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a

HEADERS =		-I.

LIST =			ft_atoi \
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
				ft_strndup

FLAGS = -Wall -Wextra -Werror

OBJ =		$(addprefix obj/, $(addsuffix .o, $(LIST)))

all: $(NAME)

obj/%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ $(HEADERS)

$(NAME): obj $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

obj:
	@mkdir obj
	
clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

.PHONY: all clean fclean re