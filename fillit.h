/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:03:06 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/10 17:28:58 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

size_t	g_npieces;
size_t	g_size;
size_t	g_optim;

void	ft_error(void);
void	ft_checks(char *pieces);
void	ft_board(char **tetrilist);
char	*ft_solve(char *board, char **tetrilist);
char	**ft_separate(char *pieces);
char	*ft_reader(char *argv);
size_t	ft_optimization(char *board, char *tetri, size_t i);
//size_t	ft_opti2(char **tetrilist);

#endif
