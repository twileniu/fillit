/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:53:03 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/21 17:15:05 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	cdest = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dst);
}
