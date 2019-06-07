/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:13:42 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 13:05:56 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		mouse_btn1(t_mlx *mlx, int x, int y)
{
	t_coord		*cord;

	mlx->x1 = x;
	mlx->y1 = y;
	if (!(cord = (t_coord*)malloc(sizeof(t_coord))))
		ft_error_out("ms", 22);
	cord->x1 = mlx->x1;
	cord->y1 = mlx->y1;
	cord->x0 = mlx->x0;
	cord->y0 = mlx->y0;
	cord->color_start = atoi_color("0xFFFFFF");
	cord->color_end = atoi_color("0xFFFFFF");
	line_draw(mlx, cord);
	free(cord);
	return ;
}

static void		mouse_btn4(t_mlx *mlx)
{
	mlx->pa->size_rect = mlx->pa->size_rect + 2;
	if (mlx->pa->size_rect > 2147483640)
		mlx->pa->size_rect = 2147483639;
	ft_min_max(&mlx);
	mlx_clear_window(mlx->mlx, mlx->window);
	main_draw(mlx);
	return ;
}

static void		mouse_btn5(t_mlx *mlx)
{
	mlx->pa->size_rect = mlx->pa->size_rect - 2;
	if (mlx->pa->size_rect < 1)
		mlx->pa->size_rect = 1;
	ft_min_max(&mlx);
	mlx_clear_window(mlx->mlx, mlx->window);
	main_draw(mlx);
	return ;
}

int				hook_mouseyx(int button, int x, int y, t_mlx *mlx)
{
	if (button == 2)
	{
		mlx->x0 = x;
		mlx->y0 = y;
	}
	else
	{
		if (mlx->x0 == 0)
		{
			mlx->x0 = x;
			mlx->y0 = y;
		}
	}
	if (button == 1)
		mouse_btn1(mlx, x, y);
	if (button == 4)
		mouse_btn4(mlx);
	if (button == 5)
		mouse_btn5(mlx);
	return (0);
}
