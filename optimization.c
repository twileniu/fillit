/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:20:52 by jpuronah          #+#    #+#             */
/*   Updated: 2022/03/10 15:25:41 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// TÄÄLLÄ EHKÄ LEAK, JOS SE LUKEE TETRIN ULKOPUOLELT //
static size_t	ft_tetriheight(char *tetri)
{
	size_t	i;
	size_t	height;

	i = 0;
	height = 0;
	while (tetri[i])
	{
		//if (tetri[i] >= 'A' && (i < 9 && tetri[i + 9] >= 'A') || (i < 9	<<<<<<<<------ toimimaton kokeilu
		//	&& tetri[i + 10] >= 'A') || (i < 8 && tetri[i + 11] >= 'A'))	<<<<<<<<------ toimimaton kokeilu
		if (tetri[i] >= 'A' && (tetri[i + 9] >= 'A' || tetri[i + 10] >= 'A'
				|| tetri[i + 11] >= 'A'))
			height = 3;
		++i;
	}
	return (height);
}

static ssize_t	ft_empty_check(char *board, char c)
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
			if (i < g_size * (g_size + 1) - 1 && board[i + 1] == c)
					++sidecount;
			if (i > (g_size - 1) && board[i - g_size - 1] == c)
				++sidecount;
			if (i < (g_size * (g_size + 1) - g_size)
				&& board[i + g_size + 1] == c)
				++sidecount;
		}
		++i;
	}
	if (sidecount >= 6)
		return (1);
	else
		return (0);
}

/*static size_t ft_count_empties(char *rest_board)
{
	size_t	count;
	size_t	pala;
	size_t i;
	
	count = 0;
	i = 0;
	pala = 0;
	while(rest_board[i] != '\0') 
	{
		//printf("%s\n", rest_board);
		if(rest_board[i] == '.' && rest_board[i + 1] == '.') 
		{
			count++;
			//printf("viereinen: %zu\n", count);
		}	
		if(rest_board[i] == '.' && rest_board[i + g_size + 1] == '.')
		{
			count++;
			//printf("alempi: %zu\n", count);
		}	
		if(count >= 4)	
		{
			pala++;
			count -= 4;
		}
		i++;	
	}	
	//printf("%zu\n", pala);
	return(pala);
}*/

size_t	ft_optimization(char *board, char *tetri, size_t i)
{
	size_t	height;
	size_t	j;

	height = ft_tetriheight(tetri);
	j = 0;
	//printf("%s\n", &board[i]);
	//printf("%d\n", (char)tetri[j + 1]);
	//ft_count_empties(&board[i]);
	//printf("%zu\n---------------------\n", ((g_npieces + 'A') - tetri[j])  * 4);
	while ((tetri && board[i] >= 'A' )|| board[i] == '\n'
		|| (tetri[j + 1] >= 'A' && board[i + 1] == '\n') 
		|| (tetri[j + 1] >= 'A' && tetri[j + 2] >= 'A' && board[i + 2] == '\n')
		|| (tetri[j + 1] >= 'A' && tetri[j + 2] >= 'A' && tetri[j + 3] >= 'A' && board[i + 3] == '\n')
		|| (tetri[j + 6] >= 'A' && (board[i + 1] == '\n' || board[i + g_size + 2] >= 'A' ))
		|| (tetri[j + 7] >= 'A' && (board[i + 1] == '\n' || board[i + g_size + 2] >= 'A' ))
		|| (tetri[j + 1] >= 'A' && (board[i + 1] == '\n' || board[i + 1] >= 'A' ))
		|| (tetri[j + 4] >= 'A' && board[i - 1] == '\n')
        || (tetri[j + 3] >= 'A' && board[i - 2] == '\n')
        || (tetri[j + 5] >= 'A' && board[i + g_size + 1] >= 'A')
		|| (board[i + 1] >= 'A' && board[i + g_size + 1] >= 'A') 
        || (tetri[j + 10] >= 'A' && board[i + (2 * (g_size + 1))] >= 'A')
		|| (ft_empty_check(&board[i], '.') < 1 && board[i] != '\0')
		|| (tetri[j + 11] >= 'A' && ((board[i + (2 * (g_size + 1)) + 1] >= 'A') || (board[i + (2 * (g_size + 1)) + 1] == '\n'))))
		++i;
	//while(ft_empty_check(&board[i], '.') < 1 && board[i] != '\0')	
	//	++i;
	if (height == 3 && i >= ((g_size * (g_size + 1)) - (2 * (g_size + 1))))
		i += 2 * (g_size + 1);
	return (i);
}
