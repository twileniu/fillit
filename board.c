/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:29:51 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/11 14:35:42 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_empty_board(char *board)
{
	size_t	i;

	i = 0;
	while (i < (g_size * (g_size + 1)))
	{
		board[i] = '.';
		if (i % (g_size + 1) == g_size)
			board[i] = '\n';
		i++;
	}
	board[i] = '\0';
	return (board);
}

static char	*ft_set_board(char *board, char **tetrilist)
{
	ssize_t	i;
	ssize_t	count;
	char	*output;

	count = 0;
	while (1)
	{
		i = 0;
		count++;
		ft_empty_board(board);
		output = ft_solve(board, tetrilist);
		if (!output)
		{
			g_size++;
			free(board);
			board = ft_strnew(g_size * (g_size + 1) + 1);
		}
		else
			return (board);
	}
	return (NULL);
}

void	ft_board(char **tetrilist)
{
	char	*board;

	g_size = 0;
	while (g_size * g_size < g_npieces * 4)
		g_size++;
	board = ft_strnew(g_size * (g_size + 1) + 1);
	if (!tetrilist || !board)
		ft_error();
	board = ft_set_board(board, tetrilist);
	if (board)
	{
		ft_putstr(board);
		printf("%zu\n", g_optim);
		free(board);
		exit(EXIT_SUCCESS);
	}
	else
		ft_error();
}
