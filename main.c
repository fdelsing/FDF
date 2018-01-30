/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:22:05 by fdelsing          #+#    #+#             */
/*   Updated: 2018/01/30 15:53:13 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "fdf.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_translation(int keycode, t_param *p)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 124)
		p->c_x += 10;
	if (keycode == 123)
		p->c_x -= 10;
	if (keycode == 126)
		p->c_y -= 10;
	if (keycode == 125)
		p->c_y += 10;
	ft_fill_img(p);
	return (0);
}

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
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIN_X, WIN_Y, "fdf");	
	p->img.img = mlx_new_image(p->mlx, WIN_X, WIN_Y);
	p->img.data_img = (int*)mlx_get_data_addr
		(p->img.img, &p->img.bpp, &p->img.s_l, &p->img.endian);
}

int		ft_keyhook(int keycode, t_param *p)
{
	if (keycode == 53)
		exit(0);
	if (keycode >= 123 && keycode <= 126)
	{
		ft_bzero((char*)p->img.data_img, (WIN_Y * WIN_X) * 4);
		ft_translation(keycode, p);
	}
	return (0);
}

int		ft_mousehook(int button, int x, int y, t_param p)
{
	int i;

	i = 0;
	if (button == 1)
	{
		if (x < 1000 && y < 500)
			printf("dans le haut\n");
		printf("HELLO\n");
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_param	p;
	t_img	img;
	int		x;
	int		y;

	ft_check_error(&p, argv);
	ft_init_ctx(&p);
	////////////////// print map ////////////////////// 
	y = -1;
	while (++y < p.len_y)
	{
		x = -1;
		while (++x < p.len_x)
			printf("%d ", p.map[y][x]);
		printf("\n");
	}
	printf("c_x = %d, c_y = %d\n", p.c_x, p.c_y);
	//////////////// fill img ///////////////////////
	ft_fill_img(&p);
	mlx_hook(p.win, 2, 1L<<8, ft_keyhook, &p);
	mlx_hook(p.win, 4, 1L<<8, ft_mousehook, &p);
	//mlx_key_hook(p.win, ft_keyhook, &p);
	////////////////////////////////////////////////////////////
	mlx_loop(p.mlx);
	return (0);
}