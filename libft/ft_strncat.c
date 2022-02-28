/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:33:04 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/27 15:29:55 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2[i])
		return (s1);
	while (s1[j])
		j++;
	while (s2[i] && i < n)
	{
		s1[j + i] = (char)s2[i];
		i++;
	}
	s1[j + i] = '\0';
	return (s1);
}
