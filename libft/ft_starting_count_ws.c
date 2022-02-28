/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starting_count_ws.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:41:34 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/21 18:37:06 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_starting_count_ws(char const *s, int (*f)(int))
{
	size_t	i;

	i = 0;
	while (f(s[i]))
		i++;
	return (i);
}
