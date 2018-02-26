/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:56:45 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/26 19:31:35 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace_vertical(t_point a, t_point b, t_param *p)
{
	int i;

	i = 0;
	if (a.y < b.y)
	{
		while (i + a.y <= b.y)
		{
			put_pixel(p->img.data_img, a.x, i + a.y, p);
			i++;
		}
	}
	else
		while (i + b.y <= a.y)
		{
			put_pixel(p->img.data_img, a.x, i + b.y, p);
			i++;
		}
}

void	trace_horizontal(t_point a, t_point b, t_param *p)
{
	int i;

	i = 0;
	if (a.x < b.x)
	{
		while (i + a.x <= b.x)
		{
			put_pixel(p->img.data_img, i + a.x, a.y, p);
			i++;
		}
	}
	else
		while (i + b.x <= a.x)
		{
			put_pixel(p->img.data_img, i + b.x, a.y, p);
			i++;
		}
}

void	trace_diag_x(float delta, t_point a, t_point b, t_param *p)
{
	int i;
	int j;

	i = 0;
	if (a.x < b.x)
	{
		while ((int)(i + a.x) <= b.x)
		{
			j = (int)(delta * i);
			put_pixel(p->img.data_img, i + a.x, (int)(j + a.y), p);
			i++;
		}
	}
	if (b.x < a.x)
	{
		while ((int)(a.x - i) >= b.x)
		{
			j = (int)(-delta * i);
			put_pixel(p->img.data_img, a.x - i, (int)(j + a.y), p);
			i++;
		}
	}
}

void	trace_diag_y(float delta, t_point a, t_point b, t_param *p)
{
	int i;
	int j;

	j = 0;
	if (a.y < b.y)
	{
		while ((int)(j + a.y) <= b.y)
		{
			i = (int)(delta * j);
			put_pixel(p->img.data_img, i + a.x, (int)(j + a.y), p);
			j++;
		}
	}
	if (a.y > b.y)
	{
		while ((int)(b.y + j) <= a.y)
		{
			i = (int)(delta * j);
			put_pixel(p->img.data_img, b.x + i, (int)(b.y + j), p);
			j++;
		}
	}
}

void	trace(t_point a, t_point b, t_param *p)
{
	float delta;
	float x;
	float y;

	adapt_coord(&a, &b, p);
	x = b.x - a.x;
	y = b.y - a.y;
	if (x == 0)
		trace_vertical(a, b, p);
	if (y == 0)
		trace_horizontal(a, b, p);
	if (x != 0 && y != 0)
	{
		if (ft_abs(x) < ft_abs(y))
		{
			delta = (x / y);
			trace_diag_y(delta, a, b, p);
		}
		else
		{
			delta = (y / x);
			trace_diag_x(delta, a, b, p);
		}
	}
}
