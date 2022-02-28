/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ending_count_ws.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:42:17 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/21 18:37:43 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ending_count_ws(char const *s, int (*f)(int))
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (s[i])
		i++;
	i--;
	while (f(s[i]))
	{
		i--;
		c++;
	}
	return (c);
}
