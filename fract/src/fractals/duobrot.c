/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duobrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:04:33 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 19:46:45 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		duo_compl(t_fract_compl f, int *i, int max_it)
{
	*i = -1;
	while (++(*i) < max_it)
	{
		f.oldre = f.newre;
		f.oldim = f.newim;
		f.newre = f.oldre * f.oldre * f.oldre -
			3 * f.oldre * f.oldim * f.oldim + f.r;
		f.newim = 3 * f.oldre * f.oldre * f.oldim -
			f.oldim * f.oldim * f.oldim + f.i;
		if ((f.newre * f.newre + f.newim * f.newim) > 4)
			break ;
	}
	return ;
}

static t_color	go_duo(int x, int y, t_mlx *mlx)
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
		f.r = 1.5 * (x - WIN_WIDTH / 2.0) /
			(0.5 * mlx->zoom * WIN_WIDTH) + mlx->movex;
		f.i = (y - WIN_HEIGHT / 2.0) /
			(0.5 * mlx->zoom * WIN_HEIGHT) + mlx->movey;
		fract_compl_init(&f);
		duo_compl(f, &i, mlx->max_iter);
		color = palette_fact(i, mlx->pallete, mlx->max_iter);
	}
	image_set_pixel(mlx->img, x, y, color);
	return (color);
}

void			duobrot_f(t_mlx **mlx)
{
	t_color			color;
	int				x;
	int				y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			color = go_duo(x, y, *mlx);
	}
	return ;
}
