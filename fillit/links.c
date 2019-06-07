/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:50:02 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/03/26 19:04:29 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		link_r_and_l(t_node *n, int i, int nb_block, int *flag)
{
	int		j;

	j = 0;
	while (j < nb_block)
	{
		if (j < nb_block - 1)
			n[i + j].r = i + j + 1;
		if (j > 0)
			n[i + j].l = i + j - 1;
		j++;
	}
	n[i].l = i + nb_block - 1;
	n[i + nb_block - 1].r = i;
	if (nb_block == 2)
		*flag = 1;
	return (nb_block);
}

void	link_u_and_d(t_node *n, int i, int j)
{
	n[i].d = j;
	n[j].u = i;
	return ;
}

void	links_nodes_to_null(t_node *n, int nb_col, int nb_possib)
{
	int		r;

	r = -1;
	while (++r < (nb_col + 1 + (5 * nb_possib)))
	{
		n[r].l = 0;
		n[r].r = 0;
		n[r].u = 0;
		n[r].d = 0;
		n[r].c = 0;
		n[r].num_elem = 0;
		n[r].letter = 0;
	}
	return ;
}
