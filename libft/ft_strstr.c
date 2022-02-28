/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:25:28 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/21 14:27:26 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n;

	n = ft_strlen(needle);
	if (n == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		if (!ft_memcmp(haystack, needle, n))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
