/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 05:23:01 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 05:23:37 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		atoi_color(char *z)
{
	int		i;
	int		color;

	i = 2;
	color = 0;
	if (!z)
		return (0xFFFFFF);
	while (z[i] != '\0')
	{
		if (z[i] >= 48 && z[i] <= 57)
			color = color * 16 + z[i] - 48;
		else if (z[i] >= 65 && z[i] <= 70)
			color = color * 16 + z[i] - 55;
		else
			return (0xFFFFFF);
		i++;
	}
	return (color);
}

int		cgrad(int c1, int c2, double pers)
{
	int	r;
	int	g;
	int	b;

	if (c1 == c2)
		return (c1);
	r = ft_f_grad((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, pers);
	g = ft_f_grad((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, pers);
	b = ft_f_grad(c1 & 0xFF, c2 & 0xFF, pers);
	return (r << 16 | g << 8 | b);
}
