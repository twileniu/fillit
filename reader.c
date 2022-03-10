/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:33:09 by twileniu          #+#    #+#             */
/*   Updated: 2022/03/04 14:29:19 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_read_to_fill(char *pieces, int fd, char *argv)
{
	size_t	i;
	ssize_t	n_bytes;
	char	buf;

	n_bytes = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error();
	n_bytes = read(fd, &buf, 1);
	i = 0;
	while (n_bytes == 1)
	{
		pieces[i++] = buf;
		n_bytes = read(fd, &buf, 1);
	}
	pieces[i] = '\0';
	close(fd);
	return (pieces);
}

char	*ft_reader(char *argv)
{
	int		fd;
	char	buf;
	char	*pieces;
	ssize_t	n_bytes;
	size_t	length;

	buf = '\0';
	pieces = NULL;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error();
	n_bytes = read(fd, &buf, 1);
	length = 0;
	while (n_bytes == 1)
	{
		n_bytes = read(fd, &buf, 1);
		++length;
	}
	pieces = ft_strnew(length);
	if (!pieces)
		ft_error();
	close(fd);
	return (ft_read_to_fill(pieces, fd, argv));
}
