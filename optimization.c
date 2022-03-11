/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:20:52 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/11 14:06:15 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
static size_t	ft_tetriheight(char *tetri)
{
	size_t	i;
	size_t	height;

	i = 0;
	height = 0;
	if (tetri[0] >= 'A' && ((tetri[3] >= 'A' || tetri[7])
			|| (tetri[5] >= 'A' && tetri[6]) || (tetri[4] >= 'A' && tetri[5])))
		height = 2;
	if (tetri[0] >= 'A' && (tetri[9] >= 'A' || tetri[10] >= 'A'
			|| tetri[11] >= 'A'))
		height = 3;
	++i;
	if (tetri[0] >= 'A' && tetri[15] >= 'A')
		height = 4;
	if (tetri[0] >= 'A' && tetri[1] >= 'A' && tetri[2] && tetri[3] >= 'A')
		height = 1;
	if (height == 2 && (tetri[0] >= 'A' && tetri[1] >= 'A'
			&& tetri[5] >= 'A' && tetri[6] >= 'A'))
		height = 5;
	return (height);
}*/

static size_t	ft_tetriheight(char *tetri)
{
	size_t	height;
	size_t	t_len;

	////printf("height\n");
	////printf("%s\n", tetri);
	t_len = ft_strlen(tetri);
	////printf("%zU\n", t_len);
	height = 0;
	if (t_len > 7 && ((tetri[2] >= 'A' || tetri[7] >= 'A') || (tetri[5] >= 'A' && tetri[6] >= 'A') || (tetri[6] >= 'A' && tetri[7] >= 'A')))
		height = 2;
	if (t_len > 10 && (tetri[9] >= 'A' || tetri[10] >= 'A' || tetri[11] >= 'A'))
		height = 3;
	if (t_len > 16 && tetri[16] >= 'A')
		height = 4;
	if (tetri[1] >= 'A' && tetri[2] && tetri[3] >= 'A')
		height = 1;
	if (height == 2 && tetri[0] >= 'A' && tetri[1] >= 'A' && tetri[5] >= 'A' && tetri[6] >= 'A')
		height = 5;
	//printf("%zu\n", height);
	//printf("%s\n", tetri);
	return (height);
}

static int ft_tetriwidth(char *tetri, size_t height)
{
    int width;

    width = 0;
	////printf("witdht\n");
    if(height == 3)
    {
        if(tetri[0] >= 'A' && (tetri[10] >= 'A'
            || tetri[11] >= 'A'))
            width = 2;
        if(tetri[0] >= 'A' && (tetri[9] >= 'A'  || tetri[4] >= 'A'))
            width = -2;
    }
    if(height == 2)
    {
        if(tetri[0] >= 'A' && ((tetri[3] >= 'A' || tetri[7]) || (tetri[5] >= 'A' && tetri[6])))
            width = 3;
        if(tetri[0] >= 'A' && (tetri[4] >= 'A' && tetri[5]))
            width = -3;
    }
    if (height == 5)
        width = 2;
    return(width);
}

/*static size_t	ft_tetriheight2(char *tetri, size_t height)
{
	size_t	i;

	i = 0;
	while (tetri[i])
	{
		if (tetri[i] >= 'A' && ((tetri[i + 3] >= 'A' || tetri[i + 7]) || (tetri[i + 5] >= 'A' && tetri[i + 6]) || (tetri[i + 4] >= 'A' && tetri[i + 5])))
			height = 2;
		++i;
	}
	return (height);
}*/

/*static size_t	ft_tetriheight3(char *tetri, size_t height)
{
	size_t	i;

	i = 0;
	while (tetri[i])
	{
		if (tetri[0] >= 'A' && tetri[1] >= 'A' && tetri[2] && tetri[3] >= 'A'
			height = 1;
		++i;
	}
	return (height);
}*/

