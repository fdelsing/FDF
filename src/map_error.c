/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:28:58 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/02 18:35:58 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	crash(int i)
{
	if (i == 0)
		perror("ERROR");
	if (i == 1)
		ft_putendl("ERROR: File badly formated for fdf");
	if (i == 2)
		ft_putendl("ERROR: Wrong number of input files");
	exit(0);
}

int		mapsize_y(char **argv)
{
	int		i;
	int		y;
	int		fd;
	int		gnl;
	char	*line;

	y = 0;
	fd = open(argv[1], O_RDONLY);
	gnl = ft_get_next_line(fd, &line);
	if (gnl == -1)
		crash(0);
	while (gnl == 1)
	{
		i = -1;
		while (line[++i])
			if (ft_isdigit(line[i]) != 1 && line[i] != ' ' && line[i] != '-')
				crash(1);
		free(line);
		y++;
		gnl = ft_get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	return (y);
}

int		mapsize_x(char *s)
{
	size_t i;
	int count;

	i = -1;
	count = 0;
	while (++i < (ft_strlen(s)))
		if ((ft_isdigit(s[i]) == 1) && (s[i + 1] == '\0' ||
					s[i + 1] == ' '))
			count++;
	return (count);
}

int		**map(t_param *p)
{
	int		i;
	int		x;
	int		y;
	int		**map;
	char	**split;

	if (!(map = (int**)malloc(sizeof(int*) * p->len_y)))
		crash(0);
	x = 0;
	i = 0;
	while (p->temp[x])
	{
		split = ft_strsplit(p->temp[x], ' ');
		if (!(map[i] = (int*)malloc(sizeof(int) * p->len_x)))
			crash(0);
		y = -1;
		while (++y < p->len_x)
			map[i][y] = ft_atoi(split[y]);
		x++;
		i++;
		free_ctab(split);
	}
	return (map);
}

void	check_error(t_param *p, char **argv, int argc)
{
	int		fd;
	int		x;

	if (argc != 2)
		crash(2);
	if ((p->len_y = mapsize_y(argv)) == 0)
		crash(1);
	if (!(p->temp = (char**)malloc(sizeof(char*)
					* ((p->len_y) + 1))))
		crash(0);
	fd = open(argv[1], O_RDONLY);
	x = 0;
	while (ft_get_next_line(fd, &(p->temp[x])) == 1)
		x++;
	free(p->temp[x]);
	p->temp[p->len_y] = 0;
	p->len_x = mapsize_x(p->temp[x - 1]);
	while (--x > 0)
	{
		if (p->len_x != mapsize_x(p->temp[x - 1]))
			crash(1);
	}
	close(fd);
}
