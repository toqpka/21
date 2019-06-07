/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projects.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:35:06 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 13:03:04 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			take_cart_x(int nbr, t_mlx *mlx, double xc)
{
	int		cart;
	int		sgn;
	double	fx;

	sgn = -1;
	if (mlx->points[nbr]->x == xc)
		return (WIN_WIDTH / 2);
	fx = xc - mlx->points[nbr]->x;
	cart = (int)((WIN_WIDTH / 2) + mlx->pa->size_rect * sgn * fx);
	return (cart);
}

int			take_cart_y(int nbr, t_mlx *mlx, double yc)
{
	int		cart;
	int		sgn;
	double	fy;

	sgn = -1;
	if (mlx->points[nbr]->y == yc)
		return (WIN_HEIGHT / 2);
	fy = yc - mlx->points[nbr]->y;
	cart = (int)((WIN_HEIGHT / 2) + mlx->pa->size_rect * sgn * fy);
	return (cart);
}

void		iso(int *x, int *y, int z, t_mlx *mlx)
{
	int		previous_x;
	int		previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z * mlx->pa->shape_z + (previous_x + previous_y) * sin(0.523599);
}
