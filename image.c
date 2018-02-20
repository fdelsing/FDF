/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:40:07 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/20 14:03:45 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_img(int *add, int i, int j, t_param *p)
{
	i += p->c_x;
	j += p->c_y;
	add[(j * WIN_X) + i] = p->img.color;
}

void	ft_adapt_coord(t_point *a, t_point *b, t_param *p)
{
	float	depth_y;
	float	depth_x;
	float	depth_z;
	int		buf;

	depth_y = p->map[p->a.y][p->a.x] * p->sin_y;
	depth_x = p->map[p->a.y][p->a.x] * p->sin_x;
	a->x = (int)((((float)a->x - p->o_x) * p->space_x)
			* p->cos_x) + (int)depth_x;
	a->y = (int)((((float)a->y - p->o_y) * p->space_y)
			* p->cos_y) + (int)depth_y;
	depth_y = p->map[p->b.y][p->b.x] * p->sin_y;
	depth_x = p->map[p->b.y][p->b.x] * p->sin_x;
	b->x = (int)((((float)b->x - p->o_x) * p->space_x)
			* p->cos_x) + (int)depth_x;
	b->y = (int)((((float)b->y - p->o_y) * p->space_y)
			* p->cos_y) + (int)depth_y;
	depth_z = p->map[p->a.y][p->a.x] * p->cos_z;
	buf = a->x;
	a->x += (int)((float)a->y * (p->sin_z)) + (int)depth_z;
	a->y -= (int)((float)buf * (p->sin_z)) - (int)depth_z;
	depth_z = p->map[p->b.y][p->b.x] * p->cos_z;
	buf = b->x;
	b->x += (int)((float)b->y * (p->sin_z)) + (int)depth_z;
	b->y -= (int)((float)buf * (p->sin_z)) - (int)depth_z;
}

void	ft_fill_img(t_param *p)
{
	p->a.y = 0;
	while (p->a.y <= (p->len_y - 1))
	{
		p->a.x = 0;
		while (p->a.x <= (p->len_x - 1))
		{
			p->b.x = p->a.x + 1;
			p->b.y = p->a.y;
			if (p->b.x < p->len_x && p->b.y < p->len_y)// trace horizontal
				ft_trace(p->a, p->b, p);
			p->b.x = p->a.x;
			p->b.y = p->a.y + 1;
			if (p->b.y < p->len_y)// trace vertical
				ft_trace(p->a, p->b, p);
			p->a.x++;
		}
		p->a.y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
}
