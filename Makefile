# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 13:23:49 by jpuronah          #+#    #+#              #
#    Updated: 2022/03/10 11:20:40 by twileniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = *.c
OBJS = *.o
HEADER = fillit.h
FLAGS = -Wall -Wextra -Werror
CFLAGS = -Wconversion

LIBFT = libft/

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRC) -I $(HEADER) -L. libft/libft.a

test:
	gcc -o $(NAME) $(SRC) $(GNL) -I $(HEADER) -L. libft/libft.a

filecheck:	test
	bash /Users/teikowilenius/HIVE/42FileChecker/42FileChecker.sh

leaks:	fclean
	make -C $(LIBFT)
	gcc -o $(NAME) $(SRC) $(GNL) -I $(HEADER) -L. libft/libft.a -fsanitize=address

noflags: fclean
	make -C $(LIBFT)
	gcc -o $(NAME) $(SRC) $(GNL) -I $(HEADER) -L. libft/libft.a

allflags: fclean
	make -C $(LIBFT)
	gcc $(FLAGS) $(CFLAGS) -o $(NAME) $(SRC) $(GNL) -I $(HEADER) -L. libft/libft.a

color: fclean
	make -C $(LIBFT)
	gcc $(FLAGS) $(CFLAGS) -o $(NAME) $(SRC) $(GNL) -I $(HEADER) -L. libft/libft.a

clean:
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: clean fclean re all noflags allflags
