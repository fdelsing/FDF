/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:00:46 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/20 13:56:34 by fdelsing         ###   ########.fr       */
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
	if (keycode == 83) // rotate axe y
	{
		p->rad_x += 0.4/p->pi;
		p->sin_x = sin(p->rad_x);
		p->cos_x = cos(p->rad_x);
	}
	if (keycode == 84) //rotate axe x
	{	
		p->rad_y += 0.4/p->pi;
		p->sin_y = sin(p->rad_y);
		p->cos_y = cos(p->rad_y);
	}
	if (keycode == 85) // rotate z
	{
		p->rad_z = p->pi + p->pi/3;
		p->sin_z = sin(p->rad_z); // appliquer sur y ;
		p->cos_z = cos(p->rad_z);
	}
	return (0);
}
