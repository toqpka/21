/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 03:24:48 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 14:22:15 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			show_load_2(int *cur_l, int *perc_l, int y, int h)
{
	int		load_perc;

	if (h != 0)
		load_perc = y * 100 / h;
	if (*cur_l < load_perc)
	{
		*cur_l = load_perc;
		if (!(*cur_l % *perc_l) && *perc_l < 84)
		{
			*perc_l += 15;
			ft_putstr("\rCreating map ["COLOR_YELLOW);
			ft_putnbr(*perc_l);
			ft_putstr("%"COLOR_RESET"]");
		}
	}
	return ;
}

static void		show_load(void)
{
	ft_putstr("\rCreating map ["COLOR_YELLOW);
	ft_putnbr(5);
	ft_putstr("%"COLOR_RESET"]");
	return ;
}

void			ft_fill_map(t_map **map, int y, int x_max,
		unsigned long int size_m)
{
	(*map)->h = y;
	(*map)->w = x_max;
	(*map)->size = size_m;
	return ;
}

static void		ft_ff_p(char ***w_str, int *k, int g, t_point ****opph)
{
	int		i;
	char	**col_str;

	i = 0;
	while ((*w_str)[i])
	{
		(**opph)[*k] = (t_point*)malloc(sizeof(t_point));
		if (!(col_str = ft_strsplit((*w_str)[i], ',')))
			ft_error_out("rfc", 61);
		if (!ft_is_valid(col_str[0]))
			ft_error_out("err", 404);
		(**opph)[*k]->z = ft_atoi(col_str[0]);
		(**opph)[*k]->color = atoi_color(col_str[1]);
		(**opph)[*k]->x = i;
		(**opph)[*k]->y = g;
		free((*w_str)[i++]);
		*k += 1;
	}
	free((*w_str));
	i = 0;
	while (col_str[i])
		free(col_str[i++]);
	free(col_str);
	return ;
}

void			ft_fill_points(t_point ***opph, t_list *tmp, t_map *map)
{
	int		g;
	int		k;
	char	**w_str;

	g = 0;
	k = 0;
	show_load();
	while (tmp)
	{
		if (!(w_str = ft_strsplit(tmp->content, ' ')))
			ft_error_out("rfc", 89);
		else
			ft_ff_p(&w_str, &k, g++, &opph);
		tmp = tmp->next;
	}
	return ;
}
