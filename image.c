/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:40:07 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/19 12:56:27 by fdelsing         ###   ########.fr       */
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
	float depth_y;
	float depth_x;

	depth_y = p->map[p->A.y][p->A.x] * p->cos_y;
	depth_x = p->map[p->A.y][p->A.x] * p->cos_x;//
	A->x = (int)((((float)A->x - p->o_x) * p->space_x) * p->sin_x) + (int)depth_x;
	A->y = (int)((((float)A->y - p->o_y) * p->space_y) * p->sin_y) + (int)depth_y;

	depth_y = p->map[p->B.y][p->B.x] * p->cos_y;
	depth_x = p->map[p->B.y][p->B.x] * p->cos_x;//
	B->x = (int)((((float)B->x - p->o_x) * p->space_x) * p->sin_x)+ (int)depth_x;;
	B->y = (int)((((float)B->y - p->o_y) * p->space_y) * p->sin_y) + (int)depth_y;

	A->x += (int)((float)A->y * p->sin_z);
	B->x += (int)((float)B->y * p->sin_z);
	A->y += (int)((float)(A->x * p->sin_z));
	B->y += (int)((float)(B->x * p->sin_z));
}

void	ft_trace_straight(t_point A, t_point B, t_param *p, int x, int y)
{
	int i;
	int j;

	i = 0;
	if (x == 0)
	{
		while (i + A.y <= B.y)
		{
			fill_img(p->img.data_img, A.x, i + A.y, 0x0000ff, p);
			i++;
		}
	}
	i = 0;
	if (y == 0)
	{
		while (i + A.x <= B.x)
		{
			fill_img(p->img.data_img, i + A.x, A.y, 0x0000ff, p);
			i++;
		}
	}
}

void	ft_trace(t_point A, t_point B, t_param *p)
{
	int i; ////x
	int j; ////y
	float delta;
	float x;
	float y;

	ft_adapt_coord(&A, &B, p);
	x = B.x - A.x;
	y = B.y - A.y;
//	printf("A.x = %d, A.y = %d\n, B.x = %d, B.y = %d\n", A.x, A.y, B.x, B.y);
	if (y == 0 || x == 0)
		ft_trace_straight(A, B, p, x, y);
	else
	{
		delta = (y / x);
		printf("delta %f ", delta);
		printf("cos_x = %f, cos_y = %f\n", p->cos_x, p->cos_y);
	   	//if (p->sin_x < 0)
		//	delta = -delta;	
		i = 0;
		printf("delta %f ", delta);
		while ((int)(i + A.x) <= B.x)
		{
			j = (int)(delta * i);
			printf("j = %d\n", j);
			if (p->sin_x < 0)
				fill_img(p->img.data_img,i + A.x, (int)(j + B.y), 0x00ffff, p);
			else
				fill_img(p->img.data_img,i + A.x, (int)(j + A.y), 0x00ffff, p);
			i++;
		}
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
//	printf("len_x = %d\n", p->len_x);
	mlx_put_image_to_window(p->mlx,p->win, p->img.img, 0, 0);
}
