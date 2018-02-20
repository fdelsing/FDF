/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:22:05 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/20 14:15:34 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "fdf.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <float.h>

void	ft_init_ctx(t_param *p)
{
	p->map = ft_map(&*p);
	ft_free_ctab(p->temp);
	if (p->len_x % 2 != 0)
		p->c_x = ((WIN_X - p->len_x) / 2) + 1;
	else
		p->c_x = (WIN_X - p->len_x) / 2;
	if (p->len_y % 2 != 0)
		p->c_y = ((WIN_Y - p->len_y) / 2) + 1;
	else
		p->c_y = (WIN_Y - p->len_y) / 2;
	p->space_x = 10;
	p->space_y = 10;
	p->o_x = ((float)p->len_x - 1) / 2;
	p->o_y = ((float)p->len_y - 1) / 2;
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIN_X, WIN_Y, "fdf");
	p->img.img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->img.data_img = (int*)mlx_get_data_addr(p->img.img,
			&p->img.bpp, &p->img.s_l, &p->img.endian);
	p->img.color = 0x0000ff;
}

void	ft_init_angles(t_param *p)
{
	p->pi = acos(0) * 2;
	p->rad_x = 0;
	p->rad_y = p->pi;
	p->rad_z = p->pi;
	p->sin_x = sin(p->rad_x);
	p->sin_y = sin(p->rad_y);
	p->cos_x = cos(p->rad_x);
	p->cos_y = cos(p->rad_y);
	p->sin_z = 0;
	p->cos_z = 0;
}

int		ft_keyhook(int keycode, t_param *p)
{
	ft_bzero((char*)p->img.data_img, (WIN_Y * WIN_X) * 4);
	if (keycode == 53)
		exit(0);
	if (keycode >= 123 && keycode <= 126)
		ft_translation(keycode, p);
	if (keycode >= 83 && keycode <= 85)
		ft_rotations(keycode, p);
	if (keycode == 24 || keycode == 27)
		ft_zoom(keycode, p);
	if (keycode == 269 || keycode == 262)
		ft_depth(keycode, p);
	if (keycode == 71)
		ft_init_angles(p);
	ft_fill_img(p);
	return (0);
}

int		main(int argc, char **argv)
{
	t_param	p;
	t_img	img;
	int		x;
	int		y;

	ft_check_error(&p, argv, argc);
	ft_init_ctx(&p);
	ft_init_angles(&p);
	////////////////// print map //////////////////////
	y = -1;
	while (++y < p.len_y)
	{
		x = -1;
		while (++x < p.len_x)
			printf("%d ", p.map[y][x]);
		printf("\n");
	}
	//////////////// fill img ///////////////////////
	ft_fill_img(&p);
	mlx_hook(p.win, 2, 1L << 8, ft_keyhook, &p);
	mlx_loop(p.mlx);
	return (0);
}
