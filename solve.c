/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:09:20 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/16 18:32:38 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static ssize_t	ft_placement_check(char *board, char c, size_t size)
{
	size_t	i;
	size_t	sidecount;

	i = 0;
	sidecount = 0;
	while (board[i] != '\0')
	{
		if (board[i] == c)
		{
			if (i > 0 && board[i - 1] == c)
				++sidecount;
			if (i < size * (size + 1) - 1 && board[i + 1] == c)
				++sidecount;
			if (i > (size - 1) && board[i - size - 1] == c)
				++sidecount;
			if (i < (size * (size + 1) - size)
				&& board[i + size + 1] == c)
				++sidecount;
		}
		++i;
	}
	if (sidecount == 6 || sidecount == 8)
		return (1);
	else
		return (0);
}

static void	ft_clear_previous(char *board, ssize_t c)
{
	ssize_t	i;

	i = 0;
	while (board[i] != '\0')
	{
		if (board[i] == c)
			board[i] = '.';
		++i;
	}
}

static size_t	ft_adjust_position(char *piece, size_t i, size_t j, size_t size)
{
	if (piece[j] == '\n' && size == 3)
		i--;
	if (piece[j] == '\n' && size != 3 && size != 4)
		i += (size - 4);
	return (i);
}

static size_t	ft_place(char *board, char *tetri, size_t i, size_t size)
{
	size_t		j;
	char		letter;
	size_t		count;

	j = 0;
	count = 0;
	letter = tetri[j];
	while (tetri[j])
	{
		i = ft_adjust_position(tetri, i, j, size);
		if (i > (size * (size + 1)) || board[i] == '\0')
			break ;
		if (board[i] == '.' && tetri[j] >= 'A')
		{
			board[i] = tetri[j];
			++count;
		}
		i++;
		j++;
		if (count == 4)
			break ;
	}
	if (ft_placement_check(board, letter, size))
		return (1);
	return (0);
}

char	*ft_solve(char *board, char **tetrilist, size_t size)
{
	size_t	i;

	i = 0;
	if (!tetrilist[0])
		return (board);
	while (tetrilist[0] && tetrilist[0][0] < 'A')
		tetrilist[0]++;
	while (board[i])
	{
		i = ft_optimization(board, tetrilist[0], i, size);
		if (ft_place(board, *tetrilist, i, size) != 1)
			ft_clear_previous(&board[i], *tetrilist[0]);
		else if (!ft_solve(board, &tetrilist[1], size))
			ft_clear_previous(&board[i], *tetrilist[0]);
		else
			return (board);
		++i;
	}
	return (NULL);
}
