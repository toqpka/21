/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:04:38 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 19:20:34 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	next_pallete(t_mlx *mlx)
{
	if (mlx->pallete < (MAX_COLOR - 1))
		mlx->pallete += 1;
	else
		mlx->pallete = 0;
	return ;
}

void	prev_pallete(t_mlx *mlx)
{
	if (mlx->pallete > 0)
		mlx->pallete -= 1;
	else
		mlx->pallete = (MAX_COLOR - 1);
	return ;
}

void	reset_fract(t_mlx *mlx)
{
	mlx->max_iter = 50;
	mlx->zoom = 1.0;
	mlx->movex = 0.0;
	mlx->movey = 0.0;
	return ;
}

int		hook_keydown(int key, t_mlx **mlx)
{
	hook_first(key, mlx);
	if (key == TOP)
		(*mlx)->movey += 0.1 / (*mlx)->zoom;
	if (key == DOWN)
		(*mlx)->movey -= 0.1 / (*mlx)->zoom;
	if (key == LEFT)
		(*mlx)->movex += 0.1 / (*mlx)->zoom;
	if (key == RIGHT)
		(*mlx)->movex -= 0.1 / (*mlx)->zoom;
	if (key == NUM_MINUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, mlx, 1 / ZOOM);
	if (key == NUM_PLUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, mlx, ZOOM);
	if (key == NUM_DIV)
		(*mlx)->max_iter--;
	if (key == NUM_MULT)
		(*mlx)->max_iter++;
	if (ACTIVE_KEY(key))
		load_fractal_img(mlx);
	return (0);
}
