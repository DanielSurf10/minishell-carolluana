# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 17:34:18 by cshingai          #+#    #+#              #
#    Updated: 2024/10/18 17:14:12 by cshingai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Wextra -Werror -g3
LIBFT = libs/libft
FT_PRINTF = libs/ft_printf
LIBS = $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a
HEADERS = -I $(LIBFT) -I ./include

# source files
SRCS = ${addprefix srcs/, \
			main.c \
			list.c \
			utils.c \
			list_utils.c \
			tokenizer.c \
			tokens2.c \
			validation.c \
			parsing-tree.c \
			env_list.c \
		}

OBJ = $(SRCS:srcs/%.c=obj/%.o)

all: $(NAME)

$(NAME): libft ft_printf ${OBJ}
			@cc $(FLAGS) $(OBJ) $(LIBS) -lreadline -o $@
			@echo "compiling $(NAME)"

# building libraries
libft:
			@make -C $(LIBFT) all

ft_printf:
			@make -C $(FT_PRINTF) all

# compiling objects files
obj/%.o: srcs/%.c ./include/minishell.h
			mkdir -p obj
			@cc $(FLAGS) $(HEADERS) -c $< -o $@
			@echo "compiling objects"

# cleanning up objects files
clean:
			@echo "removing objects"
			@rm -rf $(OBJ)
			@make clean -C $(LIBFT)
			@make clean -C $(FT_PRINTF)

# cleaning up executables
fclean:	clean
			@echo "removing executables"
			@rm -rf $(NAME)
			@echo "removing libs"
			@make fclean -C $(LIBFT)
			@make fclean -C $(FT_PRINTF)
			@echo "everything was removed 🧹🗑️"

re: fclean all

.PHONY: all libft ft_printf clean fclean re
