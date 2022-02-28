/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:35:42 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/23 11:02:04 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	size_t			size;
	size_t			start;
	size_t			ws;

	if (!s)
		return (NULL);
	size = (size_t)ft_strlen(s);
	ws = ft_starting_count_ws(s, ft_is_whitespace);
	start = ws;
	if (size > ws)
		ws += ft_ending_count_ws(s, ft_is_whitespace);
	size -= ws;
	str = ft_memalloc(size + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s + start, size);
	return (str);
}
