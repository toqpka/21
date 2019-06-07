/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:58:45 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 12:21:40 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		coord_params(t_coord **new_coord, t_mlx *mlx,
		t_vec *vec, t_figure *fig)
{
	if (mlx->pa->proj == 0)
	{
		(*new_coord)->x0 = take_cart_x(vec->num1, mlx, fig->centr_x);
		(*new_coord)->y0 = take_cart_y(vec->num1, mlx, fig->centr_y);
		(*new_coord)->x1 = take_cart_x(vec->num2, mlx, fig->centr_x);
		(*new_coord)->y1 = take_cart_y(vec->num2, mlx, fig->centr_y);
	}
	else if (mlx->pa->proj == 1)
	{
		(*new_coord)->x0 = take_cart_x(vec->num1, mlx, fig->centr_x);
		(*new_coord)->y0 = take_cart_y(vec->num1, mlx, fig->centr_y);
		(*new_coord)->x1 = take_cart_x(vec->num2, mlx, fig->centr_x);
		(*new_coord)->y1 = take_cart_y(vec->num2, mlx, fig->centr_y);
		iso(&(*new_coord)->x0, &(*new_coord)->y0,
				mlx->points[vec->num1]->z, mlx);
		iso(&(*new_coord)->x1, &(*new_coord)->y1,
				mlx->points[vec->num2]->z, mlx);
		(*new_coord)->x0 += 398;
		(*new_coord)->y0 -= 140;
		(*new_coord)->x1 += 398;
		(*new_coord)->y1 -= 140;
	}
	return ;
}

static void		get_coord_colr(t_coord **new_coord,
		t_mlx *mlx, t_vec *vec, int h)
{
	t_vec	*z1z2;

	if (!(z1z2 = (t_vec*)malloc(sizeof(t_vec))))
		ft_error_out("co", 45);
	z1z2->num1 = mlx->points[vec->num1]->z;
	z1z2->num2 = mlx->points[vec->num2]->z;
	if (mlx->pa->color_f == 0)
	{
		(*new_coord)->color_start = mlx->points[vec->num1]->color;
		(*new_coord)->color_end = mlx->points[vec->num2]->color;
	}
	else if (mlx->pa->color_f == 10)
		get_10_color(new_coord, z1z2, h, mlx->map_param->h_colr_min);
	else if (mlx->pa->color_f == 11)
		get_11_color(new_coord, z1z2, h, mlx->map_param->h_colr_min);
	else if (mlx->pa->color_f == 12)
		get_12_color(new_coord, z1z2, h, mlx->map_param->h_colr_min);
	else
	{
		(*new_coord)->color_start = take_collor(mlx->pa->color_f);
		(*new_coord)->color_end = take_collor(mlx->pa->color_f);
	}
	free(z1z2);
	return ;
}

t_coord			*creat_coord(t_mlx *mlx, int num1, int num2)
{
	t_coord		*new_coord;
	t_figure	*fig;
	t_vec		*vec;
	int			h;

	if (!(mlx->points[num1]) || !(mlx->points[num2]) ||
			!(new_coord = (t_coord*)malloc(sizeof(t_coord))) ||
			!(fig = (t_figure*)malloc(sizeof(t_figure))) ||
			!(vec = (t_vec*)malloc(sizeof(t_vec))))
		return (NULL);
	vec->num1 = num1;
	vec->num2 = num2;
	fig->centr_x = ((mlx->map->w) - 1) / 2.00;
	fig->centr_y = ((mlx->map->h) - 1) / 2.00;
	h = mlx->map_param->h_colr_max - mlx->map_param->h_colr_min;
	coord_params(&new_coord, mlx, vec, fig);
	get_coord_colr(&new_coord, mlx, vec, h);
	free(fig);
	free(vec);
	return (new_coord);
}
