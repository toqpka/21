/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:51:45 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 19:05:34 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color		set_color_f(int red, int green, int blue)
{
	t_color color;

	color.red = (red ? red : 0);
	color.green = (green ? green : 0);
	color.blue = (blue ? blue : 0);
	return (color);
}

t_color		palette_fact(int i, int8_t pal, int max_iter)
{
	t_color		color;
	int			k;
	int			g;

	if (!pal)
	{
		if (i < max_iter)
			color = set_color_f((i * 9) % 256, (i * 9) % 256, (i * 9) % 256);
		else
			color = set_color_f(0, 0, 0);
	}
	else if (pal == 1)
		color = fire_color(i, max_iter);
	else if (pal == 2)
		color = rainbow_color(i, max_iter);
	else if (pal == 3)
		color = blue_orang(i, max_iter);
	return (color);
}
