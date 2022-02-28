/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_midarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:01:46 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/23 21:04:28 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_midarray(char **arr, size_t i)
{
	while (arr[i])
	{
		free(arr[i]);
		i--;
	}
	ft_strdel(arr);
	return (arr);
}
