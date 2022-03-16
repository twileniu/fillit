/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:29:51 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/16 21:53:20 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_empty_board(char *board, size_t size)
{
	size_t	i;

	i = 0;
	while (i < (size * (size + 1)))
	{
		board[i] = '.';
		if (i % (size + 1) == size)
			board[i] = '\n';
		i++;
	}
	board[i] = '\0';
	return (board);
}

static char	*ft_set_board(char *board, char **tetrilist, size_t size)
{
	ssize_t	i;
	ssize_t	count;
	char	*output;

	count = 0;
	while (1)
	{
		i = 0;
		count++;
		ft_empty_board(board, size);
		output = ft_solve(board, tetrilist, size);
		if (!output)
		{
			size++;
			free(board);
			board = ft_strnew(size * (size + 1) + 1);
		}
		else
			return (board);
	}
	return (NULL);
}

static size_t	ft_if_line(char **tetrilist, size_t n_pieces)
{
	size_t	i;
	size_t	h1;
	size_t	h4;

	i = 0;
	h1 = 0;
	h4 = 0;
	while (tetrilist[i] != NULL)
	{
		while (*tetrilist[i] < 'A')
			++tetrilist[i];
		if (ft_tetriheight(tetrilist[i]) == 1)
			++h1;
		if (ft_tetriheight(tetrilist[i]) == 4)
			++h4;
		++i;
	}
	if (h1 == n_pieces || h4 == n_pieces)
		return (1);
	return (0);
}

size_t	ft_set_size(size_t n_pieces, size_t size)
{
	if (n_pieces == 7)
		size = 7;
	if (n_pieces >= 8 && n_pieces <= 17)
		size = 8;
	if (n_pieces == 17 || (n_pieces > 18))
		size += 1;
	if (n_pieces >= 23 && n_pieces <= 26)
		size = 12;
	return (size);
}

void	ft_board(char **tetrilist)
{
	char	*board;
	size_t	size;
	size_t	n_pieces;

	size = 0;
	n_pieces = 0;
	while (tetrilist[n_pieces] != NULL)
		++n_pieces;
	while (size * size < n_pieces * 4)
		size++;
	if (ft_if_line(tetrilist, n_pieces))
		size = ft_set_size(n_pieces, size);
	board = ft_strnew(size * (size + 1) + 1);
	if (!tetrilist || !board)
		ft_error();
	board = ft_set_board(board, tetrilist, size);
	if (board)
	{
		ft_putstr(board);
		free(board);
		exit(EXIT_SUCCESS);
	}
	else
		ft_error();
}
