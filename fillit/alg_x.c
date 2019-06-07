/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:50:34 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/03/19 21:04:17 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	del_matrix(char **m, int nb_rows)
{
	int		r;

	r = 0;
	while (r < nb_rows)
	{
		free(m[r]);
		r++;
	}
	free(m);
}

static void	print_solution(char *s, int side, t_node **n, int **solution)
{
	int		l;

	l = -1;
	while (s[++l] != '\0')
	{
		ft_putchar(s[l]);
		if (!((l + 1) % side))
			ft_putchar('\n');
	}
	free((*n));
	free((*solution));
	free(s);
	return ;
}

static void	build_solution(t_node **n, int **sol, int nb_pieces, int side)
{
	char	*print;
	int		l;
	int		p;
	int		s;

	if (!(print = create_print(side)))
		return ;
	p = nb_pieces - 1;
	while (p > -1)
	{
		l = (*sol)[p--];
		while (!((*n)[l].c > side * side - 1))
			l = (*n)[l].r;
		s = (*n)[l].r;
		while (s != l)
		{
			s = (*n)[s].r;
			if (count_r_nodes((*n), side, (*sol)[(p + 1)]) < 2)
				print[(*n)[(*n)[s].l].c - 1] = '.';
			else
				print[(*n)[(*n)[s].l].c - 1] = (*n)[(*n)[l].c].letter;
		}
	}
	print_solution(print, side, n, sol);
	return ;
}

int			search(t_node *n, int *solv, int k, int side)
{
	int			row;
	int			col;

	col = find_col_side(n, side);
	if (k == 0 || col == 0)
		return (k);
	cover_col(n, col);
	row = n[col].d;
	while (row != col)
	{
		solv[k - 1] = row;
		cover_row(n, row);
		if (search(n, solv, k - 1, side) == 0)
			return (0);
		row = solv[k - 1];
		col = n[row].c;
		unrowver_row(n, row);
		row = n[row].d;
	}
	uncolver_col(n, col);
	return (k);
}

void		solve(t_etrim *tetrimin, int num_f, int side)
{
	int			nb_possible;
	int			numb_fig;
	char		**matrix;
	t_node		*link_nodes;
	int			*result;

	nb_possible = 0;
	numb_fig = 0;
	while (1)
	{
		numb_fig = add_figures(&tetrimin, num_f, side * side - 4 * num_f);
		nb_possible = possible_rows(tetrimin, numb_fig, side);
		matrix = cr_mat(tetrimin, numb_fig, side, nb_possible);
		link_nodes = create_link_nodes(matrix, numb_fig, side, nb_possible);
		del_matrix(matrix, nb_possible);
		give_letters(&link_nodes, num_f, side);
		result = (int *)malloc(numb_fig * sizeof(int));
		if (link_nodes != NULL && \
				search(link_nodes, result, numb_fig, side) == 0)
			return (build_solution(&link_nodes, &result, numb_fig, side));
		side++;
		free(result);
		free(link_nodes);
	}
}
