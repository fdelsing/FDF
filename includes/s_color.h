/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_color.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:38:18 by fdelsing          #+#    #+#             */
/*   Updated: 2018/03/29 17:41:14 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_COLOR_H
# define S_COLOR_H

typedef union		u_color
{
	unsigned int	hex;
	struct			s_rgba
	{
		unsigned char b;
		unsigned char g;
		unsigned char r;
		unsigned char a;
	}				rgba;
}					t_color;

#endif
