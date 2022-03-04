/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:16:19 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/04 13:08:54 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_characters(char *pieces)
{
	int	i;
	int	new_lines;
	int	tag;
	int	dot;
	int	n_pieces;

	i = 0;
	dot = 0;
	new_lines = 0;
	tag = 0;
	while (pieces[i])
	{
		if (pieces[i] == '.')
			++dot;
		if (pieces[i] == '#')
			++tag;
		if (pieces[i] == '\n')
			++new_lines;
		n_pieces = (new_lines + 1) / 5;
		++i;
	}
	if ((new_lines + 1) % 5 != 0 || tag % 4 != 0 || dot % 12 != 0)
		ft_error();
}

static void	ft_check_line_len(char *pieces)
{
	int	len;
	int	line_count;
	int	i;

	line_count = 0;
	i = 0;
	len = 0;
	while (pieces[i] != '\0')
	{
		len++;
		if (pieces[i] == '\n')
		{
			line_count++;
			if (line_count % 5 != 0)
				if (len != 5)
					ft_error();
			if (line_count % 5 == 0 && pieces[i] != '\n')
				if (len != 1)
					ft_error();
			len = 0;
		}
		i++;
		g_npieces = (line_count + 1) / 5;
	}
}

static int	ft_check_adj(char *pieces, int i, int adj, int count)
{
	if (pieces[i] == '#' && pieces[i - 1] == '#' && count > 0)
		++adj;
	if (pieces[i] == '#' && pieces[i + 1] == '#' && count < 20)
		++adj;
	if (pieces[i] == '#' && pieces[i - 5] == '#' && count > 4)
		++adj;
	if (pieces[i] == '#' && pieces[i + 5] == '#' && count < 16)
		++adj;
	return (adj);	
}

static void	ft_adjacent(char *pieces)
{
	int	i;
	int	adj;
	int	count;

	count = 0;
	i = 0;
	adj = 0;
	while (pieces[i] != '\0')
	{
		adj = ft_check_adj(pieces, i, adj, count);
		/*if (pieces[i] == '#' && pieces[i - 1] == '#' && count > 0)
			++adj;
		if (pieces[i] == '#' && pieces[i + 1] == '#' && count < 20)
			++adj;
		if (pieces[i] == '#' && pieces[i - 5] == '#' && count > 4)
			++adj;
		if (pieces[i] == '#' && pieces[i + 5] == '#' && count < 16)
			++adj;*/
		++i;
		++count;
		if ((i + 1) % 21 == 0)
		{
			if (!(adj == 6 || adj == 8))
				ft_error();
			adj = 0;
			count = 0;
		}
	}
}

void	ft_checks(char *pieces)
{
	ft_characters(pieces);
	ft_check_line_len(pieces);
	ft_adjacent(pieces);
}
