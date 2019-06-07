/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_params_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 07:01:18 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 13:16:13 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		map_param_init(t_mlx *mlx, t_map_params **grunt)
{
	(*grunt)->x_min = 0;
	(*grunt)->y_min = 0;
	(*grunt)->x_max = mlx->map->w;
	(*grunt)->y_max = mlx->map->h;
	return ;
}

void		fill_map_to_mlx(t_mlx **mlx, t_map_params *grunt)
{
	(*mlx)->map_param->x_max = grunt->x_max;
	(*mlx)->map_param->x_min = grunt->x_min;
	(*mlx)->map_param->y_max = grunt->y_max;
	(*mlx)->map_param->y_min = grunt->y_min;
	(*mlx)->map_param->h_colr_min = grunt->h_colr_min;
	(*mlx)->map_param->h_colr_max = grunt->h_colr_max;
	return ;
}

int			fill_h_min(t_mlx *mlx)
{
	int		h_colr_min;
	int		i;
	int		cur;

	i = 0;
	cur = 2147483646;
	h_colr_min = 2147483647;
	while (i < mlx->map->size)
	{
		cur = mlx->points[i]->z;
		if (cur < h_colr_min)
			h_colr_min = cur;
		i++;
	}
	return (h_colr_min);
}

int			fill_h_max(t_mlx *mlx)
{
	int		h_colr_max;
	int		i;
	int		cur;

	i = 0;
	cur = -2147483647;
	h_colr_max = -2147483648;
	while (i < mlx->map->size)
	{
		cur = mlx->points[i]->z;
		if (cur > h_colr_max)
			h_colr_max = cur;
		i++;
	}
	return (h_colr_max);
}
