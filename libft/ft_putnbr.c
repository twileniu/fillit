/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:39:32 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/23 21:28:14 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	nbr;

	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		nbr = n;
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		if (nbr < 10)
		{
			ft_putchar(nbr + 48);
		}
		else
		{
			ft_putnbr(nbr / 10);
			ft_putnbr(nbr % 10);
		}
	}
}
