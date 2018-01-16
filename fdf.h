/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:48:26 by fdelsing          #+#    #+#             */
/*   Updated: 2018/01/16 10:52:19 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./Libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define WIN_X 2500
# define WIN_Y 1200

typedef	struct	s_info
{
	void	*mlx;
	void	*win;
	int 	**map;
	char	**temp;
	int		y;
	int		x;
}				t_info;

void	ft_exit();
void	ft_check_error(t_info *inf, char **argv);
void	ft_free_ctab(char **s);
void	ft_free_itab(int **tab, int tablen);

int		ft_escape_programm(int keycode, void *param);
int		ft_mapsize_y(char **argv);
int		ft_count_nbr(char *s);
int		**ft_map(t_info *inf);

#endif
