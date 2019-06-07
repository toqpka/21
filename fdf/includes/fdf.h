/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:30:29 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 14:19:21 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <math.h>
# include <time.h>
# define WIN_WIDTH    1280
# define WIN_HEIGHT   720
# define INT2VOIDP(i) (const void*)(uintptr_t)(i)
# define COLOR_RESET "\033[0m"
# define COLOR_RED "\033[31m"
# define COLOR_BLUE "\033[34m"
# define COLOR_YELLOW "\033[33m"
# define COLOR_GREEN "\033[32m"

typedef struct			s_grad
{
	double				percent;
	int					xb;
	int					yb;
	int					xall;
	int					yall;
	int					wut;
	int					all_q;
}						t_grad;

typedef struct			s_coord
{
	int					x0;
	int					x1;
	int					y0;
	int					y1;
	int					color_start;
	int					color_end;
}						t_coord;

typedef struct			s_line_params
{
	int					x;
	int					y;
	int					color_cur;
	int					f;
	int					a;
	int					b;
	int					sign;
	int					signa;
	int					signb;
}						t_line_params;

typedef struct			s_figure
{
	double				centr_x;
	double				centr_y;
}						t_figure;

typedef struct			s_vec
{
	int					num1;
	int					num2;
}						t_vec;

typedef struct			s_map
{
	unsigned long int	size;
	int					w;
	int					h;
}						t_map;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
	int					h;
	int					x_next_line;
}						t_point;

typedef struct			s_params
{
	int					move_x;
	int					move_y;
	double				shape_z;
	int					size_rect;
	char				proj;
	int					color_f;
}						t_params;

typedef struct			s_map_params
{
	int					x_max;
	int					x_min;
	int					y_max;
	int					y_min;
	int					h_colr_min;
	int					h_colr_max;
}						t_map_params;

typedef struct			s_mlx
{
	void				*mlx;
	void				*window;
	int					x0;
	int					y0;
	int					x1;
	int					y1;
	t_params			*pa;
	t_map				*map;
	t_point				**points;
	t_map_params		*map_param;
}						t_mlx;

/*
** Error_exit
*/
void					ft_error_out(char *str, int nbr);
int						ft_is_valid(char *str);
/*
** Read_file && Check_Valid
*/
t_point					**ft_read(char *av, t_map *map);
void					show_load_2(int *cur_l, int *perc_l, int y, int h);
void					ft_fill_map(t_map **map, int y, int x_max,
		unsigned long int size_m);
void					ft_fill_points(t_point ***opph,
		t_list *tmp, t_map *map);
void					ft_min_max(t_mlx **mlx);
/*
** Drawing
*/
int						fdf(t_point **ar, t_map		*map);
void					line_draw(t_mlx *mlx, t_coord *box);
void					main_draw(t_mlx *mlx);
int						cgrad(int c1, int c2, double pers);
int						atoi_color(char *z);
int						hook_mouseyx(int button, int x, int y, t_mlx *mlx);
/*
** Some_converters
*/
void					map_param_init(t_mlx *mlx, t_map_params **grunt);
void					fill_map_to_mlx(t_mlx **mlx, t_map_params *grunt);
int						fill_h_min(t_mlx *mlx);
int						fill_h_max(t_mlx *mlx);
/*
** Coord_converters
*/
void					map_param_init(t_mlx *mlx, t_map_params **grunt);
t_coord					*creat_coord(t_mlx *mlx, int num1, int num2);
/*
** Projects
*/
int						take_cart_x(int nbr, t_mlx *mlx, double xc);
int						take_cart_y(int nbr, t_mlx *mlx, double yc);
void					iso(int *x, int *y, int z, t_mlx *mlx);
/*
** Start_window & Colors
*/
void					mlx_def_init(t_mlx **mlx);
int						take_collor(int	x);
void					ft_start_window(t_mlx *mlx);
void					get_10_color(t_coord **new_coord,
		t_vec *z1z2, int h, int h_min);
void					get_11_color(t_coord **new_coord,
		t_vec *z1z2, int h, int h_min);
void					get_12_color(t_coord **new_coord,
		t_vec *z1z2, int h, int h_min);
/*
** Clear
*/
t_mlx					*mlxdel(t_mlx *mlx);
#endif
