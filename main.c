/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:10:11 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/02 11:31:25 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_error(void)
{
	ft_putendl("error");
	exit(1);
}

static void	ft_usage(void)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd("fillit", STDERR_FILENO);
	ft_putstr_fd(" input_file\n", STDERR_FILENO);
}

int	main(int argc, char **argv)
{
	char *pieces;
	char **tetrilist;
	int i = 0;

	pieces = NULL;
	if (argc == 2)
	{
		pieces = ft_reader(argv[1]);
		//printf("%s\n", pieces);
		ft_checks(pieces);
		tetrilist = ft_separate(pieces);
		ft_solver(tetrilist);
	}
	else
		ft_usage();
	return(0);	


}
