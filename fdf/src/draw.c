/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:55:21 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 00:38:24 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int take_collor(int	x)
{
	const int collors_col[] =
	{
  	0x000000,  // 0 black
  	0x00FFFF,  // 1 Aqua(Cyan)
  	0x0000FF,  // 2 blue
  	0xFF0000,  // 3 red
  	0xFFFF00,  // 4
  	0xFF00FF,  // 5
  	0x00FF00,  // 6 green
  	0xA52A2A,  // 7 Brown
  	0x800000,  // 8 MAroon
  	0x1E90FF,  // 9 DodgerBlue
		0xFFFFFF,  // 10  white
	};
	return (collors_col[x]);
}

void	ft_start_window(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->window,	WIN_WIDTH-130, WIN_HEIGHT-80, 0x00FFFFFF, "> = Increase");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH-130, WIN_HEIGHT-65, 0x00FFFFFF, "< = Decrease");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH-290, WIN_HEIGHT-40, 0x00FFFFFF, "Mouse (scroll up) = Zoom in");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH-310, WIN_HEIGHT-25, 0x00FFFFFF, "Mouse (scroll down) = Zoom out");
	mlx_string_put(mlx->mlx, mlx->window,	WIN_WIDTH-(WIN_WIDTH-20), WIN_HEIGHT-70, 0x00FFFFFF, "RIGHT = Move right");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH-(WIN_WIDTH-20), WIN_HEIGHT-55, 0x00FFFFFF, "LEFT  = Move left");
	mlx_string_put(mlx->mlx, mlx->window, WIN_WIDTH-(WIN_WIDTH-20), WIN_HEIGHT-40, 0x00FFFFFF, "UP    = Move up");
	mlx_string_put(mlx->mlx, mlx->window,	WIN_WIDTH-(WIN_WIDTH-20), WIN_HEIGHT-25, 0x00FFFFFF, "DOWN  = Move down");
	mlx_string_put(mlx->mlx, mlx->window,	WIN_WIDTH-(WIN_WIDTH-300), WIN_HEIGHT-40, 0x00FFFFFF, "NUM 1..6 = Colors");
	mlx_string_put(mlx->mlx, mlx->window,	WIN_WIDTH-(WIN_WIDTH-300), WIN_HEIGHT-25, 0x00FFFFFF, "NUM 7..9 = Spectrum");
	mlx_string_put(mlx->mlx, mlx->window,	WIN_WIDTH-(WIN_WIDTH-300), WIN_HEIGHT-70, 0x00FFFFFF, "NUM 0    = Default");
	return ;
}

char    *ft_dec_to_hex_color(int nbr)
{
	int		i;
	char	*str;
  int   buf[50];
  int   temp;
  char  gg;
  int   k;

	i = 0;
	str = (char*)malloc(9);
	if (!nbr)
  {
    str = "0xFFFFFF";
		return (str);
  }
  nbr = 65535;
	while (nbr != 0)
	{
    temp = nbr % 16;
    buf[i] = temp;
    if (temp < 10)
      str[i] = temp + 48;
    else
      str[i] = temp + 55;
    nbr /= 16;
		i++;
	}
  while (i < 6)
    str[i++] = 48;
  k = 7;
  while (k > -1)
  {
    str[k] = str[k - 2];
    str[k - 1] = str[k - 2];
    k -= 2;
  }
  k = 2;
  i = 8;
  while (--i > 5)
  {
    gg = str[i];
    str[i] = str[k];
    str[k] = gg;
    k++;
  }
  str[8] = '\0';
  str[0] = 48;
  str[1] = 'x';
  //printf("\n Result=%s \n",str);
	return (str);
}

static int ft_get_color(t_coord *cord, int x, int y)
{
  int     color_curr;
  double  percent;
  int     xB;
  int     yB;
  int     xall;
  int     yall;
  int     wut;
  int     all_q;
  char    *str;

  xB = abs(cord->x1 - x);
  yB = abs(cord->y1 - y);
  xall = abs(cord->x1 - cord->x0);
  yall = abs(cord->y1 - cord->y0);
  all_q = sqrt((xall*xall) + (yall*yall));
  wut = sqrt((xall - xB) * (xall - xB) + (yall - yB) * (yall - yB));


  percent = 100 * wut / all_q;
  percent /= 100.00;

//  str = ft_dec_to_hex_color(cord->color_end);
  color_curr = cgrad(cord->color_start, cord->color_end, percent);
  //printf("\ncolor_curr=%d cord->color_end=%d   per=%f\n",color_curr,cord->color_end,percent);
  return (color_curr);
}

