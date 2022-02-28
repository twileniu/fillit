/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:04:44 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/22 14:05:53 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*r;

	r = (void *)malloc(size);
	if (r == NULL)
		return (NULL);
	ft_bzero(r, size);
	return (r);
}
