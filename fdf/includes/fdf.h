/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:30:29 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/21 23:50:22 by gwaymar-         ###   ########.fr       */
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
#include <time.h>
# define WIN_WIDTH    1280
# define WIN_HEIGHT   720
# define INT2VOIDP(i) (const void*)(uintptr_t)(i)
# define COLOR_RESET "\033[0m"
# define COLOR_RED "\033[31m"
# define COLOR_BLUE "\033[34m"
# define COLOR_YELLOW "\033[33m"
# define COLOR_GREEN "\033[32m"

typedef struct  s_coord
{
  int           x0;
  int           x1;
  int           y0;
  int           y1;
  int           color_start;
  int           color_end;
}               t_coord;

typedef struct  s_map
{
  unsigned long int size;
  int           w;
  int           h;
}               t_map;

typedef struct s_point
{
  int           x;
  int           y;
  int           z;
  int           color;
  int           h;
  int           x_next_line;
}               t_point;

typedef struct s_mlx
{
  void        *mlx;
  void        *window;
  int         x0;
  int         y0;
  int         x1;
  int         y1;
  int         move_x;
  int         move_y;
  double      shape_z;
  int         size_rect;
	t_map       *map;
  t_point     **points;
  char        proj;
  int         color_f;
  int         x_max;
  int         x_min;
  int         y_max;
  int         y_min;
  int         h_colr_min;
  int         h_colr_max;
  double      rot_x;
  double      rot_x_gg;
  double      rot_y;
  double      rot_z;
  double      rot_x_last;
  double      rot_y_last;
  double      rot_z_last;
  int         start_from;  // ???  wut
}             t_mlx;


/*
** Read_file && Check_Valid
*/
void  line_draw(t_mlx *mlx, t_coord *box);
void  main_draw(t_mlx *mlx);
int   fdf(t_point **ar, t_map		*map);
void  rotate_to_l(t_mlx *mlx);
int		atoi_color(char *z);
int   ft_f_grad(int first, int second, double p);
int		cgrad(int c1, int c2, double pers);
void  ft_min_max(t_mlx **mlx);
void iso(int *x, int *y, int z, t_mlx *mlx);
#endif
