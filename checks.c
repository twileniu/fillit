/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:16:19 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/16 15:58:42 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_characters(char *pieces)
{
	size_t	i;
	size_t	tag;
	size_t	dot;
	size_t	new_lines;

	i = 0;
	dot = 0;
	tag = 0;
	new_lines = 0;
	while (pieces[i])
	{
		if (pieces[i] == '.')
			++dot;
		if (pieces[i] == '#')
			++tag;
		if (pieces[i] == '\n')
			++new_lines;
		++i;
	}
	if (new_lines == 0 || tag == 0 || dot == 0)
		ft_error();
	if ((new_lines + 1) % 5 != 0 || tag % 4 != 0 || dot % 12 != 0)
		ft_error();
	if (((new_lines + 1) / 5) > 26)
		ft_error();
}

static void	ft_check_line_len(char *pieces)
{
	size_t	len;
	size_t	line_count;
	size_t	i;

	line_count = 0;
	i = 0;
	len = 0;
	while (pieces[i])
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
	}
}

static size_t	ft_check_adj(char *pieces, size_t i, size_t adj, size_t count)
{
	if (count > 0 && pieces[i] == '#' && pieces[i - 1] == '#')
		++adj;
	if (count < 20 && pieces[i] == '#' && pieces[i + 1] == '#')
		++adj;
	if (count > 4 && pieces[i] == '#' && pieces[i - 5] == '#')
		++adj;
	if (count < 16 && pieces[i] == '#' && pieces[i + 5] == '#')
		++adj;
	return (adj);
}

static void	ft_adjacent(char *pieces)
{
	size_t	i;
	size_t	adj;
	size_t	count;

	count = 0;
	i = 0;
	adj = 0;
	while (pieces[i])
	{
		adj = ft_check_adj(pieces, i, adj, count);
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
