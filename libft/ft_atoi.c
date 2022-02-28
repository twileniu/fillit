/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:16:08 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/22 16:27:31 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	int	num;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\t') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		num *= 10;
		num += ((int)str[i] - 48);
		i++;
	}
	return (num * sign);
}
