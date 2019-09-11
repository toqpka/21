/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:34:12 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 19:12:41 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_struct(t_mlx *mlx)
{
	mlx->fractal = -1;
	mlx->name_fractal = NULL;
	mlx->max_iter = 50;
	mlx->zoom = 1.0;
	mlx->movex = 0.0;
	mlx->movey = 0.0;
	mlx->pallete = 1;
	mlx->mouse.x = 0;
	mlx->mouse.y = 0;
	mlx->jul_pause = 0;
	mlx->show_help = 0;
	return ;
}

static void		init_mlx(t_mlx **mlx)
{
	if (!((*mlx) = ft_memalloc(sizeof(t_mlx))))
		ft_print_error_exit(&ft_putendl, "Error");
	if (!((*mlx)->mlx = mlx_init()) ||
			!((*mlx)->window = mlx_new_window((*mlx)->mlx, WIN_WIDTH,
					WIN_HEIGHT, WIN_TITLE)))
		ft_print_error_exit(&ft_putendl, "Error");
	(*mlx)->img = new_image(*mlx);
	init_struct(*mlx);
	return ;
}

void			init(t_mlx **m)
{
	init_mlx(m);
	return ;
}
