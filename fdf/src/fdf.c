/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:22:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 00:35:49 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_min_max(t_mlx **mlx)
{
	double centr_map_x;
	double centr_map_y;
	//some optimiz
	int		i;
	int		cur;
	int		cur_y;
	int		cur_y2;
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	int		h_colr_min;
	int		h_colr_max;


	int previous_x;
  int previous_y;

	centr_map_x = (((*mlx)->map->w) - 1) / 2.00;
	centr_map_y = (((*mlx)->map->h) - 1) / 2.00;

x_min = 0;
y_min = 0;
x_max = (*mlx)->map->w;
y_max = (*mlx)->map->h;
if ((*mlx)->proj == 0)
{
	i = 0;
	cur = -(*mlx)->size_rect-5;
	x_min = (*mlx)->map->w;
	while (i < (*mlx)->map->w && cur < -(*mlx)->size_rect)
	{
		cur = (int)((WIN_WIDTH / 2) - (*mlx)->size_rect * (centr_map_x - i) + (*mlx)->move_x);
		if (cur >= -(*mlx)->size_rect)
			x_min = i;
		i++;
	}

	i = 0;
	cur = 1;
	x_max = -1;
	while (i < (*mlx)->map->w && cur <= WIN_WIDTH)
	{
		cur = (int)((WIN_WIDTH / 2) - (*mlx)->size_rect * (centr_map_x - i) + (*mlx)->move_x);
		if (cur < WIN_WIDTH)
			x_max = i;
		i++;
	}

	i = 0;
	cur = -(*mlx)->size_rect-5;
	y_min = (*mlx)->map->h;
	while (i < (*mlx)->map->h && cur < -(*mlx)->size_rect)
	{
		cur = (int)((WIN_HEIGHT / 2) - (*mlx)->size_rect * (centr_map_y - i) + (*mlx)->move_y);
		if (cur >= -(*mlx)->size_rect)
			y_min = i;
		i++;
	}

	i = 0;
	cur = 1;
	y_max = -1;
	while ((i < (*mlx)->map->h) && (cur <= (WIN_HEIGHT - 85)))
	{
		cur = (int)((WIN_HEIGHT / 2) - (*mlx)->size_rect * (centr_map_y - i) + (*mlx)->move_y);
		if (cur < (WIN_HEIGHT - 85))
			y_max = i;
		i++;
	}
}
	i = 0;
	cur = -2147483647;
	h_colr_max = -2147483648;
	while (i < (*mlx)->map->size)
	{
		cur = (*mlx)->points[i]->z;
		//printf("\nZ=%d     h_cur=%d",(*mlx)->points[i]->z,h_colr_max);
		if (cur > h_colr_max)
			h_colr_max = cur;
		i++;
	}

	i = 0;
	cur = 2147483646;
	h_colr_min = 2147483647;
	while (i < (*mlx)->map->size)
	{
		cur = (*mlx)->points[i]->z;
		if (cur < h_colr_min)
			h_colr_min = cur;
		i++;
	}
	(*mlx)->x_max = x_max;
	(*mlx)->x_min = x_min;
	(*mlx)->y_max = y_max;
	(*mlx)->y_min = y_min;
	(*mlx)->h_colr_min = h_colr_min;
	(*mlx)->h_colr_max = h_colr_max;
	return ;
}

t_mlx *color_key(int key,t_mlx *mlx)
{
	if (key == 82)
	{
		mlx->start_from = 1;
		mlx->color_f = 0;
		//mlx->size_rect = 19;
		//mlx->move_y = 0;
		//mlx->move_x = 0;
		//mlx->shape_z = 1;
		//mlx->rot_x = 0;
		//mlx->rot_x_gg = 0;
	}
	if (key == 83)
		mlx->color_f = 1;
	if (key == 84)
		mlx->color_f = 2;
	if (key == 85)
		mlx->color_f = 3;
	if (key == 86)
		mlx->color_f = 4;
	if (key == 87)
		mlx->color_f = 5;
	if (key == 88)
		mlx->color_f = 6;
	if (key == 89)
		mlx->color_f = 10;
	if (key == 91)
		mlx->color_f = 11;
	if (key == 92)
		mlx->color_f = 12;
	return (mlx);
}

