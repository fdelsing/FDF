/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:40:07 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/11 09:27:33 by fdelsing         ###   ########.fr       */
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
	int	z;
	if (p->A.x < p->len_y - 1 && p->A.y < p->len_x - 1)
		z = p->map[p->A.x][p->A.y];
	else
		z = 0;
	printf("z = %d\n", z);

	A->x = (A->x * p->space_x) * p->angle_x;
	A->y = (A->y * p->space_y) * p->angle_y;
	B->x = (B->x * p->space_x) * p->angle_x;
	B->y = (B->y * p->space_y) * p->angle_y;
}

void	ft_trace(t_point A, t_point B, t_param *p)
{
	int i; ////x
	int j; ////y
	int x;
	int y;

	ft_adapt_coord(&A, &B, p);
	//	printf("A.x = %d, A.y = %d\n", A.x, A.y);
	//	printf("B.x = %d, B.y = %d\n\n", B.x, B.y);
	i = 0;
	x = B.x - A.x;
	y = B.y - A.y; 
	if (y == 0 || x == 0)
	{
		j = 0;
		if (y == 0)
		{
			while (i + A.x <= B.x)
			{
				fill_img(p->img.data_img, i + A.x, j + A.y, 0x0000ff, p);
				i++;
			}
		}
		i = 0;
		if (x == 0)
		{
			while (i + A.y <= B.y)
			{
				fill_img(p->img.data_img, j + A.x, i + A.y, 0x0000ff, p);
				i++;
			}
		}
		//		j = (y / x) * i;
		i++;
	}
	x = 3;
	y = 5;
	//	int	VAR(z);
	//	printf("z = %d\n", z);
}

void	ft_fill_img(t_param *p)
{
	p->A.x = 0;
	while (p->A.x <= (p->len_x - 1))
	{
		p->A.y = 0;
		while (p->A.y < (p->len_y - 1))
		{
			p->B.x = p->A.x + 1;
			p->B.y = p->A.y;
			if (p->B.x < p->len_x)
			{
/*				int	z;
				z = p->map[p->A.x][p->A.y];
	printf("a->x%d, a->y%d\n", A->x, A->y);*/
	
				if (p->angle_x < 0)
					ft_trace(p->B, p->A, p);
				else
					ft_trace(p->A, p->B, p);
			}
			p->B.x = p->A.x;
			p->B.y = p->A.y + 1;
			if (p->angle_y < 0)
				ft_trace(p->B, p->A, p);
			else
				ft_trace(p->A, p->B, p);
			p->A.y++;
		}
		p->B.y = p->A.y;
		p->B.x = p->A.x + 1;
		if (p->B.x < p->len_x)
		{
			if (p->angle_x < 0)
				ft_trace(p->B, p->A, p);
			else
				ft_trace(p->A, p->B, p);
		}
		p->A.x++;
	}
	printf("len_x = %d\n", p->len_x);
	mlx_put_image_to_window(p->mlx,p->win, p->img.img, 0, 0);
}
