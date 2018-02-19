/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:00:46 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/19 11:04:30 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		reset(int keycode, t_param *p)
{
	ft_init_ctx(p);
	ft_init_angles(p);
	return (0);
}

int		ft_depth(int keycode, t_param *p)
{
	int y;
	int x;

	y = 0;
	while (y < p->len_y)
	{
		x = 0;
		while(x < p->len_x)
		{
			if (keycode == 269)
			{
				if (p->map[y][x] > 0)
					p->map[y][x] += 5;
				else if (p->map[y][x] < 0)
					p->map[y][x] -= 5;
			}
			else if (keycode == 262)
			{
				if (p->map[y][x] > 0 && p->map[y][x] - 5 > 0)
					p->map[y][x] -= 5;
				else if (p->map[y][x] < 0 && p->map[y][x] + 5 < 0)
					p->map[y][x] += 5;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_zoom(int keycode, t_param *p)
{
	if (keycode == 24) //////// zoom
	{
		p->space_x += 5;
		p->space_y += 5;
	}
	if (keycode == 27) //////// zoom
	{
		p->space_x -= 5;
		p->space_y -= 5;
	}
	return (0);
}

int		ft_translation(int keycode, t_param *p)
{
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

int		ft_rotations(int keycode, t_param *p)
{
	if (keycode == 83) // rotate axe x
	{
		p->rad_x += 0.4 / p->pi;
		p->sin_x = sin(p->rad_x);
		p->cos_x = cos(p->rad_x);
	}
	if (keycode == 84) //rotate axe y
	{	
		p->rad_y += 0.4 / p->pi;
		p->sin_y = sin(p->rad_y);
		p->cos_y = cos(p->rad_y);
//		p->cos_x = cos(p->rad_x);
	}
	if (keycode == 85) // rotate z
	{
		p->rad_z += 0.2/p->pi;
		p->sin_z = sin(p->rad_z); // appliquer sur y ;
		p->cos_z = cos(p->rad_z);
	}
	printf("sin_x = %f, sin_y = %f, sin_z = %f\n, cos_x = %f, cos_y = %f, cos_z = %f\n",
			p->sin_x, p->sin_y, p->sin_z, p->cos_x, p->cos_y, p->cos_z);
	return (0);
}
