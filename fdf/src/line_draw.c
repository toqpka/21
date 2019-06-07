/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:28:34 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 13:39:42 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_get_color(t_coord *cord, int x, int y)
{
	int		color_curr;
	t_grad	*grad;

	if (!(grad = (t_grad*)malloc(sizeof(t_grad))))
		ft_error_out("ldr", 21);
	grad->xb = abs(cord->x1 - x);
	grad->yb = abs(cord->y1 - y);
	grad->xall = abs(cord->x1 - cord->x0);
	grad->yall = abs(cord->y1 - cord->y0);
	grad->all_q = sqrt((grad->xall * grad->xall) + (grad->yall * grad->yall));
	grad->wut = sqrt((grad->xall - grad->xb) * (grad->xall - grad->xb) +
			(grad->yall - grad->yb) * (grad->yall - grad->yb));
	grad->percent = 100 * grad->wut / grad->all_q;
	grad->percent /= 100.00;
	color_curr = cgrad(cord->color_start, cord->color_end, grad->percent);
	free(grad);
	return (color_curr);
}

static void		draw_line_a(t_line_params *line, t_mlx *mlx, t_coord *box)
{
	while (line->x != box->x1 || line->y != box->y1)
	{
		line->f += line->a * line->signa;
		if (line->f > 0)
		{
			line->f -= line->b * line->signb;
			line->y += line->signa;
		}
		line->x -= line->signb;
		if (!(line->x < 0 || line->x >= WIN_WIDTH ||
					line->y < 0 || line->y >= WIN_HEIGHT - 85))
		{
			line->color_cur = ft_get_color(box, line->x, line->y);
			mlx_pixel_put(mlx->mlx, mlx->window, line->x,
					line->y, line->color_cur);
		}
	}
	return ;
}

static void		draw_line_b(t_line_params *line, t_mlx *mlx, t_coord *box)
{
	while (line->x != box->x1 || line->y != box->y1)
	{
		line->f += line->b * line->signb;
		if (line->f > 0)
		{
			line->f -= line->a * line->signa;
			line->x -= line->signb;
		}
		line->y += line->signa;
		if (!(line->x < 0 || line->x >= WIN_WIDTH ||
					line->y < 0 || line->y >= WIN_HEIGHT - 85))
		{
			line->color_cur = ft_get_color(box, line->x, line->y);
			mlx_pixel_put(mlx->mlx, mlx->window,
					line->x, line->y, line->color_cur);
		}
	}
	return ;
}

void			line_draw(t_mlx *mlx, t_coord *box)
{
	t_line_params	*gg_line;

	if (!(gg_line = (t_line_params*)malloc(sizeof(t_line_params))))
		ft_error_out("ldr", 81);
	gg_line->x = box->x0;
	gg_line->y = box->y0;
	gg_line->f = 0;
	gg_line->a = box->y1 - box->y0;
	gg_line->b = box->x0 - box->x1;
	gg_line->sign = (abs(gg_line->a) > abs(gg_line->b)) ? 1 : -1;
	gg_line->signa = (gg_line->a < 0) ? -1 : 1;
	gg_line->signb = (gg_line->b < 0) ? -1 : 1;
	(gg_line->sign == -1) ? draw_line_a(gg_line, mlx, box) :
		draw_line_b(gg_line, mlx, box);
	free(gg_line);
	return ;
}