/*
static ssize_t	ft_empty_check(char *board, char c, size_t j)
{
	size_t	i;
	size_t	sidecount;
	size_t	board_len;

	i = 0;
	sidecount = 0;
	board_len = g_size * (g_size + 1);
	// //printf("%s\n", board);
	// //printf("empty\n");
	// //printf("%zu\n", j);
	while (board[i] != '\0')
	{
		////printf("%c\n", board[i]);
		if (board[i] == c)
		{
			////printf("dot\n");
			if (i > 0 && board[i - 1] == c)
				++sidecount;
			if (i < board_len - 1 && board[i + 1] == c)
				++sidecount;
			if (i > (g_size - 1) && board[i - g_size - 1] == c)
				++sidecount;
			if (i < (board_len - j) && board[i + g_size + 1] == c)
				++sidecount;
		}
		++i;
	}
	if (sidecount >= 6)
		return (1);
	else
		return (0);
}*/

/*size_t	ft_opti2(char **tetrilist)
{
	size_t	i;
	size_t	h1;
	size_t	h4;

	i = 0;
	h1 = 0;
	h4 = 0;
	while (tetrilist != NULL)
	{
		if (ft_tetriheight(tetrilist[i]) == 4)
			++h4;
		if (ft_tetriheight(tetrilist[i]) == 1)
			++h1;
	}
	if (g_npieces == 4 && h1 > 0 && h4 > 0)
		return (0);
	else
		return (1);
}*/

