/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:49:28 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/03/19 21:02:29 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		possible_rows(t_etrim *tet, int num_f, int side)
{
	int		rows;
	int		i;

	i = 0;
	rows = 0;
	while (i < num_f)
	{
		if (side < tet[i].width || side < tet[i].height)
			return (-1);
		rows += ((side - tet[i].width + 1) * (side - tet[i].height + 1));
		i++;
	}
	return (rows);
}

int		add_figures(t_etrim **t, int num_f, int nb_blocks)
{
	int		i;

	if (nb_blocks < 0)
		return (-1);
	while (nb_blocks--)
	{
		(*t)[num_f].height = 1;
		(*t)[num_f].width = 1;
		(*t)[num_f].tab[0] = 2;
		i = 1;
		while (i < 16)
			(*t)[num_f].tab[i++] = 0;
		num_f++;
	}
	return (num_f);
}

int		minimum_grid(int num_f)
{
	int size;

	size = 2;
	while ((size * size) < (num_f * 4))
		size++;
	return (size);
}

char	*create_print(int side)
{
	char	*str;
	int		g;

	if (!(str = (char *)malloc(1 + side * side * sizeof(char))))
		return (NULL);
	g = -1;
	while (++g < side * side)
		str[g] = '.';
	str[g] = '\0';
	return (str);
}

int		count_r_nodes(t_node *n, int side, int l)
{
	int	jag;

	jag = 0;
	l = n[l].r;
	while (n[l].c < side * side + 1)
	{
		l = n[l].r;
		jag++;
	}
	return (jag);
}
