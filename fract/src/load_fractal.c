/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 22:07:02 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 20:30:28 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			show_help(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 82 / 100,
		(WIN_HEIGHT) * 60 / 100, 0x000000, "NUM * : ++iteration");
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 82 / 100,
		(WIN_HEIGHT) * 63 / 100, 0x000000, "NUM / : --iteration");
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 82 / 100,
		(WIN_HEIGHT) * 66 / 100, 0x000000, "NUM + : zoom in");
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 82 / 100,
		(WIN_HEIGHT) * 69 / 100, 0x000000, "NUM - : zoom out");
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 82 / 100,
		(WIN_HEIGHT) * 72 / 100, 0x000000, "NUM 8 : prev color");
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 82 / 100,
		(WIN_HEIGHT) * 75 / 100, 0x000000, "NUM 9 : next color");
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 82 / 100,
		(WIN_HEIGHT) * 78 / 100, 0x000000, "NUM 3 : prev fractol");
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 82 / 100,
		(WIN_HEIGHT) * 81 / 100, 0x000000, "NUM 2 : next fractol");
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 82 / 100,
		(WIN_HEIGHT) * 84 / 100, 0x000000, "Arrows: move");
	if (mlx->fractal == JULIA)
		mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 82 / 100,
			(WIN_HEIGHT) * 87 / 100, 0x000000, "Space : pause");
	return ;
}

static void			help_put_text(t_mlx *mlx)
{
	char	*s;

	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 1 / 100,
		(WIN_HEIGHT) * 92 / 100, 0x000000, "X:");
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 1 / 100,
		(WIN_HEIGHT) * 96 / 100, 0xFFFFFF, "Y:");
	s = ft_itoa(mlx->mouse.x);
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 3 / 100,
		(WIN_HEIGHT) * 92 / 100, 0x000000, s);
	free(s);
	s = ft_itoa(mlx->mouse.y);
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 3 / 100,
		(WIN_HEIGHT) * 96 / 100, 0xFFFFFF, s);
	free(s);
	if (mlx->jul_pause)
		mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 10 / 100,
			(WIN_HEIGHT) * 92 / 100, 0x000000, "Paused");
}

static void			put_text(t_mlx *mlx)
{
	char		*s;

	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 65 / 100,
		(WIN_HEIGHT) * 92 / 100, 0x000000, "NUM 7 : Show_Help");
	if (mlx->show_help)
		show_help(mlx);
	if (mlx->fractal == JULIA)
		help_put_text(mlx);
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 83 / 100,
		(WIN_HEIGHT) * 96 / 100, 0xFFFFFF, "Max iter:");
	s = ft_itoa(mlx->max_iter);
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 90 / 100,
		(WIN_HEIGHT) * 96 / 100, 0xFFFFFF, s);
	free(s);
	mlx_string_put(mlx->mlx, mlx->window, (WIN_WIDTH) * 48 / 100,
		(WIN_HEIGHT) * 96 / 100, 0xFFFFFF, mlx->name_fractal);
	return ;
}

void				load_fractal_img(t_mlx **mlx)
{
	if ((*mlx)->fractal == MANDELBROT)
		mandelbrot_f(mlx);
	else if ((*mlx)->fractal == JULIA)
		julia_f(mlx);
	else if ((*mlx)->fractal == DUOBROT)
		duobrot_f(mlx);
	else if ((*mlx)->fractal == TRIOBROT)
		triobrot_f(mlx);
	else if ((*mlx)->fractal == SHIP)
		ship_f(mlx);
	else
		ft_print_error_exit(&ft_putendl, "Error");
	mlx_put_image_to_window((*mlx)->mlx, (*mlx)->window,
		(*mlx)->img->image, 0, 0);
	put_text(*mlx);
	return ;
}
