/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:33:29 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 12:26:33 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*mlxdel(t_mlx *mlx)
{
	int	i;

	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->map_param != NULL)
		free(mlx->map_param);
	if (mlx->pa != NULL)
		free(mlx->pa);
	if (mlx->points != NULL)
	{
		i = -1;
		while (++i < mlx->map->size)
		{
			if (mlx->points[i])
				free(mlx->points[i]);
		}
		free(mlx->points);
	}
	if (mlx->map != NULL)
		free(mlx->map);
	if (mlx->mlx != NULL)
		free(mlx->mlx);
	free(mlx);
	return (NULL);
}
