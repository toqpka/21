/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:50:23 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/03/19 19:57:31 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		move_up(t_etrim *tet)
{
	int	i;

	i = 0;
	while ((*tet).tab[0] == 0 && (*tet).tab[1] == 0 \
			&& (*tet).tab[2] == 0 && (*tet).tab[3] == 0)
	{
		if ((*tet).tab[i * 4] == 0 && (*tet).tab[i * 4 + 1] == 0 \
			&& (*tet).tab[i * 4 + 2] == 0 && (*tet).tab[i * 4 + 3] == 0)
		{
			move_buf_top(&(*tet));
			i = 0;
		}
		i++;
	}
	return ;
}

static void		move_left(t_etrim *tet)
{
	int		i;

	i = 0;
	while ((*tet).tab[0] == 0 && (*tet).tab[4] == 0 \
			&& (*tet).tab[8] == 0 && (*tet).tab[12] == 0)
	{
		if ((*tet).tab[i] == 0 && (*tet).tab[i + 4] == 0 \
			&& (*tet).tab[i + 8] == 0 && (*tet).tab[i + 12] == 0)
		{
			move_buf_left(&(*tet));
			i = 0;
		}
		i++;
	}
	return ;
}

static int		find_w(int *tab)
{
	int		width;
	int		width_m;
	int		i;
	int		j;

	width = 0;
	width_m = 0;
	j = -1;
	while (++j < 4)
	{
		i = j % 4;
		while (i < 16)
		{
			if (tab[i] == 1)
			{
				width = check_pos_w(tab, i);
				if (width_m < width)
					width_m = width;
			}
			i += 4;
		}
	}
	return (width_m);
}

static int		find_h(int *tab)
{
	int		height;
	int		height_m;
	int		i;

	height = 0;
	i = -1;
	height_m = 0;
	while (++i < 16)
	{
		if (tab[i] == 1)
		{
			height = check_pos_h(tab, i);
			if (height_m < height)
				height_m = height;
		}
	}
	return (height_m);
}

t_etrim			*create_tetrim(int **tab, int nb_fig)
{
	t_etrim		*tetrim;
	int			i;
	int			k;

	if (!(tetrim = (t_etrim *)malloc(sizeof(t_etrim) * 200)))
		return (NULL);
	k = 0;
	while (k < nb_fig)
	{
		(tetrim[k]).height = find_h(tab[k]);
		(tetrim[k]).width = find_w(tab[k]);
		(tetrim[k]).letter = 'A' + k;
		i = 0;
		while (i < 16)
		{
			(tetrim[k]).tab[i] = tab[k][i];
			i++;
		}
		move_left(&tetrim[k]);
		move_up(&tetrim[k]);
		k++;
	}
	return (tetrim);
}
