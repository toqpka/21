/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:49:40 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/03/26 19:01:14 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		give_letters(t_node **link_nodes, int num_f, int side)
{
	int		col;

	if (link_nodes != NULL && *link_nodes != NULL)
	{
		col = ((*link_nodes)[0]).r;
		while (col != 0)
		{
			if (col > side * side)
			{
				if (col <= num_f + side * side)
					(*link_nodes)[col].letter = 'A' + col - (side * side) - 1;
				else
					(*link_nodes)[col].letter = '.';
			}
			col = (*link_nodes)[col].r;
		}
	}
}

static void	build_heads_of_column(t_node *n, int nb_col, int nb_possible)
{
	int		i;

	i = -1;
	while (++i < (5 * nb_possible + nb_col + 1))
		n[i].c = 0;
	i = 1;
	while (i < nb_col)
	{
		n[i].l = i - 1;
		n[i - 1].r = i;
		n[i].c = i;
		n[i].num_elem = 0;
		i++;
	}
	n[0].l = nb_col;
	n[nb_col].r = 0;
	return ;
}

static int	build_r_and_l(t_node *n, char **m, int start_node, int r)
{
	int		c;
	int		i;
	int		j;
	int		flag;

	flag = 0;
	i = start_node;
	c = 0;
	j = 0;
	while (j < 5)
	{
		if (m[r][c++] != 0)
		{
			n[i++].c = c;
			if (flag == 1)
				break ;
			if (j == 0)
				((m[r][c - 1] == 2) ? link_r_and_l(n, i - 1, 2, &flag) :\
					link_r_and_l(n, i - 1, 5, &flag));
			j++;
		}
	}
	return (flag == 1 ? 2 : 5);
}

static void	build_u_and_d(t_node *n, int c, int nb_col, int nb_possible)
{
	int		r;
	int		prev;

	r = nb_col - 1;
	while (++r < (5 * nb_possible + nb_col + 1))
	{
		if (n[r].c == c)
		{
			n[c].num_elem++;
			if (n[c].num_elem == 1)
			{
				n[c].d = r;
				n[r].u = c;
			}
			else
			{
				n[r].u = prev;
				n[prev].d = r;
			}
			prev = r;
		}
	}
	n[prev].d = c;
	n[c].u = prev;
	return ;
}

t_node		*create_link_nodes(char **m, int numb_fig, int side, int nb_possib)
{
	t_node	*n;
	int		r;
	int		c;
	int		start_node;
	int		nb_col;

	nb_col = side * side + numb_fig + 1;
	n = (t_node *)malloc((nb_col + 1 + (5 * nb_possib)) * sizeof(t_node));
	if (n == NULL || m == NULL || numb_fig < 1 || nb_possib < 1 || nb_col < 5)
		return (NULL);
	links_nodes_to_null(n, nb_col, nb_possib);
	build_heads_of_column(n, nb_col, nb_possib);
	r = -1;
	start_node = nb_col;
	while (++r < nb_possib)
		start_node += build_r_and_l(n, m, start_node, r);
	c = 0;
	while (++c < nb_col)
		build_u_and_d(n, c, nb_col, nb_possib);
	return (n);
}
