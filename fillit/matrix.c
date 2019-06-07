/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:49:56 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/03/19 20:05:39 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_alloc_matrix(int numb_fig, int side, int nb_possib)
{
	char	**m;
	int		r;
	int		i;

	m = (char **)malloc(nb_possib * sizeof(char *));
	if (m == NULL || nb_possib == 0 || numb_fig == 0 || side < 2)
		return (NULL);
	r = -1;
	while (++r < nb_possib)
	{
		m[r] = (char *)malloc((numb_fig + side * side) * sizeof(char));
		if (m[r] == NULL)
		{
			while (r--)
				free(m[r]);
			free(m);
			return (NULL);
		}
		i = -1;
		while (++i < numb_fig + side * side)
			m[r][i] = 0;
	}
	return (m);
}

static int	fill_matrix_fig(char **m, t_etrim p, int side)
{
	int		i;
	int		j;
	int		k;
	int		r;
	int		pos;

	r = 0;
	j = -1;
	while (++j < side - p.height + 1)
	{
		i = -1;
		while (++i < side - p.width + 1)
		{
			pos = side * j + i;
			k = -1;
			while (++k < 16 && pos + k / 4 * side + k % 4 < side * side)
				m[r][pos + k / 4 * side + k % 4] = (char)(p.tab[k]);
			r++;
		}
	}
	return (r);
}

char		**cr_mat(t_etrim *tetrim, int numb_fig, int side, int nb_possib)
{
	char	**matrix;
	char	**m_ptr;
	int		p;
	int		r;
	int		nb_filled_rows;

	if (!(matrix = ft_alloc_matrix(numb_fig, side, nb_possib)))
		return (NULL);
	m_ptr = matrix;
	p = 0;
	while (p < numb_fig)
	{
		nb_filled_rows = fill_matrix_fig(m_ptr, tetrim[p], side);
		r = 0;
		while (r < nb_filled_rows)
		{
			m_ptr[r][side * side + p] = 1;
			r++;
		}
		m_ptr += (nb_filled_rows);
		p++;
	}
	return (matrix);
}
