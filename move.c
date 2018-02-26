/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:00:46 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/26 19:21:46 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deeper(t_param *p)
{
	int y;
	int x;

	y = 0;
	while (y < p->len_y)
	{
		x = 0;
		while(x < p->len_x)
		{
			if (p->map[y][x] > 0)
				p->map[y][x] += zm;
			else if (p->map[y][x] < 0)
				p->map[y][x] -= zm;
			x++;
		}
		y++;
	}
}

void	flatter(t_param *p)
{
	int y;
	int x;

	y = 0;
	while (y < p->len_y)
	{
		x = 0;
		while(x < p->len_x)
		{
				if (p->map[y][x] > 0 && p->map[y][x] - zm > 0)
					p->map[y][x] -= zm;
				else if (p->map[y][x] < 0 && p->map[y][x] + zm < 0)
					p->map[y][x] += zm;
			x++;
		}
		y++;
	}
}

int		zoom(int keycode, t_param *p)
{
	if (keycode == 24)
	{
		p->space_x += zm;
		p->space_y += zm;
		deeper(p);
	}
	if (keycode == 27 && p->space_x - zm > 0 && p->space_y - zm > 0)
	{
		p->space_x -= zm;
		p->space_y -= zm;
		flatter(p);
	}
	return (0);
}

int		translation(int keycode, t_param *p)
{
	if (keycode == 124)
		p->c_x += 10;
	if (keycode == 123)
		p->c_x -= 10;
	if (keycode == 126)
		p->c_y -= 10;
	if (keycode == 125)
		p->c_y += 10;
	return (0);
}

int		rotations(int keycode, t_param *p)
{
	if (keycode == 83) // rotate axe y
	{
		p->f.rad_x += 0.4/p->f.pi;
		p->f.sin_x = sin(p->f.rad_x);
		p->f.cos_x = cos(p->f.rad_x);
	}
	if (keycode == 84) //rotate axe x
	{	
		p->f.rad_y += 0.4/p->f.pi;
		p->f.sin_y = sin(p->f.rad_y);
		p->f.cos_y = cos(p->f.rad_y);
	}
	if (keycode == 85) // rotate z
	{
		p->f.rad_z = p->f.pi + p->f.pi/3;
		p->f.sin_z = sin(p->f.rad_z); // appliquer sur y ;
		p->f.cos_z = cos(p->f.rad_z);
	}
	return (0);
}
