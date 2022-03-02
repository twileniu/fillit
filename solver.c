/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:43:06 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/02 14:37:26 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char *ft_board_size()
{
	char *board;
	int i;

	g_size = 0;
	while (g_size * g_size < g_npieces * 4)
		++g_size;
	board  = (char *)malloc(sizeof(char) *  g_size * (g_size +1) + 1);
	return(board);
}

static int ft_checkplacement(char *board, int j)
{
	int i;
	int adj;
	int count;

	count = 0;
	i = 0;
	adj = 0;
	while(board[i] != '\0')
	{
		if(board[i] == j + 65 && board[i - 1] == j + 65 && count > 0)
			++adj;
		if(board[i] == j + 65 && board[i + 1] == j + 65 && count < (g_size * (g_size + 1)))
			++adj;
		if(board[i] == j + 65 && board[i - (g_size + 1)] == j + 65 && count > g_size)
			++adj;
		if(board[i] == j + 65 && board[i + (g_size + 1)] == j + 65 && count < (g_size * (g_size + 1) - 4))
			++adj;
		++i;
		++count;
	}
	//printf("%d\n", adj);
	if (!(adj == 6 || adj == 8))
		return (0);
	else
		return (1);
}

char	*ft_clear(char *board, int j)
{
	int i;

	i = 0;
	while (board[i] != '\0')
	{
		if (board[i] >= j + 65)
			board[i] = '.';
		++i;	
	}
	//printf("%s\n", board);		
	return (board);
}


static int ft_algo(char *board, char **tetrilist, int z, int y)
{
	//printf("%s\n", board);
	int	i;
	int j;
	int k;

	i = 0;
	j = y;
	k = z;
	//printf("%d\n", j);
	while (tetrilist[j][i] < 'A')
		i++;
	//printf("%s\n", tetrilist[j]);
	//printf("TEST\n");
	while (k < g_size * (g_size + 1))
	{
		//printf("TEST\n");
		if (board[k] == '.' && tetrilist[j][i] >= 'A')
			board[k] = tetrilist[j][i];
		if (i % (g_size + 1) != 0 && tetrilist[j][i] == '\n')
			++i;
		k++;
		i++;
	}
	printf("%d\n", g_size);
	if (k > 3 && k > g_size * (g_size + 1) + 1)
	{
		g_size++;
		z = 0;
		y = 0;
		ft_algo(board, tetrilist, z, y);
	}
	printf("%s\n", board);
	if (ft_checkplacement(board, j) == 0)
	{
		ft_clear(board, j);
		//printf("%s\n", board);
		ft_algo(board, tetrilist, z + 1, y);
		return(0);
	}
	else
	{
		ft_algo(board, tetrilist, z, y + 1);
		return(1);
	}
		

}

void	ft_solver(char **tetrilist)
{
	char *board;
	size_t i;
	int		k;
	int		y;

	k = 0;
	y = 0;
	board = ft_board_size();
	if(!board)
		ft_error();
	i = 0;
	while (1)
	{
		while (i < g_size * (g_size + 1))
		{
			board[i] = '.';
			if (i % (g_size + 1) == g_size)
				board[i] = '\n';
			++i;	
		}
		board[i] = '\0';
		i = 0;
		if (!ft_algo(board, tetrilist, k, y))
		{	
			g_size++;
			free(board);
			board = ft_board_size();
		}
	}
	free(board);
	k = 0;
	while (tetrilist[k] != NULL)
	{
		////printf("%s\n", tetrilist[k]);
		free(tetrilist[k]);
		k++;
	}
	free(tetrilist);
}
