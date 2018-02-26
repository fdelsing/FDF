/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdelsing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:32:18 by fdelsing          #+#    #+#             */
/*   Updated: 2018/02/26 12:28:05 by fdelsing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_itab(int **tab, int tablen)
{
	int i;

	i = tablen;
	while (--i >= 0)
		free(tab[i]);
	free(tab);
}

void	free_ctab(char **s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}
