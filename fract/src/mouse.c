/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:35:27 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 19:37:24 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	if (button == 5)
	{
		zoom(x, y, &mlx, 1 / ZOOM);
		load_fractal_img(&mlx);
	}
	else if (button == 4)
	{
		zoom(x, y, &mlx, ZOOM);
		load_fractal_img(&mlx);
	}
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	if ((x >= 0 && x <= WIN_WIDTH) && (y >= 0 && y <= WIN_HEIGHT))
	{
		if (!(mlx->jul_pause))
		{
			mlx->mouse.x = x;
			mlx->mouse.y = y;
			load_fractal_img(&mlx);
		}
	}
	return (0);
}
