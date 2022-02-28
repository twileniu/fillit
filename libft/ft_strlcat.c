/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:31:44 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/22 15:36:08 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	k;
	size_t	len_src;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	if (dstsize < len_dest)
		len_src += dstsize;
	else
		len_src += len_dest;
	k = 0;
	while (src[k] != '\0' && (len_dest + k) < dstsize - 1)
	{
		dst[len_dest + k] = src[k];
		k++;
	}
	dst[len_dest + k] = '\0';
	return (len_src);
}
