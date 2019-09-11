/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:11:02 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 19:07:38 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		next_fract(t_mlx *mlx)
{
	if (mlx->fractal < (MAX_FRACT - 1))
		mlx->fractal += 1;
	else
		mlx->fractal = 0;
	if (mlx->name_fractal)
		free(mlx->name_fractal);
	set_name_fractal(mlx);
	return ;
}

void		prev_fract(t_mlx *mlx)
{
	if (mlx->fractal > 0)
		mlx->fractal -= 1;
	else
		mlx->fractal = (MAX_FRACT - 1);
	if (mlx->name_fractal)
		free(mlx->name_fractal);
	set_name_fractal(mlx);
	return ;
}

void		fract_compl_init(t_fract_compl *f)
{
	(*f).newre = 0;
	(*f).newim = 0;
	(*f).oldre = 0;
	(*f).oldim = 0;
	return ;
}

int			exit_hook(t_mlx **mlx)
{
	exit(EXIT_SUCCESS);
}

void		fractol(t_mlx **mlx)
{
	load_fractal_img(mlx);
	mlx_hook((*mlx)->window, 6, (1L << 6), hook_mousemove, (*mlx));
	mlx_hook((*mlx)->window, 4, (1L << 2), hook_mousedown, (*mlx));
	mlx_hook((*mlx)->window, 2, (1L << 0), hook_keydown, mlx);
	mlx_hook((*mlx)->window, 17, (1L << 17), exit_hook, mlx);
	mlx_loop((*mlx)->mlx);
	return ;
}
