/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:00:46 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/17 08:30:47 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		reset(int keycode, t_param *p)
{
	ft_init_ctx(p);
	ft_init_angles(p);
	return (0);
}

int		ft_zoom(int keycode, t_param *p)
{
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
	return (0);
}

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
	if (keycode == 83) // rotate axe x
	{
		p->rad_x += 0.4 / p->pi;
		p->sin_x = sin(p->rad_x);
		p->cos_x = cos(p->rad_x);
	}
	if (keycode == 84) //rotate axe y
	{	
		p->rad_y += 0.4 / p->pi;
		p->sin_y = sin(p->rad_y);
		p->cos_x = cos(p->rad_x);
	}
	if (keycode == 85) // rotate z
	{
		p->rad_z += 0.4 / p->pi;
		p->sin_z = sin(p->rad_z); // appliquer sur y ;
		p->cos_z = cos(p->rad_z);
	}
	printf("angle = %f\n", p->sin_x);
	return (0);
}
