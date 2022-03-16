/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:03:06 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/16 21:54:10 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

void	ft_error(void);
void	ft_checks(char *pieces);
void	ft_board(char **tetrilist);
char	*ft_solve(char *board, char **tetrilist, size_t size);
char	**ft_separate(char *pieces);
char	*ft_reader(char *argv);
size_t	ft_optimization(char *board, char *tetri, size_t i, size_t size);
size_t	ft_tetriheight(char *tetri);

#endif
