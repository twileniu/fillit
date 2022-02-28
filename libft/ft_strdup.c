/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:41:37 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/22 14:06:59 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;

	cpy = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cpy == NULL)
		return (NULL);
	return (ft_strcpy(cpy, (char *)src));
}
