# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 18:04:45 by twileniu          #+#    #+#              #
#    Updated: 2021/12/23 21:29:16 by twileniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libft.a
CMP		=	gcc -Wall -Werror -Wextra -c
INC     =	libft.h

SRCS	=	ft_atoi.c \
            ft_memalloc.c \
			ft_putendl.c \
			ft_strcmp.c \
			ft_strmap.c \
			ft_strstr.c \
			ft_bzero.c \
			ft_memccpy.c \
			ft_putendl_fd.c \
			ft_strcpy.c \
			ft_strmapi.c \
			ft_strsub.c \
			ft_ending_count_ws.c \
			ft_memchr.c \
			ft_putnbr.c \
			ft_strdel.c	\
			ft_strncat.c \
			ft_strtrim.c \
			ft_is_whitespace.c \
			ft_memcmp.c \
			ft_putnbr_fd.c \
			ft_strdup.c \
			ft_strncmp.c \
           	ft_tolower.c \
			ft_isalnum.c \
			ft_memcpy.c \
           	ft_putstr.c \
			ft_strequ.c \
			ft_strncpy.c \
			ft_toupper.c \
			ft_isalpha.c \
       	    ft_memdel.c \
	     	ft_putstr_fd.c \
			ft_striter.c \
			ft_strnequ.c \
			ft_isascii.c \
           	ft_memmove.c \
			ft_starting_count_ws.c \
			ft_striteri.c \
			ft_strnew.c \
			ft_isdigit.c \
			ft_memset.c \
			ft_strcat.c \
			ft_strjoin.c \
			ft_strnstr.c \
			ft_isprint.c \
			ft_putchar.c \
			ft_strchr.c \
			ft_strlcat.c \
			ft_strrchr.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_strclr.c \
			ft_strlen.c \
			ft_strsplit.c \
			ft_free_midarray.c
		
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
		@$(CMP) $(SRCS) -I $(INC)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

clean:
		@/bin/rm -f $(OBJS)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

norm:
	norminette *.c
	norminette *.h

.PHONY: all
.PHONY: clean
.PHONY: fclean
.PHONY: re
.PHONY: norm
