/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:30:27 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/23 01:57:42 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = ft_memalloc(len + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, (char *)&(s[start]), len);
	return (str);
}
