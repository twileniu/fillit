/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:18:05 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/03 21:22:32 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_strsub_chr(char const *s, unsigned int start,
size_t len, int chr)
{
	char			*substr;
	unsigned int	i;

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

static char	**ft_split_string(char **tetriminos, char *pieces)
{
	int				linecount;
	unsigned int	start;
	int				j;
	int				k;

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

char	**ft_separate(char *pieces)
{
	char			**tetriminos;
//	int				linecount;
//	unsigned int	start;
//	int				j;
//	int				k;

	tetriminos = (char **)malloc(sizeof(char) * g_npieces * 21);
	/*linecount = 0;
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
	free(pieces); */
	return (ft_split_string(tetriminos, pieces));
}
