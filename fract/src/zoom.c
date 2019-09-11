/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:32:30 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 19:43:00 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom(int x, int y, t_mlx **mlx, double z)
{
	(*mlx)->zoom *= z;
	(*mlx)->movex -= (2.0 * x / WIN_WIDTH - 1.0) *
		2.0 * ((1 - z) / (*mlx)->zoom);
	(*mlx)->movey -= (1.0 - 2.0 * y / WIN_HEIGHT) *
		2.0 * ((z - 1) / (*mlx)->zoom);
	return ;
}
