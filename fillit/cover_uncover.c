/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cover_uncover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 21:05:24 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/03/19 20:56:53 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	cover_col(t_node *n, int col)
{
	int		i;
	int		j;

	n[n[col].r].l = n[col].l;
	n[n[col].l].r = n[col].r;
	i = n[col].d;
	while (i != col)
	{
		j = n[i].r;
		while (j != i)
		{
			n[n[j].d].u = n[j].u;
			n[n[j].u].d = n[j].d;
			n[n[j].c].num_elem--;
			j = n[j].r;
		}
		i = n[i].d;
	}
}

void	uncolver_col(t_node *n, int col)
{
	int		i;
	int		j;

	i = n[col].u;
	while (i != col)
	{
		j = n[i].l;
		while (j != i)
		{
			n[n[j].c].num_elem++;
			n[n[j].d].u = j;
			n[n[j].u].d = j;
			j = n[j].l;
		}
		i = n[i].u;
	}
	n[n[col].r].l = col;
	n[n[col].l].r = col;
}

void	cover_row(t_node *n, int row)
{
	int		j;

	j = n[row].r;
	while (j != row)
	{
		cover_col(n, n[j].c);
		j = n[j].r;
	}
}

void	unrowver_row(t_node *n, int row)
{
	int		j;

	j = n[row].l;
	while (j != row)
	{
		uncolver_col(n, n[j].c);
		j = n[j].l;
	}
}

int		find_col_side(t_node *n, int side)
{
	int		col;
	int		flag;
	int		side_check;

	side_check = 0;
	if (n && (side > 0))
	{
		col = n[0].r;
		flag = 0;
		while (col != 0 && !flag)
		{
			if ((col > side * side))
			{
				side_check = col;
				flag = 1;
			}
			col = n[col].r;
		}
	}
	return (side_check);
}
