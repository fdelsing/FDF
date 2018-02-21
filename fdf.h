/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:48:26 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/21 13:49:49 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./Libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define WIN_X 2500
# define WIN_Y 1200
# define zm 3

typedef struct	s_float
{
	float	pi;
	float	rad_x;
	float	rad_y;
	float	rad_z;
	float	sin_x;
	float	sin_y;
	float	sin_z;
	float	cos_x;
	float	cos_y;
	float	cos_z;
}				t_float;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_img
{
	int		bpp;
	int		s_l;
	int		endian;
	void	*img;
	int		*data_img;
	int		color;
}				t_img;

typedef	struct	s_param
{
	void	*mlx;
	void	*win;
	int		**map;
	char	**temp;
	int		len_y;
	int		len_x;
	float	o_x;
	float	o_y;
	int		c_x;
	int		c_y;
	int		space_x;
	int		space_y;
	t_float	f;
	t_img	img;
	t_point	a;
	t_point b;
}				t_param;

typedef struct	s_var
{
	int x;
	int y;
	int color;
}				t_var;

void			exit_program(t_param *p);
void			init_ctx(t_param *p);
void			init_image_tools(t_param *p);
int				ft_keyhook(int keycode, t_param *p);

void			free_ctab(char **s);
void			free_itab(int **tab, int tablen);

void			crash(int i);
int				mapsize_y(char **argv);
int				mapsize_x(char *s);
int				**map(t_param *p);
void			check_error(t_param *p, char **argv, int argc);

int				translation(int keycode, t_param *p);
int				rotations(int keycode, t_param *p);
int				zoom(int keycode, t_param *p);
int				depth(int keycode, t_param *p);

void			put_pixel(int *add, int i, int j, t_param *p);
void			adapt_rot_z(t_point *a, t_point *b, t_param *p);
void			adapt_coord(t_point *a, t_point *b, t_param *p);
void			fill_img(t_param *p);

void			trace(t_point a, t_point b, t_param *p);
void			trace_vertical(t_point a, t_point b, t_param *p);
void			trace_horizontal(t_point a, t_point b, t_param *p);
void			trace_diag_x(float delta, t_point a, t_point b, t_param *p);
#endif