size_t	ft_optimization(char *board, char *tetri, size_t i)
{
	size_t	height;
	int		width;
	size_t	line;
	size_t	board_len;

	height = 0;
	width = 0;
	height = ft_tetriheight(tetri);
	width = ft_tetriwidth(tetri, height);
	board_len = g_size * (g_size + 1);
	//printf("%s\n", tetri);
	//printf("%zu:\n%s\n", i, board);
	//printf("%zu\n", board_len);
	////printf("opti\n");
	if (height == 4 && i >= (board_len - (3 * (g_size + 1))))
		i += 3 * (g_size + 1);
	if (height == 3 && i >= (board_len - (2 * (g_size + 1))))
		i += 2 * (g_size + 1);
	if (height == 2 && i >= (board_len - (g_size + 1)))
		i += (g_size + 1);
	if (i > board_len - 2)
		i = board_len - 2;
	//printf("len :%zu\n", board_len);
	//printf("len - 2: %c\n", board[board_len - 2]);
	//printf("optim: %zu\n", g_optim++);
	while ((tetri && board[i] >= 'A') || board[i] == '\n'
		|| (i > (board_len - 4)
		|| (i < board_len - 1 && tetri[1] >= 'A' && board[i + 1] == '\n')
		|| (i < board_len - 2 && tetri[1] >= 'A' && tetri[2] >= 'A' && board[i + 2] == '\n')
		|| (i < board_len - 3 && tetri[1] >= 'A' && tetri[2] >= 'A' && tetri[3] >= 'A' && board[i + 3] == '\n')
		|| (i < board_len - 1 && tetri[1] >= 'A' && (board[i + 1] == '\n' || board[i + 1] >= 'A' ))
		|| (i > 2 && tetri[3] >= 'A' && board[i - 2] == '\n')
		|| (i > 1 && tetri[4] >= 'A' && board[i - 1] == '\n')
		|| (i < (board_len - 4) && height == 1 && (board[i + 1] >= 'A' || board[i + 2] >= 'A' || board[i + 3] >= 'A'))
		|| (i < (board_len - (g_size + 1)) && tetri[5] >= 'A' && board[i + g_size + 1] >= 'A')
		|| (i < board_len - (g_size + 1) && (board[i + 1] >= 'A' && board[i + g_size + 1] >= 'A'))
		|| (i < (board_len - (g_size + 1)) && tetri[6] >= 'A' && (board[i + 1] == '\n' || board[i + g_size + 2] >= 'A' ))
		|| (i < (board_len - (g_size + 1)) && tetri[7] >= 'A' && (board[i + 1] == '\n' || board[i + g_size + 2] >= 'A' ))
		|| (i < (board_len - (g_size + 1)) && height == 2 && (board[i + 2] >= 'A' && board[i + g_size + 3] >= 'A'))
		|| (i < (board_len - (2 * (g_size + 1))) && tetri[10] >= 'A' && board[i + (2 * (g_size + 1))] >= 'A')
		|| (i < (board_len - (2 * (g_size + 1))) && (tetri[11] >= 'A' && ((board[i + (2 * (g_size + 1)) + 1] >= 'A') || (board[i + (2 * (g_size + 1)) + 1] == '\n'))))))
		{
			if (i > board_len - 1)
				break ;
			//printf("%c, %zu\n", board[i], i);
			++i;
			//printf("%c, %zu\n", board[i], i);
		}
		//|| (i < (board_len - (2 * (g_size + 1))) && (tetri[11] >= 'A' && ((board[i + (2 * (g_size + 1)) + 1] >= 'A') || (board[i + (2 * (g_size + 1)) + 1] == '\n'))))))
		//|| (ft_empty_check(&board[i], '.', i) < 1 && board[i] != '\0'))
			////printf("%zu\n", i++);
	line = i / g_size;
	/*if (height == 2 && width == 3 && board[i + 1] == '\n')
        i += 2;
    if (height == 2 && width == 3 && board[i + 2] == '\n')    
        i += 3;
    if (height == 3 && width == 2 && board[i + 1] == '\n')
        i += 2;
    if (height == 2 && width == -3 && (board[i - 1] == '\n' ||  board[i + g_size] == '\n' ))    
        i += 1;
    if (height == 3 && width == -2 && (board[i - 1] == '\n' || board[i + g_size] == '\n'))
        i += 1;
    if (height == 3 && width == -2 && (board[i - 1] == '\n' ||  board[i + g_size] == '\n' ))
        i += 1;*/
	//if (height == 1 && g_size % (i + 1) > (g_size - 4))
	//	i += g_size - 4;


	// || (i < board_len - 1 && tetri[1] >= 'A' && board[i + 1] == '\n')
	// 	|| (i < board_len - 2 && tetri[1] >= 'A' && tetri[2] >= 'A' && board[i + 2] == '\n')
	// 	|| (i < board_len - 3 && tetri[1] >= 'A' && tetri[2] >= 'A' && tetri[3] >= 'A' && board[i + 3] == '\n')
	// 	|| (i < board_len - 1 && tetri[1] >= 'A' && (board[i + 1] == '\n' || board[i + 1] >= 'A' ))
	// 	|| (i > 2 && tetri[3] >= 'A' && board[i - 2] == '\n')
	// 	|| (i > 1 && tetri[4] >= 'A' && board[i - 1] == '\n')
	// 	|| (height == 1 && (board[i + 1] >= 'A' || board[i + 2] >= 'A' || board[i + 3] >= 'A'))
	// 	|| (tetri[10] >= 'A' && board[i + (2 * (g_size + 1))] >= 'A')
	// 	|| (i < board_len - (g_size + 1) && (board[i + 1] >= 'A' && board[i + g_size + 1] >= 'A'))
	// 	|| (i < (g_size + 1) && tetri[5] >= 'A' && board[i + g_size + 1] >= 'A')
	// 	|| (i < (g_size + 2) && tetri[6] >= 'A' && (board[i + 1] == '\n' || board[i + g_size + 2] >= 'A' ))
	// 	|| (i < (g_size + 2) && tetri[7] >= 'A' && (board[i + 1] == '\n' || board[i + g_size + 2] >= 'A' ))
	// 	|| (i < (g_size + 3) && height == 2 && (board[i + 2] >= 'A' && board[i + g_size + 3] >= 'A'))
	// 	|| (tetri[11] >= 'A' && ((board[i + (2 * (g_size + 1)) + 1] >= 'A') || (board[i + (2 * (g_size + 1)) + 1] == '\n'))))
	return (i);
}
