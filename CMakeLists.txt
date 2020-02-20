cmake_minimum_required(VERSION 3.15)
project(corewar C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft)

add_executable(corewar
        includes/corewar.h
        includes/op.h
        libft/ft_10_to_16.c
        libft/ft_10_to_16_long.c
        libft/ft_10_to_8.c
        libft/ft_10_to_8_long.c
        libft/ft_abs.c
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_capitalize.c
        libft/ft_count_num.c
        libft/ft_count_num_16.c
        libft/ft_count_num_8.c
        libft/ft_count_num_big.c
        libft/ft_count_num_long.c
        libft/ft_count_num_long_long.c
        libft/ft_countwords.c
        libft/ft_get_word_len.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isnumber.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_lltoa.c
        libft/ft_lstadd.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_lstnew.c
        libft/ft_ltoa.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_power.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_8.c
        libft/ft_putnbr_8_long.c
        libft/ft_putnbr_big.c
        libft/ft_putnbr_fd.c
        libft/ft_putnbr_hex.c
        libft/ft_putnbr_hex_long.c
        libft/ft_putnbr_hex_long_upper.c
        libft/ft_putnbr_hex_upper.c
        libft/ft_putnbr_uns.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclen.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdel1join.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strrev.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/libft.h
        src/corewar.c
        src/error.c
        src/init_cursors.c src/operations/live.c src/operations/ld.c
		src/operations/st.c src/operations/add.c src/operations/aff.c
		src/operations/and.c src/operations/fork.c src/operations/ldi.c
		src/operations/lfork.c src/operations/lld.c src/operations/lldi.c
		src/operations/or.c src/operations/sti.c src/operations/sub.c
		src/operations/xor.c src/operations/zjmp.c)
