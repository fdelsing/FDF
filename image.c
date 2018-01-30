/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:40:07 by fdelsing          #+#    #+#             */
/*   Updated: 2018/01/30 18:15:31 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_img(int *add, int i, int j, int color, t_param *p)
{
	i += p->c_x;
	j += p->c_y;
	add[(j * WIN_X) + i] = color;
}

void	ft_trace(t_point A, t_point B, t_param *p)
{
	int x;
	int y;

	x = 3;
	y = 5;
	int	VAR(z);
	printf("z = %d\n", z);
}

void	ft_fill_img(t_param *p)
{
	int i;
	int j;
	int x;
	int y;
	int k;

	k = 0;
	j = 0;

	while (j < p->len_y)
	{	
		x = (space * j);
		k = -1;
		while(k++ < 10 * (p->len_x - 1))
		{
			y = k;
			fill_img(p->img.data_img, x, y, 0x0000ff, p);
		}
		i = 0;
		while(i < p->len_x)
		{
			y = (10 * i);
			k = -1;
			while(++k < 10 * (p->len_y - 1))
			{
				x = k;
				fill_img(p->img.data_img, x, y, 0x0000ff, p);
			}
			i++;
		}
		j++;
	}
	ft_trace(p->A, p->B, p);
	mlx_put_image_to_window(p->mlx,p->win, p->img.img, 0, 0);
}