void line_draw(t_mlx *mlx, t_coord *box)
{
  int A, B, sign;
  int signa, signb;
  int f = 0;
  int x, y;
  int color_cur;

  x = box->x0;
  y = box->y0;
  A = box->y1 - box->y0;
  B = box->x0 - box->x1;
  if (abs(A) > abs(B)) sign = 1;
  else sign = -1;
  if (A < 0) signa = -1;
  else signa = 1;
  if (B < 0) signb = -1;
  else signb = 1;

  //mlx_pixel_put(mlx->mlx, mlx->window, x, y, box->color_start);
  if (sign == -1)
  {
    while (x != box->x1 || y != box->y1)
    {
      f += A*signa;
      if (f > 0)
      {
        f -= B*signb;
        y += signa;
      }
      x -= signb;
			if (!(x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT-85))
      {
      	color_cur = ft_get_color(box, x, y);
      	mlx_pixel_put(mlx->mlx, mlx->window, x, y, color_cur);
			}
    }
  }
  else
  {
    while (x != box->x1 || y != box->y1)
    {
      f += B*signb;
      if (f > 0) {
        f -= A*signa;
        x -= signb;
      }
      y += signa;
      if (!(x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT-85))
      {
        color_cur = ft_get_color(box, x, y);
        mlx_pixel_put(mlx->mlx, mlx->window, x, y, color_cur);
      }
    }
  }
  return ;
}

static int take_cart_x(int nbr, t_mlx *mlx, double xc)
{
  int   cart;
  int   sgn;
  double   fx;

  sgn = -1;
  //if (mlx->points[nbr]->x > xc)
    //sgn = 1;
  if (mlx->points[nbr]->x == xc)
    return (WIN_WIDTH / 2);
  fx = xc - mlx->points[nbr]->x;
  //printf("    wut=%f   ", fx);
  //printf("\n#G=%d  nbrX=%d   xcentr_fig=%f",nbr,  mlx->points[nbr]->x, xc);
  cart = (int)((WIN_WIDTH / 2) + mlx->size_rect * sgn * fx);
  //printf("    cart=%d   \n", cart);
  return (cart);
}

static int take_cart_y(int nbr, t_mlx *mlx, double yc)
{
  int   cart;
  int   sgn;
  double   fy;

  sgn = -1;
  //if (mlx->points[nbr]->y > yc)
    //sgn = 1;
  if (mlx->points[nbr]->y == yc)
    return (WIN_HEIGHT / 2);
  fy = yc - mlx->points[nbr]->y;
  cart = (int)((WIN_HEIGHT / 2) + mlx->size_rect * sgn * fy);
  return (cart);
}


void iso(int *x, int *y, int z, t_mlx *mlx)
{
  int previous_x;
  int previous_y;

  previous_x = *x;
  previous_y = *y;
  *x = (previous_x - previous_y) * cos(0.523599);
  *y = -z*mlx->shape_z + (previous_x + previous_y) * sin(0.523599);
	previous_x = *x;
	previous_y = *y;
	//1  z
		*x = previous_x * cos(mlx->rot_x) - previous_y * sin(mlx->rot_x);
		*y = previous_x * sin(mlx->rot_x) + previous_y * cos(mlx->rot_x);
	//printf("\n  add=%g",cos(mlx->rot_x));
  //printf("\nWINcX=%d  WINcY=%d   x_cart=%d y_cart=%d   x_iso=%d y_iso=%d\n",WIN_WIDTH/2,WIN_HEIGHT/2,previous_x,previous_y,*x,*y);
}

t_coord *get_10_color(t_coord *new_coord, int z, int z2, int h, int h_min)
{
	if (z <= h_min)
		new_coord->color_start = take_collor(1);
	else if (z >= 2*h/3)
		new_coord->color_start = take_collor(7);
	else if (z > h_min && z < h/3)
		new_coord->color_start = take_collor(6);
	else
		new_coord->color_start = take_collor(9);
	if (z2 <= h_min)
		new_coord->color_end = take_collor(1);
	else if (z2 >= 2*h/3)
		new_coord->color_end = take_collor(7);
	else if (z2 > h_min && z2 < h/3)
		new_coord->color_end = take_collor(6);
	else
		new_coord->color_end = take_collor(9);

	return (new_coord);
}

t_coord *get_11_color(t_coord *new_coord, int z, int z2, int h, int h_min)
{
	if (z <= h_min)
		new_coord->color_start = take_collor(10);
	else if (z >= 2*h/3)
		new_coord->color_start = take_collor(2);
	else if (z > h_min && z < h/3)
		new_coord->color_start = take_collor(1);
	else
		new_coord->color_start = take_collor(9);
	if (z2 <= h_min)
		new_coord->color_end = take_collor(10);
	else if (z2 >= 2*h/3)
		new_coord->color_end = take_collor(2);
	else if (z2 > h_min && z2 < h/3)
		new_coord->color_end = take_collor(1);
	else
		new_coord->color_end = take_collor(9);
	return (new_coord);
}

