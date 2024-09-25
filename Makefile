# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 17:34:18 by cshingai          #+#    #+#              #
#    Updated: 2024/09/25 19:54:07 by cshingai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Werror -Wextra
LIBFT = libs/libft
LIBS = $(LIBFT)/libft.a
HEADERS = -I ./include

SRCS = ${addprefix srcs/, \
					main.c \
					metachar.c \
					list.c \
				 }

OBJ = $(SRCS:srcs/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
			@cc $(FLAGS) $(HEADERS) $(OBJ) -lreadline -o $@
			@echo "compiling $(NAME)"

obj/%.o: srcs/%.c
			@mkdir -p obj
			@cc $(FLAGS) $(HEADERS) -c $< -o $@
			@echo "compiling $(notdir $<)"

clean:
			@echo "removing object files"
			@rm -rf $(OBJ)

fclean: clean
			@echo "removing executables"
			@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
