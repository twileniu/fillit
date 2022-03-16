# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 13:23:49 by jpuronah          #+#    #+#              #
#    Updated: 2022/03/15 14:15:14 by jpuronah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = *.c
OBJS = *.o
HEADER = fillit.h
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRC) -I $(HEADER) -L. libft/libft.a

clean:
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: clean fclean re all
