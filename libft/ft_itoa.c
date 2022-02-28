/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:21:08 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/23 11:20:10 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy_numbers(char *str, unsigned int number, long int len)
{
	while (number > 0)
	{
		str[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (str);
}

static long int	ft_len(int n)
{
	int					len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*str;
	long int			len;
	unsigned int		number;
	int					sign;

	sign = 1;
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * ((unsigned long)len + 1));
	if (!(str))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = (unsigned int)(n * -1);
		str[0] = '-';
	}
	else
		number = (unsigned int)n;
	str = ft_copy_numbers(str, number, len);
	return (str);
}
