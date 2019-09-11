/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:39:24 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 19:09:15 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook_first(int key, t_mlx **mlx)
{
	if (key == NUM_9)
		next_pallete(*mlx);
	if (key == NUM_8)
		prev_pallete(*mlx);
	if (key == ESC)
		exit(EXIT_SUCCESS);
	if (key == NUM_7)
		(*mlx)->show_help = !(*mlx)->show_help;
	if ((*mlx)->fractal == JULIA)
		if (key == SPACE)
			(*mlx)->jul_pause = !(*mlx)->jul_pause;
	if (key == NUM_0)
		reset_fract(*mlx);
	if (key == NUM_3)
	{
		reset_fract(*mlx);
		next_fract(*mlx);
	}
	if (key == NUM_2)
	{
		reset_fract(*mlx);
		prev_fract(*mlx);
	}
	return ;
}
