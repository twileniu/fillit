/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:20:52 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/16 18:03:57 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_tetriheight(char *tetri)
{
	size_t	height;
	size_t	t_len;

	t_len = ft_strlen(tetri);
	height = 0;
	if (t_len > 7 && ((tetri[2] >= 'A' || tetri[7] >= 'A')
			|| (tetri[5] >= 'A' && tetri[6] >= 'A')
			|| (tetri[6] >= 'A' && tetri[7] >= 'A')))
		height = 2;
	if (t_len > 10 && (tetri[9] >= 'A' || tetri[10] >= 'A' || tetri[11] >= 'A'))
		height = 3;
	if (t_len >= 15 && (tetri[15] >= 'A' || tetri[16] >= 'A'
			|| tetri[17] >= 'A' || tetri[18] >= 'A'))
		height = 4;
	if (tetri[0] >= 'A' && tetri[1] >= 'A' && tetri[2] && tetri[3] >= 'A')
		height = 1;
	if (height == 2 && tetri[0] >= 'A' && tetri[1] >= 'A' && tetri[5] >= 'A'
		&& tetri[6] >= 'A')
		height = 5;
	return (height);
}

static size_t	ft_skip(char *board, char *tetri, size_t i, size_t size)
{
	size_t	board_len;

	board_len = size * (size + 1);
	while ((tetri && board[i] >= 'A') || board[i] == '\n'
		|| (i > (board_len - 4))
		|| (i > 1 && tetri[4] >= 'A' && board[i - 1] == '\n')
		|| (i < (board_len - 1) && tetri[1] >= 'A'
			&& (board[i + 1] == '\n' || board[i + 1] >= 'A' ))
		|| (i < (board_len - (size + 1))
			&& tetri[5] >= 'A' && board[i + size + 1] >= 'A')
		|| (i < (board_len - (size + 1)) && tetri[6] >= 'A'
			&& (board[i + 1] == '\n' || board[i + size + 2] >= 'A' ))
		|| (i < (board_len - (size + 1)) && tetri[7] >= 'A'
			&& (board[i + 1] == '\n' || board[i + size + 2] >= 'A' ))
		|| (i < (board_len - (2 * (size + 1))) && tetri[10] >= 'A'
			&& board[i + (2 * (size + 1))] >= 'A'))
	{
		if (i > board_len - 1)
			break ;
		++i;
	}
	return (i);
}

static size_t	ft_count_till_nl(char *board)
{
	size_t	count;

	count = 0;
	while (board && *board != '\n')
	{
		board++;
		count++;
	}
	return (count);
}

static size_t	ft_lineskip(char *board, char *tetri, size_t i, size_t size)
{
	size_t	height;
	size_t	board_len;

	height = ft_tetriheight(tetri);
	board_len = size * (size + 1);
	if (height == 4 && i >= (board_len - (3 * (size + 1))))
		i += 3 * (size + 1);
	if (height == 3 && i >= (board_len - (2 * (size + 1))))
		i += 2 * (size + 1);
	if (height == 2 && i >= (board_len - (size + 1)))
		i += (size + 1);
	if (i < (board_len - 3) && height == 1 && (board[i + 1] == '\n'
			|| board[i + 2] == '\n' || board[i + 3] == '\n'))
		i += (ft_count_till_nl(&board[i]) + 1);
	if (i < (board_len - (size + 1)) && height == 2
		&& (board[i + 2] >= 'A' && board[i + size + 3] >= 'A'))
		++i;
	if (i > board_len - 2)
		i = board_len - 2;
	return (i);
}

size_t	ft_optimization(char *board, char *tetri, size_t i, size_t size)
{
	i = ft_lineskip(board, tetri, i, size);
	i = ft_skip(board, tetri, i, size);
	return (i);
}
