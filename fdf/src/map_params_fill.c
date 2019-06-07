/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_params_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 06:33:20 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 13:11:59 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fill_x_min(t_mlx *mlx, double c_x)
{
	int		x_min;
	int		i;
	int		cur;

	i = 0;
	cur = -mlx->pa->size_rect - 5;
	x_min = mlx->map->w;
	while (i < mlx->map->w && cur < -mlx->pa->size_rect)
	{
		cur = (int)((WIN_WIDTH / 2) - mlx->pa->size_rect * (c_x - i) +
				mlx->pa->move_x);
		if (cur >= -mlx->pa->size_rect)
			x_min = i;
		i++;
	}
	return (x_min);
}

static int		fill_x_max(t_mlx *mlx, double c_x)
{
	int		x_max;
	int		i;
	int		cur;

	i = 0;
	cur = 1;
	x_max = -1;
	while (i < mlx->map->w && cur <= WIN_WIDTH)
	{
		cur = (int)((WIN_WIDTH / 2) - mlx->pa->size_rect * (c_x - i) +
				mlx->pa->move_x);
		if (cur < WIN_WIDTH)
			x_max = i;
		i++;
	}
	return (x_max);
}

static int		fill_y_min(t_mlx *mlx, double c_y)
{
	int		y_min;
	int		i;
	int		cur;

	i = 0;
	cur = -mlx->pa->size_rect - 5;
	y_min = mlx->map->h;
	while (i < mlx->map->h && cur < -mlx->pa->size_rect)
	{
		cur = (int)((WIN_HEIGHT / 2) - mlx->pa->size_rect * (c_y - i) +
				mlx->pa->move_y);
		if (cur >= -mlx->pa->size_rect)
			y_min = i;
		i++;
	}
	return (y_min);
}

static int		fill_y_max(t_mlx *mlx, double c_y)
{
	int		y_max;
	int		i;
	int		cur;

	i = 0;
	cur = 1;
	y_max = -1;
	while ((i < mlx->map->h) && (cur <= (WIN_HEIGHT - 85)))
	{
		cur = (int)((WIN_HEIGHT / 2) - mlx->pa->size_rect * (c_y - i) +
				mlx->pa->move_y);
		if (cur < (WIN_HEIGHT - 85))
			y_max = i;
		i++;
	}
	return (y_max);
}

void			ft_min_max(t_mlx **mlx)
{
	t_map_params	*grunt;
	double			centr_map_x;
	double			centr_map_y;

	if (!(grunt = (t_map_params*)malloc(sizeof(t_map_params))))
	{
		mlxdel(*mlx);
		ft_error_out("mpp", 100);
	}
	centr_map_x = (((*mlx)->map->w) - 1) / 2.00;
	centr_map_y = (((*mlx)->map->h) - 1) / 2.00;
	map_param_init((*mlx), &grunt);
	if ((*mlx)->pa->proj == 0)
	{
		grunt->x_min = fill_x_min(*mlx, centr_map_x);
		grunt->x_max = fill_x_max(*mlx, centr_map_x);
		grunt->y_min = fill_y_min(*mlx, centr_map_y);
		grunt->y_max = fill_y_max(*mlx, centr_map_y);
	}
	grunt->h_colr_min = fill_h_min(*mlx);
	grunt->h_colr_max = fill_h_max(*mlx);
	fill_map_to_mlx(mlx, grunt);
	free(grunt);
	return ;
}
