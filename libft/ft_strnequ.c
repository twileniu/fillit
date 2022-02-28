/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:27:34 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/22 16:28:03 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	if (n == 0)
		return (1);
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0') && (i < n))
		i++;
	if (i == n)
		i--;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}
