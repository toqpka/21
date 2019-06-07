/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tabs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:50:26 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/03/19 21:04:46 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_num(char *str)
{
	int		num;
	int		i;
	int		count_sharp;

	i = -1;
	count_sharp = 0;
	while (str[++i])
	{
		if (str[i] == '#')
			count_sharp++;
	}
	num = count_sharp / 4;
	return (num);
}

static int	**some_tab(int nb_fig)
{
	int		**tab;
	int		c;

	if (!(tab = (int **)malloc(sizeof(int*) * (nb_fig))))
		return (NULL);
	c = 0;
	while (c < nb_fig)
	{
		tab[c] = (int *)malloc(sizeof(int) * (16));
		c++;
	}
	if (c >= nb_fig)
		return (tab);
	else
	{
		while (c != -1)
			free(tab[c--]);
		free(tab);
		return (NULL);
	}
}

static int	**fill_tab(char *str, int **tab, int nb_fig)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] && (i / 21 < nb_fig))
	{
		if (((i - (i / 21) + 1) % 5) && ((i - (i / 21)) / 20 - (i / 21 + 1)))
		{
			if (str[i] == '#')
				tab[i / 21][k] = 1;
			else
				tab[i / 21][k] = 0;
			k++;
		}
		if (k > 15)
			k = 0;
		i++;
	}
	return (tab);
}

t_etrim		*create_tet_tabs(char *str)
{
	int			**tab;
	int			nb_fig;
	t_etrim		*tetrim;
	int			i;

	nb_fig = count_num(str);
	tab = some_tab(nb_fig);
	if (tab == NULL)
		return (NULL);
	fill_tab(str, tab, nb_fig);
	tetrim = create_tetrim(tab, nb_fig);
	if (tetrim)
	{
		i = 0;
		while (i < nb_fig)
			free(tab[i++]);
		free(tab);
	}
	return (tetrim);
}
