/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 03:04:44 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/08/15 23:17:46 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		*new_image(t_mlx *mlx)
{
	t_image		*img;

	if (!(img = ft_memalloc(sizeof(t_image))))
		ft_print_error_exit(&ft_putendl, "Error");
	if (!(img->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT)))
		ft_print_error_exit(&ft_putendl, "Error");
	img->addr = mlx_get_data_addr(img->image, &img->bpp,
			&img->size, &img->endian);
	return (img);
}

void		image_set_pixel(t_image *image, int x, int y, t_color color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	image->addr[y * image->size + x * image->bpp / 8] = color.blue;
	image->addr[y * image->size + x * image->bpp / 8 + 1] = color.green;
	image->addr[y * image->size + x * image->bpp / 8 + 2] = color.red;
	image->addr[y * image->size + x * image->bpp / 8 + 3] = 0;
	return ;
}
