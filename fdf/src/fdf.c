/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:22:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 13:36:17 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx			*color_key(int key, t_mlx *mlx)
{
	if (key == 82)
		mlx->pa->color_f = 0;
	if (key == 83)
		mlx->pa->color_f = 1;
	if (key == 84)
		mlx->pa->color_f = 2;
	if (key == 85)
		mlx->pa->color_f = 3;
	if (key == 86)
		mlx->pa->color_f = 4;
	if (key == 87)
		mlx->pa->color_f = 5;
	if (key == 88)
		mlx->pa->color_f = 6;
	if (key == 89)
		mlx->pa->color_f = 10;
	if (key == 91)
		mlx->pa->color_f = 11;
	if (key == 92)
		mlx->pa->color_f = 12;
	return (mlx);
}

int				hook_keydown(int key, t_mlx *mlx)
{
	mlx = color_key(key, mlx);
	if (key == 53)
	{
		mlxdel(mlx);
		exit(EXIT_SUCCESS);
	}
	mlx->pa->shape_z = (key == 47) ? mlx->pa->shape_z *= 1.5 : mlx->pa->shape_z;
	mlx->pa->shape_z = (mlx->pa->shape_z > (300)) ? 300 : mlx->pa->shape_z;
	mlx->pa->shape_z = (key == 43) ? mlx->pa->shape_z /= 1.5 : mlx->pa->shape_z;
	mlx->pa->move_y = (key == 126) ? mlx->pa->move_y -= 20 : mlx->pa->move_y;
	mlx->pa->move_y = (key == 125) ? mlx->pa->move_y += 20 : mlx->pa->move_y;
	mlx->pa->move_x = (key == 124) ? mlx->pa->move_x += 20 : mlx->pa->move_x;
	mlx->pa->move_x = (key == 123) ? mlx->pa->move_x -= 20 : mlx->pa->move_x;
	mlx->pa->proj = (key == 79) ? 0 : mlx->pa->proj;
	mlx->pa->proj = (key == 80) ? 1 : mlx->pa->proj;
	if (key == 10)
		return (mlx_clear_window(mlx->mlx, mlx->window));
	ft_min_max(&mlx);
	mlx_clear_window(mlx->mlx, mlx->window);
	main_draw(mlx);
	return (0);
}

static t_mlx	*init(char *title)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init()) ||
			(!(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
											WIN_HEIGHT, title))))
		return (mlxdel(mlx));
	if (!(mlx->map = ft_memalloc(sizeof(t_map))) ||
			!(mlx->points = ft_memalloc(sizeof(t_point**))) ||
			!(mlx->pa = ft_memalloc(sizeof(t_params))) ||
			!(mlx->map_param = ft_memalloc(sizeof(t_map_params))))
		return (mlxdel(mlx));
	mlx_def_init(&mlx);
	return (mlx);
}

static int		exit_hook(t_mlx *mlx)
{
	mlxdel(mlx);
	exit(0);
}

int				fdf(t_point **ar, t_map *map)
{
	t_mlx	*mlx;

	if (!(mlx = init("-= FDF =-")))
		ft_error_out("fc", 102);
	mlx->map = map;
	mlx->points = ar;
	ft_min_max(&mlx);
	main_draw(mlx);
	mlx_mouse_hook(mlx->window, hook_mouseyx, mlx);
	mlx_hook(mlx->window, 2, (1L << 0), hook_keydown, mlx);
	mlx_hook(mlx->window, 17, (1L << 17), exit_hook, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
