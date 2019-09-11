/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:23:10 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 18:55:29 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PROTOTYPES_H
# define FRACTOL_PROTOTYPES_H

void		fractol(t_mlx **mlx);
void		image_set_pixel(t_image *image, int x, int y, t_color color);
t_image		*new_image(t_mlx *mlx);
void		ft_mandelbrot(t_mlx *mlx);
void		clear_image(t_image *image);
void		init(t_mlx **m);
int			hook_keydown(int key, t_mlx **mlx);
int			exit_hook(t_mlx **mlx);
void		load_fractal_img(t_mlx **mlx);
int			hook_mousemove(int x, int y, t_mlx *mlx);
int			hook_mousedown(int button, int x, int y, t_mlx *mlx);
void		zoom(int x, int y, t_mlx **mlx, double z);
void		fract_compl_init(t_fract_compl *f);
void		set_name_fractal(t_mlx *mlx);
void		prev_fract(t_mlx *mlx);
void		next_fract(t_mlx *mlx);
void		hook_first(int key, t_mlx **mlx);
void		reset_fract(t_mlx *mlx);
void		prev_pallete(t_mlx *mlx);
void		next_pallete(t_mlx *mlx);

/*
** Choose color palette
*/
t_color		palette_fact(int i, int8_t pal, int max_iter);
t_color		set_color_f(int red, int green, int blue);
t_color		rainbow_color(int i, int max_iter);
t_color		blue_orang(int i, int max_iter);
t_color		fire_color(int i, int max_iter);
t_color		blue_orang2(int i, int max_iter);
t_color		test_ft(int i, int max_iter);

/*
** Fractals templates
*/
void		julia_f(t_mlx **mlx);
void		mandelbrot_f(t_mlx **mlx);
void		duobrot_f(t_mlx **mlx);
void		ship_f(t_mlx **mlx);
void		triobrot_f(t_mlx **mlx);

#endif
