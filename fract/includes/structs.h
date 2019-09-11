/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:22:50 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 18:58:50 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCTS_H
# define FRACTOL_STRUCTS_H

typedef struct		s_image
{
	void			*image;
	char			*addr;
	int				bpp;
	int				size;
	int				endian;
}					t_image;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct		s_rmouse
{
	int				x;
	int				y;
}					t_rmouse;

typedef struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct		s_fract_compl
{
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			r;
	double			i;
}					t_fract_compl;

typedef struct		s_mlx
{
	void			*mlx;
	void			*window;
	t_image			*img;
	t_rmouse		mouse;
	int8_t			fractal;
	char			*name_fractal;
	int				max_iter;
	double			zoom;
	double			movex;
	double			movey;
	int8_t			pallete;
	int8_t			jul_pause;
	int8_t			show_help;
}					t_mlx;

#endif
