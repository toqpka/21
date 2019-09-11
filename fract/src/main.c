/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:11:02 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 19:36:16 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		how_to_use(void)
{
	ft_putstr("Try to use this: ./fractol ");
	ft_putstr("[mandelbrot / julia / duobrot / triobrot / ship]\n");
	exit(1);
}

void			set_name_fractal(t_mlx *mlx)
{
	if (mlx->fractal == MANDELBROT)
		mlx->name_fractal = ft_strdup("Mandelbrot");
	if (mlx->fractal == JULIA)
		mlx->name_fractal = ft_strdup("Julia");
	if (mlx->fractal == DUOBROT)
		mlx->name_fractal = ft_strdup("Duobrot");
	if (mlx->fractal == TRIOBROT)
		mlx->name_fractal = ft_strdup("Triobrot");
	if (mlx->fractal == SHIP)
		mlx->name_fractal = ft_strdup("Ship");
	return ;
}

static void		parse_fract(t_mlx **mlx, char *av)
{
	if (ft_strcmp("mandelbrot", av) == 0)
		(*mlx)->fractal = MANDELBROT;
	else if (ft_strcmp("julia", av) == 0)
		(*mlx)->fractal = JULIA;
	else if (ft_strcmp("duobrot", av) == 0)
		(*mlx)->fractal = DUOBROT;
	else if (ft_strcmp("triobrot", av) == 0)
		(*mlx)->fractal = TRIOBROT;
	else if (ft_strcmp("ship", av) == 0)
		(*mlx)->fractal = SHIP;
	else
		how_to_use();
	set_name_fractal(*mlx);
	return ;
}

int				main(int ac, char **av)
{
	t_mlx		*mlx;

	if (ac != 2)
		how_to_use();
	else
	{
		init(&mlx);
		parse_fract(&mlx, av[1]);
		fractol(&mlx);
	}
	return (0);
}