t_mlx *rotate_key(int key,t_mlx *mlx)
{
	if (key == 0)
	{
		//a
		mlx->rot_x_gg += 1;
		mlx->rot_x = 6.2*sin(3.14159265/180*mlx->rot_x_gg);
	}
	if (key == 1)
	{
		//s
	}
	if (key == 2)
	{
		mlx->rot_x_gg -= 1;
		mlx->rot_x = 6.2*sin(3.14159265/180*mlx->rot_x_gg);
	}
	if (key == 13)
	{
		//w
	}
	//printf("\n dich gg=%g   rot_x=%g",mlx->rot_x_gg, mlx->rot_x);
	return (mlx);
}

int		hook_keydown(int key, t_mlx *mlx)
{
	//ft_putnbr(key);
	mlx = color_key(key, mlx);
	mlx = rotate_key(key, mlx);
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 47)
		mlx->shape_z *= 1.5;
	if (key == 43)
		mlx->shape_z /= 1.5;
	if (key == 126)
		mlx->move_y -= 20;
	if (key == 125)
		mlx->move_y += 20;
	if (key == 124)
		mlx->move_x += 20;
	if (key == 123)
		mlx->move_x -= 20;
	if (key == 79)
		mlx->proj = 0;
	if (key == 80)
		mlx->proj = 1;
	if (key == 10)
			return(mlx_clear_window(mlx->mlx, mlx->window));
	ft_min_max(&mlx);
	mlx_clear_window(mlx->mlx, mlx->window);
	main_draw(mlx);
	return (0);
}

int		hook_mouseyx(int button, int x, int y, t_mlx *mlx)
{
	t_coord   *cord;

  cord = (t_coord*)malloc(sizeof(t_coord));
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
	{
		mlx->x1 = x;
		mlx->y1 = y;

	  cord->x1 = mlx->x1;
	  cord->y1 = mlx->y1;
	  cord->x0 = mlx->x0;
	  cord->y0 = mlx->y0;
		cord->color_start = atoi_color("0xFFFFFF");
		cord->color_end = atoi_color("0xFFFFFF");
		line_draw(mlx, cord);
		free(cord);
	}
	if (button == 4)
	{
		mlx->size_rect = mlx->size_rect + 1;
		ft_min_max(&mlx);
		mlx_clear_window(mlx->mlx, mlx->window);
		main_draw(mlx);
	}
	if (button == 5)
	{
		mlx->size_rect = mlx->size_rect - 1;
		if (mlx->size_rect < 1)
			mlx->size_rect = 1;
		ft_min_max(&mlx);
		mlx_clear_window(mlx->mlx, mlx->window);
		main_draw(mlx);
	}
	return (0);
}

static t_mlx		*mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	ft_memdel((void **)&mlx);
	return (NULL);
}

static t_mlx		*init(char *title)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init()) || !(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, title)))
    return (mlxdel(mlx));
	mlx->map = ft_memalloc(sizeof(t_map));
	mlx->points = ft_memalloc(sizeof(t_point**));
	mlx->move_x = 0;
	mlx->move_y = 0;
	mlx->shape_z = 1;
	mlx->x_max = 1;
	mlx->x_min = 0;
	mlx->y_max = 1;
	mlx->y_min = 0;
	mlx->h_colr_max = 1;
	mlx->h_colr_min = 0;
	mlx->rot_x = 0;
	mlx->rot_x_gg = 0;
	mlx->start_from = 0;
	//mlx->proj = (char)malloc(sizeof(char*));
	return (mlx);
}

static int	exit_hook(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
	return (0);
}


int   fdf(t_point **ar, t_map *map)
{
  t_mlx   *mlx;
	int			i;

	//some  output
	ft_putstr("Map size: ");
	ft_putnbr(map->h);
	ft_putstr("x");
	ft_putnbr(map->w);
	ft_putstr("  size=");
	ft_putnbr(map->size);
	ft_putstr("\n");

  mlx = init("FDF - tests");
	mlx->size_rect = 19;
	mlx->map = map;
	mlx->points = ar;
	ft_min_max(&mlx);

	//NEEED TO DELETE OUTPUT check
	//i = 0;
	//while (i < (mlx->map->w * mlx->map->h))
	//{
		//printf("\n#%d X=%d Y=%d Z=%d  Color=%s\n", i, mlx->points[i]->x, mlx->points[i]->y, mlx->points[i]->z, mlx->points[i]->color);
		//i++;
	//}

  main_draw(mlx);
	mlx_mouse_hook(mlx->window, hook_mouseyx, mlx);
	//mlx_key_hook (mlx->window, funct, 0);
	mlx_hook(mlx->window, 2, (1L << 0), hook_keydown, mlx);
	mlx_hook(mlx->window, 17, (1L << 17), exit_hook, mlx);
  mlx_loop(mlx->mlx);
  return (0);
}
