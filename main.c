/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:22:05 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/26 19:32:02 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_program(t_param *p)
{
	ft_putendl("You have successfully exited the program");
	free_itab(p->map, p->len_y);
	free_ctab(p->temp);
	exit(0);
}

void	init_ctx(t_param *p)
{
	if (p->len_x % 2 != 0)
		p->c_x = ((WIN_X - p->len_x) / 2) + 1;
	else
		p->c_x = (WIN_X - p->len_x) / 2;
	if (p->len_y % 2 != 0)
		p->c_y = ((WIN_Y - p->len_y) / 2) + 1;
	else
		p->c_y = (WIN_Y - p->len_y) / 2;
	p->o_x = ((float)p->len_x - 1) / 2;
	p->o_y = ((float)p->len_y - 1) / 2;
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIN_X, WIN_Y, "fdf");
	p->img.img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->img.data_img = (int*)mlx_get_data_addr(p->img.img,
			&p->img.bpp, &p->img.s_l, &p->img.endian);
}

void	init_image_tools(t_param *p)
{
	p->map = map(&*p);
	p->space_x = 10;
	p->space_y = 10;
	p->img.color = 0xffffff;// 0xffffff - 0xff0000;//0xffffff - 0xffff00;

	p->f.pi = acos(0) * 2;
	p->f.rad_x = 0;
	p->f.rad_y = p->f.pi;
	p->f.rad_z = p->f.pi;
	p->f.sin_x = sin(p->f.rad_x);
	p->f.sin_y = sin(p->f.rad_y);
	p->f.cos_x = cos(p->f.rad_x);
	p->f.cos_y = cos(p->f.rad_y);
	p->f.sin_z = 0;
	p->f.cos_z = 0;
}

int		ft_keyhook(int keycode, t_param *p)
{
	ft_bzero((char*)p->img.data_img, (WIN_Y * WIN_X) * 4);
	if (keycode == 53)
		exit_program(p);
	if (keycode >= 123 && keycode <= 126)
		translation(keycode, p);
	if (keycode >= 83 && keycode <= 85)
		rotations(keycode, p);
	if (keycode == 24 || keycode == 27)
		zoom(keycode, p);
	if (keycode == 71)
	{
		free_itab(p->map, p->len_y);
		init_image_tools(p);
	}
	fill_img(p);
	return (0);
}

int		main(int argc, char **argv)
{
	t_param	p;
	int		x;
	int		y;

	check_error(&p, argv, argc);
	init_ctx(&p);
	init_image_tools(&p);
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
	fill_img(&p);
	mlx_hook(p.win, 2, 1L << 8, ft_keyhook, &p);
	mlx_loop(p.mlx);
	return (0);
}
