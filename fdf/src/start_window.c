/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:24:21 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 13:41:32 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_def_init(t_mlx **mlx)
{
	(*mlx)->pa->proj = 0;
	(*mlx)->pa->color_f = 0;
	(*mlx)->pa->size_rect = 19;
	(*mlx)->pa->move_x = 0;
	(*mlx)->pa->move_y = 0;
	(*mlx)->pa->shape_z = 1;
	(*mlx)->map_param->x_max = 1;
	(*mlx)->map_param->x_min = 0;
	(*mlx)->map_param->y_max = 1;
	(*mlx)->map_param->y_min = 0;
	(*mlx)->map_param->h_colr_max = 1;
	(*mlx)->map_param->h_colr_min = 0;
	return ;
}

int		take_collor(int x)
{
	int collors_col[11];

	collors_col[0] = 0x000000;
	collors_col[1] = 0x00FFFF;
	collors_col[2] = 0x0000FF;
	collors_col[3] = 0xFF0000;
	collors_col[4] = 0xFFFF00;
	collors_col[5] = 0xFF00FF;
	collors_col[6] = 0x00FF00;
	collors_col[7] = 0xA52A2A;
	collors_col[8] = 0x800000;
	collors_col[9] = 0x1E90FF;
	collors_col[10] = 0xFFFFFF;
	return (collors_col[x]);
}

void	ft_start_window(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH - 130,
			WIN_HEIGHT - 80, 0x00FFFFFF, "> = Increase");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH - 130,
			WIN_HEIGHT - 65, 0x00FFFFFF, "< = Decrease");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH - 290,
			WIN_HEIGHT - 40, 0x00FFFFFF, "Mouse (scroll up) = Zoom in");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH - 310,
			WIN_HEIGHT - 25, 0x00FFFFFF, "Mouse (scroll down) = Zoom out");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH - (WIN_WIDTH - 20),
			WIN_HEIGHT - 70, 0x00FFFFFF, "RIGHT = Move right");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH - (WIN_WIDTH - 20),
			WIN_HEIGHT - 55, 0x00FFFFFF, "LEFT  = Move left");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH - (WIN_WIDTH - 20),
			WIN_HEIGHT - 40, 0x00FFFFFF, "UP    = Move up");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH - (WIN_WIDTH - 20),
			WIN_HEIGHT - 25, 0x00FFFFFF, "DOWN  = Move down");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH - (WIN_WIDTH - 300),
			WIN_HEIGHT - 40, 0x00FFFFFF, "NUM 1..6 = Colors");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH - (WIN_WIDTH - 300),
			WIN_HEIGHT - 25, 0x00FFFFFF, "NUM 7..9 = Spectrum");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH - (WIN_WIDTH - 300),
			WIN_HEIGHT - 70, 0x00FFFFFF, "NUM 0    = Default");
	return ;
}
