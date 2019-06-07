/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:55:21 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 12:22:07 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		pre_line_draw(t_coord **cord, t_mlx *mlx)
{
	(*cord)->x0 += mlx->pa->move_x;
	(*cord)->y0 += mlx->pa->move_y;
	(*cord)->x1 += mlx->pa->move_x;
	(*cord)->y1 += mlx->pa->move_y;
	line_draw(mlx, (*cord));
	return ;
}

static void		ft_draw_fig(t_coord **cord, t_mlx *mlx, int g)
{
	if (mlx->points[g + 1]->x > mlx->points[g]->x)
	{
		if (!((*cord) = creat_coord(mlx, g, g + 1)))
			ft_error_out("dr", 30);
		pre_line_draw(cord, mlx);
	}
	if (mlx->points[g]->y < (mlx->map->h - 1))
	{
		if (!((*cord) = creat_coord(mlx, g, mlx->points[g]->x_next_line)))
			ft_error_out("dr", 36);
		pre_line_draw(cord, mlx);
	}
	return ;
}

void			main_draw(t_mlx *mlx)
{
	t_coord		*cord;
	int			g;
	double		centr_map_x;
	double		centr_map_y;

	centr_map_x = ((mlx->map->w) - 1) / 2.00;
	centr_map_y = ((mlx->map->h) - 1) / 2.00;
	if (!(cord = (t_coord*)malloc(sizeof(t_coord))))
		ft_error_out("dr", 52);
	ft_start_window(mlx);
	if ((centr_map_x) > 0)
	{
		g = -1;
		while ((++g + 1) < (mlx->map->size))
		{
			if ((mlx->points[g]->x <= mlx->map_param->x_max) &&\
					(mlx->points[g]->x >= mlx->map_param->x_min) &&\
					(mlx->points[g]->y <= mlx->map_param->y_max) &&\
					(mlx->points[g]->y >= mlx->map_param->y_min))
				ft_draw_fig(&cord, mlx, g);
		}
	}
	free(cord);
	return ;
}
