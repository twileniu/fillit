#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

int g_npieces;
int g_size;

char    *ft_reader(char *argv);
void    ft_error(void);
void    ft_checks(char *pieces);
char    **ft_separate(char *pieces);
void	ft_solver(char **tetrilist);

#endif
