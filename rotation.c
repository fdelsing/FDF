/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:00:46 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/11 09:27:31 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_translation(int keycode, t_param *p)
{
	printf("keycode = %d\n", keycode);
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

	ft_bzero((char*)p->img.data_img, (WIN_Y * WIN_X) * 4);
	if (keycode == 83) // rotate axe x
	{
		p->rad_x += 180 / p->pi;
		p->angle_x = sin(p->rad_x);
	}
	if (keycode == 84) //rotate axe y
	{	
		p->rad_y += 180 / p->pi;
		p->angle_y = sin(p->rad_y);
	}
		printf("angle = %f\n", p->angle_x);
	return (0);
}

int		ft_shift(int keycode, t_param *p)
{
	printf("space_x %d\n", p->space_x);
	ft_bzero((char*)p->img.data_img, (WIN_Y * WIN_X) * 4);
	if (keycode == 24) //////// zoom
	{
		p->space_x += 5;
		p->space_y += 5;
	}
	else if (keycode == 27) //////// zoom
	{
		p->space_x -= 5;
		p->space_y -= 5;
	}
	if (keycode >= 83 && keycode <= 85)
		ft_rotations(keycode, p);
	ft_fill_img(p);
	return (0);
}