t_coord *get_12_color(t_coord *new_coord, int z,int z2, int h, int h_min)
{
	if (z <= h_min)
		new_coord->color_start = take_collor(8);
	else if (z >= 2*h/3)
		new_coord->color_start = take_collor(4);
	else if (z > h_min && z < h/3)
		new_coord->color_start = take_collor(5);
	else
		new_coord->color_start = take_collor(2);
	if (z2 <= h_min)
		new_coord->color_end = take_collor(8);
	else if (z2 >= 2*h/3)
		new_coord->color_end = take_collor(4);
	else if (z2 > h_min && z2 < h/3)
		new_coord->color_end = take_collor(5);
	else
		new_coord->color_end = take_collor(2);
	return (new_coord);
}

static t_coord  *creat_coord(t_mlx *mlx, int num1, int num2)
{
  t_coord   *new_coord;
	double		centr_x;
	double		centr_y;
	int			h;

  if (!(mlx->points[num1]) || !(mlx->points[num2]))
    return (NULL);
  if (!(new_coord = (t_coord*)malloc(sizeof(t_coord))))
    return (NULL);

	centr_x = ((mlx->map->w) - 1) / 2.00;
	centr_y = ((mlx->map->h) - 1) / 2.00;
  // 0 - cart // 1 - iso
  if (mlx->proj == 0)
  {
    new_coord->x0 = take_cart_x(num1, mlx, centr_x);
    new_coord->y0 = take_cart_y(num1, mlx, centr_y);
    new_coord->x1 = take_cart_x(num2, mlx, centr_x);
    new_coord->y1 = take_cart_y(num2, mlx, centr_y);
  }
  else if (mlx->proj == 1)
  {
    //ft_putstr("risuem  iso");
    new_coord->x0 = take_cart_x(num1, mlx, centr_x);
    new_coord->y0 = take_cart_y(num1, mlx, centr_y);
    new_coord->x1 = take_cart_x(num2, mlx, centr_x);
    new_coord->y1 = take_cart_y(num2, mlx, centr_y);
    iso(&new_coord->x0, &new_coord->y0, mlx->points[num1]->z, mlx);
    iso(&new_coord->x1, &new_coord->y1, mlx->points[num2]->z, mlx);
    new_coord->x0 += 398;
    new_coord->y0 -= 140;
    new_coord->x1 += 398;
    new_coord->y1 -= 140;
  }
	h = mlx->h_colr_max - mlx->h_colr_min;
	if (mlx->color_f == 0)
	{
		new_coord->color_start = mlx->points[num1]->color;
		new_coord->color_end = mlx->points[num2]->color;
	}
	else if (mlx->color_f == 10)
		new_coord = get_10_color(new_coord, mlx->points[num1]->z,mlx->points[num2]->z, h, mlx->h_colr_min);
	else if (mlx->color_f == 11)
		new_coord = get_11_color(new_coord, mlx->points[num1]->z,mlx->points[num2]->z, h, mlx->h_colr_min);
	else if (mlx->color_f == 12)
		new_coord = get_12_color(new_coord, mlx->points[num1]->z,mlx->points[num2]->z, h, mlx->h_colr_min);
	else
	{
		//printf("\nmlx->color_f=%d   color=%d",mlx->color_f,collors_s[mlx->color_f]);
		new_coord->color_start = take_collor(mlx->color_f);
		new_coord->color_end = take_collor(mlx->color_f);
	}
  return (new_coord);
}

void main_draw(t_mlx *mlx)
{
  t_coord   *cord;
  int   g;
  double centr_map_x;
  double centr_map_y;

  centr_map_x = ((mlx->map->w) - 1) / 2.00;
  centr_map_y = ((mlx->map->h) - 1) / 2.00;
	//printf("\n centr_map_x=%g  centr_map_y=%g",centr_map_x,centr_map_y);
  cord = (t_coord*)malloc(sizeof(t_coord));
	ft_start_window(mlx);
  if ((centr_map_x) > 0)
  {
    g = 0;
		//printf("\n h_min=%d   h_max=%d",mlx->h_colr_min,mlx->h_colr_max);
		   while ((g + 1) < (mlx->map->size))
		   {
								if ((mlx->points[g]->x <= mlx->x_max) && (mlx->points[g]->x >= mlx->x_min) && (mlx->points[g]->y <= mlx->y_max) && (mlx->points[g]->y >= mlx->y_min))
								{
						     	if (mlx->points[g + 1]->x > mlx->points[g]->x)
						     	{
						       	cord = creat_coord(mlx, g, g + 1);
						       	cord->x0 += mlx->move_x;
						       	cord->y0 += mlx->move_y;
						       	cord->x1 += mlx->move_x;
						       	cord->y1 += mlx->move_y;
									 	line_draw(mlx, cord);
						     	}
								 	if (mlx->points[g]->y < (mlx->map->h - 1))
						     	{
						       	cord = creat_coord(mlx, g, mlx->points[g]->x_next_line);
						       	cord->x0 += mlx->move_x;
						       	cord->y0 += mlx->move_y;
						       	cord->x1 += mlx->move_x;
						       	cord->y1 += mlx->move_y;
						       	line_draw(mlx, cord);
						     	}
								}
		    g++;
		   }
  }
  free(cord);
  return ;
}
