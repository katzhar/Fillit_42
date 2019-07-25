# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aernie <aernie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 16:31:58 by aernie            #+#    #+#              #
#    Updated: 2019/07/25 17:23:24 by aernie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = fillit

SRC_PATH = ./
OBJ_PATH = ./objects/
INC_PATH = ./fillit.h
LIB_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

SRC_NAME =	main.c valid.c list.c coordinate.c map.c move.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fillit.h


all: $(NAME)

$(NAME): $(OBJ)
	make lib_refresh
	gcc -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	gcc -Wall -Werror -Wextra $(INC) -o $@ -c $<

lib_refresh:
	make -C $(LIB_PATH)

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	/bin/rm -rf $(OBJ_PATH)
	make clean -C $(LIB_PATH)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all