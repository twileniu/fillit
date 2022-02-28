/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:08:47 by twileniu          #+#    #+#             */
/*   Updated: 2021/12/23 21:04:14 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_len(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static size_t	ft_wcount(char const *str, char c)
{
	int		i;
	int		check;
	size_t	words;

	i = 0;
	check = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c && !check)
		{
			words++;
			check = 1;
		}
		else if (str[i] == c)
			check = 0;
		i++;
	}
	return (words);
}

static char	**ft_malloc_array(char const *s, char c)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (ft_wcount(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	return (arr);
}

static char	**ft_split_strings(char **arr, char const *s, char c)
{
	size_t		i;
	size_t		j;
	int			check;

	i = 0;
	j = 0;
	check = 0;
	while (s[i])
	{
		if (s[i] != c && !check)
		{
			check = 1;
			arr[j] = ft_memalloc(ft_word_len(&s[i], c) + 1);
			if (arr[j] == NULL)
				return (ft_free_midarray(arr, j - 1));
			ft_strncpy(arr[j], &s[i], ft_word_len(&s[i], c));
			j++;
		}
		else if (s[i] == c)
			check = 0;
		i++;
	}
	arr[j] = 0;
	return (arr);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;

	arr = ft_malloc_array(s, c);
	if (arr == NULL)
		return (NULL);
	arr = ft_split_strings(arr, s, c);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
