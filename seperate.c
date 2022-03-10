/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:18:05 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/09 16:34:48 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_strsub_chr(char const *s, size_t start,
size_t len, ssize_t chr)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		if (s[start] == '#')
			substr[i] = (char)(chr + 65);
		else
			substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_separate(char *pieces)
{
	char	**tetriminos;
	ssize_t	linecount;
	size_t	start;
	ssize_t	j;
	ssize_t	k;

	tetriminos = (char **)malloc(sizeof(char) * g_npieces * 21);
	linecount = 0;
	j = 0;
	k = 0;
	start = 0;
	while (pieces[k] != '\0')
	{
		if (pieces[k] == '\n')
			linecount++;
		if (k++ % 20 == 0)
		{
			tetriminos[j] = ft_strsub_chr(pieces, start, 20, j);
			j++;
			start = start + 21;
		}
	}
	tetriminos[j] = NULL;
	free(pieces);
	return (tetriminos);
}
