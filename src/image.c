/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:40:07 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/29 20:17:47 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	color(t_param *p)
{
	if (p->img.color.rgba.b == 0)
	{
		p->img.color.rgba.r -= 0x5;
		p->img.color.rgba.g += 0x5;
	}
	if (p->img.color.rgba.r == 0)
	{
		p->img.color.rgba.g -= 0x5;
		p->img.color.rgba.b += 0x5;
	}
	if (p->img.color.rgba.g == 0)
	{
		p->img.color.rgba.b -= 0x5;
		p->img.color.rgba.r += 0x5;
	}
}

void	put_pixel(int *add, int i, int j, t_param *p)
{
	i += p->c_x;
	j += p->c_y;
	if (j >= 0 && j < WIN_Y && i >= 0 && i <= WIN_X)
		add[(j * WIN_X) + i] = p->img.color.hex;
}

void	adapt_rot_z(t_point *a, t_point *b, t_param *p)
{
	float	depth_z;
	int		buf;

	depth_z = p->map[p->a.y][p->a.x] * p->f.cos_z;
	buf = a->x;
	a->x += (int)((float)a->y * (p->f.sin_z)) + (int)depth_z;
	a->y -= (int)((float)buf * (p->f.sin_z)) - (int)depth_z;
	depth_z = p->map[p->b.y][p->b.x] * p->f.cos_z;
	buf = b->x;
	b->x += (int)((float)b->y * (p->f.sin_z)) + (int)depth_z;
	b->y -= (int)((float)buf * (p->f.sin_z)) - (int)depth_z;
}

void	adapt_coord(t_point *a, t_point *b, t_param *p)
{
	float	depth_y;
	float	depth_x;

	depth_y = p->map[p->a.y][p->a.x] * p->f.sin_y;
	depth_x = p->map[p->a.y][p->a.x] * p->f.sin_x;
	a->x = (int)((((float)a->x - p->o_x) * p->space_x)
			* p->f.cos_x) + (int)depth_x;
	a->y = (int)((((float)a->y - p->o_y) * p->space_y)
			* p->f.cos_y) + (int)depth_y;
	depth_y = p->map[p->b.y][p->b.x] * p->f.sin_y;
	depth_x = p->map[p->b.y][p->b.x] * p->f.sin_x;
	b->x = (int)((((float)b->x - p->o_x) * p->space_x)
			* p->f.cos_x) + (int)depth_x;
	b->y = (int)((((float)b->y - p->o_y) * p->space_y)
			* p->f.cos_y) + (int)depth_y;
	adapt_rot_z(a, b, p);
}

void	fill_img(t_param *p)
{
	p->a.y = 0;
	while (p->a.y <= (p->len_y - 1))
	{
		p->a.x = 0;
		while (p->a.x <= (p->len_x - 1))
		{
			p->b.x = p->a.x + 1;
			p->b.y = p->a.y;
			if (p->b.x < p->len_x && p->b.y < p->len_y)
				trace(p->a, p->b, p);
			p->b.x = p->a.x;
			p->b.y = p->a.y + 1;
			if (p->b.y < p->len_y)
				trace(p->a, p->b, p);
			p->a.x++;
		}
		p->a.y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}
