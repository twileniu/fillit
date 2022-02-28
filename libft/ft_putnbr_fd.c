/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:47:33 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/23 21:28:42 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	nbr;

	nbr = n;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{	
		if (nbr < 0)
		{
			ft_putchar_fd('-', fd);
			nbr *= -1;
		}
		if (nbr < 10)
		{
			ft_putchar_fd(nbr + 48, fd);
		}
		else
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putnbr_fd(nbr % 10, fd);
		}
	}
}
