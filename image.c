/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:40:07 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/15 08:09:06 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_img(int *add, int i, int j, int color, t_param *p)
{
	i += p->c_x;
	j += p->c_y;
	add[(j * WIN_X) + i] = color;
}

void	ft_adapt_coord(t_point *A, t_point *B, t_param *p)
{
	float z;
	int buf;

	z = p->map[p->A.y][p->A.x] * cos(p->rad_y);

	A->x = (int)((A->x * p->space_x) * p->sin_x);
	A->y = (int)((A->y * p->space_y) * p->sin_y) + (int)z;

	z = p->map[p->B.y][p->B.x] * cos(p->rad_y);

	B->x = (int)((B->x * p->space_x) * p->sin_x);
	B->y = (int)((B->y * p->space_y) * p->sin_y) + (int)z;
}

void	ft_trace_straight(t_point A, t_point B, t_param *p, int x, int y)
{
	int i;
	int j;

	i = 0;
	if (y == 0)
	{
		while (i + A.x <= B.x)
		{
			fill_img(p->img.data_img, i + A.x,A.y, 0x0000ff, p);
			i++;
		}
	}
	i = 0;
	if (x == 0)
	{
		while (i + A.y <= B.y)
		{
			fill_img(p->img.data_img,A.x, i + A.y, 0x0000ff, p);
			i++;
		}
	}
}

void	ft_trace(t_point A, t_point B, t_param *p)
{
	int i; ////x
	float j; ////y
	int x;
	int y;

	ft_adapt_coord(&A, &B, p);
	//		printf("A.x = %d, A.y = %d\n", A.x, A.y);
	//		printf("B.x = %d, B.y = %d\n\n", B.x, B.y);
	x = B.x - A.x;
	y = B.y - A.y;
	if (y == 0 || x == 0)
		ft_trace_straight(A, B, p, x, y);
	else
	{
		i = 0;
		while (i + A.x <= B.x && (int)(j + A.y) != B.y)
		{
			j = (x / y) * i;
			if (j < 0)
			{
				fill_img(p->img.data_img, (int)(-j + A.x), -i + A.y, 0x00ffff, p);
			}
			else
				fill_img(p->img.data_img, (int)(j + A.x), i + A.y, 0x00ffff, p);
			i++;
		}
		/*i = 0;
		while (i + A.y != B.y)
		{

			i++;
		}*/
	}
}

void	ft_fill_img(t_param *p)
{
	p->A.y = 0;
	while (p->A.y <= (p->len_y - 1))
	{
		p->A.x = 0;
		while (p->A.x <= (p->len_x - 1))
		{
			p->B.x = p->A.x + 1;
			p->B.y = p->A.y;
			if (p->B.x < p->len_x && p->B.y < p->len_y) /////////// trace horizontal 
			{
				if (p->sin_x < 0)
					ft_trace(p->B, p->A, p);
				else
					ft_trace(p->A, p->B, p);
			}
			p->B.x = p->A.x;
			p->B.y = p->A.y + 1;
			if (p->B.y < p->len_y) //////////// trace vertical
			{
				if (p->sin_y < 0)
					ft_trace(p->B, p->A, p);
				else
					ft_trace(p->A, p->B, p);
			}
			p->A.x++;
		}
		p->A.y++;
	}
	printf("len_x = %d\n", p->len_x);
	mlx_put_image_to_window(p->mlx,p->win, p->img.img, 0, 0);
}
