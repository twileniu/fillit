/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:19:57 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/21 22:08:29 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = ft_strlen(needle);
	if (n == 0)
		return ((char *)haystack);
	while (*haystack && i + n <= len)
	{
		if (!ft_memcmp(haystack, needle, n))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
