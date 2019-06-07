/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_topleft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:49:49 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/03/19 20:13:29 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_buf_top(t_etrim *tet)
{
	int		j;

	j = 0;
	while (j < 3)
	{
		(*tet).tab[j * 4 + 0] = (*tet).tab[j * 4 + 4];
		(*tet).tab[j * 4 + 1] = (*tet).tab[j * 4 + 5];
		(*tet).tab[j * 4 + 2] = (*tet).tab[j * 4 + 6];
		(*tet).tab[j * 4 + 3] = (*tet).tab[j * 4 + 7];
		j++;
	}
	(*tet).tab[12] = 0;
	(*tet).tab[13] = 0;
	(*tet).tab[14] = 0;
	(*tet).tab[15] = 0;
	return ;
}

void	move_buf_left(t_etrim *tet)
{
	int		j;

	j = 0;
	while (j < 3)
	{
		(*tet).tab[j] = (*tet).tab[j + 1];
		(*tet).tab[j + 4] = (*tet).tab[j + 5];
		(*tet).tab[j + 8] = (*tet).tab[j + 9];
		(*tet).tab[j + 12] = (*tet).tab[j + 13];
		j++;
	}
	(*tet).tab[3] = 0;
	(*tet).tab[7] = 0;
	(*tet).tab[11] = 0;
	(*tet).tab[15] = 0;
	return ;
}

int		check_pos_h(int *tab, int i)
{
	int height;
	int pos_h;

	pos_h = i;
	height = 1;
	while (pos_h + 4 < 16)
	{
		if (tab[(pos_h / 4) * 4 + 4] == 1 || tab[(pos_h / 4) * 4 + 5] == 1 \
			|| tab[(pos_h / 4) * 4 + 6] == 1 || tab[(pos_h / 4) * 4 + 7] == 1)
			height += 1;
		pos_h += 4;
	}
	return (height);
}

int		check_pos_w(int *tab, int i)
{
	int width;
	int pos_w;

	pos_w = i;
	width = 1;
	while ((pos_w + 1) < (4 * (i / 4 + 1)))
	{
		if (tab[(pos_w % 4) + 1] == 1 || tab[(pos_w % 4) + 5] == 1 \
			|| tab[(pos_w % 4) + 9] == 1 || tab[(pos_w % 4) + 13] == 1)
			width += 1;
		pos_w += 1;
	}
	return (width);
}
