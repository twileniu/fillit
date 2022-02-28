/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:16:19 by twileniu          #+#    #+#             */
/*   Updated: 2022/02/28 15:11:29 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_adjacent(char *pieces)
{

}

void ft_characters(char *pieces)
{
	int i;
	int new_lines;
	int tag;
	int dot;
	int n_pieces;
	
	i = 0;
	dot = 0;
	new_lines = 0;
	tag = 0;
	while (pieces[i])
	{
		if(pieces[i] == '.')
			++dot;
		if(pieces[i] == '#')
			++tag;
		if(pieces[i] == '\n')
			++new_lines;
		n_pieces = (new_lines + 1) / 5;
		//printf("%c\n", pieces[i]);
		++i;
	}
	//printf("i: %d, dot: %d,  nl: %d, tag: %d\n", i, dot, new_lines, tag);
	//printf("%d, %d, %d\n", (new_lines + 1) % 5, (tag % n_pieces), (dot % n_pieces));
	if((new_lines + 1) % 5 != 0 || tag % 4 != 0 || dot  % 12 != 0)
	{
		//printf("TEST\n");
		ft_error();
	}
}

void ft_check_lines(char *pieces)
{
	int index;
	int linecount;


}

void ft_checks(char *pieces)
{

	//ft_adjacent(pieces);
	ft_characters(pieces);
	//ft_check_lines(pieces);

}