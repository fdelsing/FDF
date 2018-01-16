/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:22:05 by fdelsing          #+#    #+#             */
/*   Updated: 2018/01/16 11:05:12 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "fdf.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_escape_programm(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_info	inf;
	int		x;
	int		y;
	void	*imgptr;

	ft_check_error(&inf, argv);
	inf.map = ft_map(&inf);
	ft_free_ctab(inf.temp);
	////////////////// print map ////////////////////// 
	y = -1;
	while (++y < inf.y)
	{
		x = -1;
		while (++x < inf.x)
			printf("%d ", inf.map[y][x]);
		printf("\n");
	}
	//////////////////////////////////////////////////
	inf.mlx = mlx_init();
	inf.win = mlx_new_window(inf.mlx, WIN_X, WIN_Y, "test");	

	x = 100;
	while (x <= 150)
	{
		y = 100;
		while (y <= 150)
		{
			mlx_pixel_put(inf.mlx, inf.win, x-50, y-50, 0x000080);
			mlx_pixel_put(inf.mlx, inf.win, x-25, y-25, 0x00008f);
			mlx_pixel_put(inf.mlx, inf.win, x, y, 0x0000F0);
			y++;
		}
		x++;
	}
	ft_free_itab(inf.map, inf.y);
	unsigned long imgcolor;
	imgcolor = mlx_get_color_value(mlx, 0xffffff);
	imgptr = mlx_new_image(inf.mlx, 100, 500);
	mlx_get_data_addr(imgptr, 0xffffff,500, 0);
	mlx_put_image_to_window(inf.mlx,inf.win,
			imgptr, 1000, 700);
	mlx_key_hook(inf.win, ft_escape_programm, 0);
	mlx_loop(inf.mlx);
	return (0);
}
