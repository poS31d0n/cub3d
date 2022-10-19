# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pos31d0n <pos31d0n@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 15:19:18 by pos31d0n          #+#    #+#              #
#    Updated: 2022/10/17 14:05:10 by pos31d0n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

MLX		=	mlx/Makefile.gen

SRC 	= src
INC		= inc
OBJ 	= obj
	
SOURCE	=		$(wildcard $(SRC)/*.c)
OBJECT	=		$(patsubst %,$(OBJ)/%, $(notdir $(SOURCE:.c=.o)))

$(NAME)		:	$(OBJECT)
	cc -o $@ $^

$(OBJ)/%.o	:	$(SRC)/%.c
	cc -Wall -Werror -Wextra -I$(INC) -c $< -o $@

###################################################################### 
#																	 #
######################################################################

.PHONY: all clean fclean re

all: $(OBJECT) $(NAME)

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re:			fclean all