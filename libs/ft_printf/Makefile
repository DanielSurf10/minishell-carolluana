# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 15:13:33 by cshingai          #+#    #+#              #
#    Updated: 2024/01/11 17:30:54 by cshingai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
FLAGS	= -Wall -Wextra -Werror -c
INCLUDE	= include

SRC	= ${addprefix src/, \
			ft_printf.c \
			ft_putchar_fd.c \
			ft_puthex.c \
			ft_putnbr_dec.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strlen.c \
		}
OBJ	= ${SRC:src/%.c=obj/%.o}
SRC_BONUS	= ${addprefix src_bonus/, \
				ft_printf_bonus.c \
				ft_putchar_fd_bonus.c \
				ft_puthex_bonus.c \
				ft_putnbr_dec_bonus.c \
				ft_putnbr_fd_bonus.c \
				ft_putstr_fd_bonus.c \
				ft_strlen_bonus.c \
			}
OBJ_BONUS	= ${SRC_BONUS:src_bonus/%.c=obj/%.o}

all: ${NAME}
${NAME}: ${OBJ}
bonus: ${OBJ_BONUS}

obj/%.o: src/%.c
	$(shell if [ ! -d obj ]; then mkdir -p obj; fi)
	${CC} ${FLAGS} -I ${INCLUDE} $< -o $@
	@ar rcs ${NAME} $@

obj/%.o: src_bonus/%.c
	$(shell if [ ! -d obj ]; then mkdir -p obj; fi)
	${CC} ${FLAGS} -I ${INCLUDE} $< -o $@
	@ar rcs ${NAME} $@

clean:
	rm -rf obj

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
