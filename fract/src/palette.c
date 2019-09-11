/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:16:59 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 19:41:55 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color				rainbow_color(int i, int max_iter)
{
	t_color	color;
	int		k;

	if (i < max_iter && i > 0)
	{
		k = i % 7;
		if (k == 0)
			color = set_color_f(255, 0, 0);
		else if (k == 1)
			color = set_color_f(255, 125, 0);
		else if (k == 2)
			color = set_color_f(255, 255, 0);
		else if (k == 3)
			color = set_color_f(0, 255, 0);
		else if (k == 4)
			color = set_color_f(0, 255, 255);
		else if (k == 5)
			color = set_color_f(0, 0, 255);
		else if (k == 6)
			color = set_color_f(255, 0, 255);
	}
	else
		color = set_color_f(0, 0, 0);
	return (color);
}

static t_color		fire_color_next(int g)
{
	t_color color;

	if (g < 32 * 1)
		color = set_color_f((g * 2) % 100, 0, 0);
	else if (g < 32 * 2)
		color = set_color_f((g * 2) % 128, 0, 0);
	else if (g < 32 * 3)
		color = set_color_f((g * 2) % 193, 0, 0);
	else if (g < 32 * 4)
		color = set_color_f((g * 2) % 255, g - 96, 0);
	else if (g < 32 * 5)
		color = set_color_f(255, g - 96, 0);
	else if (g < 32 * 6)
		color = set_color_f(255, g - 96, 0);
	else if (g < 32 * 7)
		color = set_color_f(255, g - 96, 0);
	else if (g < 32 * 8)
		color = set_color_f(255, g - 96, 0);
	else
		color = set_color_f(0, 0, 0);
	return (color);
}

t_color				fire_color(int i, int max_iter)
{
	t_color		color;
	int			k;

	if (i < max_iter && i > 0)
		color = fire_color_next((i * 9) % 256);
	else
		color = set_color_f(0, 0, 0);
	return (color);
}

t_color				blue_orang(int i, int max_iter)
{
	t_color	color;
	int		k;

	if (i < max_iter && i > 0)
	{
		k = i % 5;
		if (k == 0)
			color = set_color_f(0, 7, 100);
		else if (k == 1)
			color = set_color_f(32, 107, 203);
		else if (k == 2)
			color = set_color_f(237, 255, 255);
		else if (k == 3)
			color = set_color_f(255, 170, 0);
		else if (k == 4)
			color = set_color_f(0, 2, 0);
	}
	else
		color = set_color_f(0, 0, 0);
	return (color);
}
