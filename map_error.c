/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:28:58 by fdelsing          #+#    #+#             */
/*   Updated: 2018/01/16 10:39:00 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "fdf.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_exit()
{
	exit(0);
}

int		ft_mapsize_y(char **argv)
{
	int		y;
	int		fd;
	int		gnl;
	char	*line;

	y = 0;
	fd = open(argv[1], O_RDONLY);
	gnl = get_next_line(fd, &line);
	if (gnl == -1)
	{
		free(line);
		ft_putendl("Bad filedescriptor - Error");
		ft_exit();
	}
	while (gnl == 1)
	{
		free(line);
		y++;
		gnl = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	return (y);
}

int		ft_mapsize_x(char *s)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (++i < (ft_strlen(s)))
		if ((ft_isdigit(s[i]) == 1) && (s[i + 1] == '\0' ||
					s[i + 1] == ' '))
			count++;
	return (count);
}

int		**ft_map(t_info *inf)
{
	int		i;
	int		x;
	int		y;
	int		**map;
	char	**split;

	if (!(map = (int**)malloc(sizeof(int*) * inf->y)))
		ft_exit();
	x = 0;
	i = 0;
	while (inf->temp[x])
	{
		split = ft_strsplit(inf->temp[x], ' ');
		if (!(map[i] = (int*)malloc(sizeof(int) * inf->x)))
		{
			i++;
			while (i-- >= 0)
				free(map[i]);
			free(map);
			ft_exit();
		}
		y = -1;
		while (++y < inf->x)
			map[i][y] = ft_atoi(split[y]);
		x++;
		i++;
		ft_free_ctab(split);
	}
//	ft_free_ctab(inf->temp);
	return (map);
}

void		ft_check_error(t_info *inf, char **argv)
{
	int		fd;
	int		x;
	int		xsize;

	inf->y = ft_mapsize_y(argv);
	if (!(inf->temp = (char**)malloc(sizeof(char*)
					* ((inf->y) + 1))))
		ft_exit();
	fd = open(argv[1], O_RDONLY);
	x = 0;
	while (get_next_line(fd, &(inf->temp[x])) == 1)
		x++;
	free(inf->temp[x]);
	inf->temp[inf->y] = 0;
	inf->x = ft_mapsize_x(inf->temp[x - 1]);
	while (--x > 0)
	{
		if (inf->x != ft_mapsize_x(inf->temp[x-1]))
		{
			ft_putendl("ERROR");
			ft_exit();
		}
	}
	close(fd);
}

