/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twileniu <twileniu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:33:09 by twileniu          #+#    #+#             */
/*   Updated: 2022/02/28 14:28:55 by twileniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_bzeros(void *s, size_t n)
{
    size_t    i;

    i = 0;
    while (i < n)
    {
        ((char *)s)[i] = 0;
        i++;
    }
}

void    *ft_memallocs(size_t size)
{
    void    *mem;

    mem = (void *)malloc(size);
    if (!mem)
        return (NULL);
    ft_bzeros(mem, size);
    return (mem);
}

char    *ft_strnews(size_t size)
{
    size_t    i;
    char    *string;

    string = ft_memallocs(size + 1);
    if (!string)
        return (NULL);
    i = 0;
    while (i < size)
        string[i++] = '\0';
    return (string);
}

char *ft_reader(char *argv)
{
	int fd;
	char buf;
	char *pieces;
	size_t n_bytes;
	size_t i;

	buf = '\0';
	pieces = NULL;
	fd = open(argv, O_RDONLY);
	n_bytes = read(fd, &buf, 1);
	i = 0;
	while(n_bytes == 1)
	{
		n_bytes = read(fd, &buf, 1);
		++i;
	}
	//printf("%zu", i);
	pieces = ft_strnews(i);
	if(!pieces)
		ft_error();
	close(fd);
	fd = open(argv, O_RDONLY);
	n_bytes = read(fd, &buf, 1);
	i = 0;
	while(n_bytes > 0)
	{
		pieces[i++] = buf;
		n_bytes = read(fd, &buf, 1);
	}
	pieces[i] = '\0';
	close(fd);
	return (pieces);
}