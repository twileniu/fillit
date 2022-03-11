/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:18:05 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/11 14:30:32 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_strsub_chr(char const *pieces, size_t start,
size_t len, ssize_t chr)
{
	char	*substr;
	size_t	i;

	if (!pieces)
		return (NULL);
	if (start >= ft_strlen(pieces))
		return (NULL);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && pieces[start] != '\0')
	{
		if (pieces[start] == '#')
			substr[i] = (char)(chr + 65);
		else
			substr[i] = pieces[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_separate(char *pieces)
{
	char	**tetrilist;
	size_t	start;
	ssize_t	j;
	ssize_t	k;

	tetrilist = (char **)malloc(sizeof(char) * g_npieces * 21);
	j = 0;
	k = 0;
	start = 0;
	while (pieces[k] != '\0')
	{
		if (k++ % 20 == 0)
		{
			tetrilist[j] = ft_strsub_chr(pieces, start, 20, j);
			j++;
			start = start + 21;
		}
	}
	tetrilist[j] = NULL;
	free(pieces);
	return (tetrilist);
}
