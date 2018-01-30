/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:48:26 by fdelsing          #+#    #+#             */
/*   Updated: 2018/01/30 18:12:32 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./Libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define WIN_X 2500
# define WIN_Y 1200
# define space 10
# define VAR(z)	z = p->map[x][y]

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct s_img
{
	int		bpp;
	int		s_l;
	int		endian;
	void	*img;
	int		*data_img;
}				t_img;

typedef	struct	s_param
{
	void	*mlx;
	void	*win;
	int 	**map;
	char	**temp;
	int		len_y;
	int		len_x;
	int		c_x;
	int		c_y;
	t_img	img;
	t_point	A;
	t_point B;
}				t_param;

typedef struct	s_var
{
	int x;
	int y;
	int color;
}				t_var;

void	ft_exit();
void	ft_check_error(t_param *p, char **argv);
void	ft_free_ctab(char **s);
void	ft_free_itab(int **tab, int tablen);
void	ft_fill_img(t_param *p);

int		ft_escape_programm(int keycode, t_param *p);
int		ft_mapsize_y(char **argv);
int		ft_count_nbr(char *s);
int		**ft_map(t_param *p);

#endif
