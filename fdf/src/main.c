/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:11:02 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 13:41:01 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		how_to_use(void)
{
	ft_putstr("try to use this: ./fdf <filename>\n");
	return ;
}

t_point			**add_next_x(t_point **pts, t_map *map)
{
	int		i;
	int		nx;
	int		perc;
	int		cur_load;

	i = 0;
	nx = 0;
	perc = 10;
	cur_load = 0;
	while (i < map->size && pts[i]->y < map->h - 1)
	{
		nx = i;
		pts[i]->x_next_line = i;
		if (pts[i]->y < map->h - 1)
		{
			while (nx + 1 < map->size && (pts[nx + 1]->x > pts[nx]->x))
				nx++;
			if (pts[i]->x == pts[nx + (pts[nx]->x - pts[(nx) - i]->x) + 1]->x)
				pts[i]->x_next_line = nx + (pts[nx]->x - pts[(nx) - i]->x) + 1;
		}
		show_load_2(&cur_load, &perc, pts[i++]->y, map->h);
	}
	ft_putstr("\rCreating map ["COLOR_GREEN"100%"COLOR_RESET"]\n");
	return (pts);
}

int				main(int ac, char **av)
{
	t_point		**ar;
	t_map		*map;

	if (ac != 2)
		how_to_use();
	else
	{
		if (!(map = (t_map*)malloc(sizeof(t_map))))
			ft_error_out("mc", 59);
		ar = add_next_x(ft_read(av[1], map), map);
		if (ar)
			fdf(ar, map);
		else
			ft_error_out("mc", 64);
	}
	return (0);
}
