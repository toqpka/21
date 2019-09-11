/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:53:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 19:50:07 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			jul_compl(t_fract_compl f, int *i, int max_it, t_complex c)
{
	*i = -1;
	while (++(*i) < max_it)
	{
		f.oldre = f.newre;
		f.oldim = f.newim;
		f.newre = f.oldre * f.oldre - f.oldim * f.oldim + c.r;
		f.newim = 2 * f.oldre * f.oldim + c.i;
		if ((f.newre * f.newre + f.newim * f.newim) > 4)
			break ;
	}
	return ;
}

static t_color		go_jul(int x, int y, t_mlx *mlx, t_complex c)
{
	t_color			color;
	int				i;
	t_fract_compl	f;

	if (y >= WIN_HEIGHT * 96 / 100)
		color = set_color_f(94, 94, 255);
	else if (y >= WIN_HEIGHT * 92 / 100)
		color = set_color_f(189, 198, 255);
	else if (mlx->show_help && y >= WIN_HEIGHT * 59 /
			100 && x >= WIN_WIDTH * 80 / 100)
		color = set_color_f(189, 198, 255);
	else
	{
		f.newre = 1.5 * (x - WIN_WIDTH / 2) /
			(0.5 * mlx->zoom * WIN_WIDTH) + mlx->movex;
		f.newim = (y - WIN_HEIGHT / 2) /
			(0.5 * mlx->zoom * WIN_HEIGHT) + mlx->movey;
		jul_compl(f, &i, mlx->max_iter, c);
		color = palette_fact(i, mlx->pallete, mlx->max_iter);
	}
	image_set_pixel(mlx->img, x, y, color);
	return (color);
}

void				julia_f(t_mlx **mlx)
{
	t_complex		c;
	t_color			color;
	int				y;
	int				x;

	c.i = 2.0 * (1.0 - 2.0 * (*mlx)->mouse.y / WIN_HEIGHT);
	c.r = 2.0 * (2.0 * (*mlx)->mouse.x / WIN_WIDTH - 1.0);
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			color = go_jul(x, y, *mlx, c);
	}
	return ;
}
