/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:11:02 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/19 02:12:44 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_f_grad(int first, int second, double p)
{
	if (first == second)
		return (first);
	return (int)((double)first + (second-first)*p);
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

static int how_to_use(void)
{
	write(1, "try to use this: ./fdf map.fdf\n", 31);
	return (1);
}

t_point		**cr_map(t_list *list, t_map *map)
{
	t_point		**oppa;
	t_list		*tmp;
	char			**o_str;
	char			**col_str;
	unsigned long int	size_m;
	int				x_max;

	int		x;
	int		y;
	int		i;
	int		g;
	int		k;

	int		load_perc;
	int		perc;
	int		cur_l;

	x_max = 0;
	size_m = 0;
	ft_list_reverse(&list);
	y = ft_lstsize(list);
	tmp = list;
	map->h = y;
	ft_putstr("Creating map ["COLOR_YELLOW"0%"COLOR_RESET"]");
	while (tmp)
	{
		o_str = ft_strsplit(tmp->content, ' ');
		i = 0;
		if (o_str)
		{
			while (o_str[i] != '\0')
				i++;
		}
		if (x_max < i)
			x_max = i;
		size_m += i;
		tmp = tmp->next;
	}
	map->w = x_max;
	map->size = size_m;
	tmp = list;
	oppa = (t_point**)malloc(sizeof(t_point*) * size_m);
	i = 0;
	while (i < size_m)
	{
		oppa[i] = (t_point*)malloc(sizeof(t_point));
		i++;
	}
	g = 0;
	k = 0;
	perc = 5;
	cur_l = 0;
	while (tmp)
	{
		o_str = ft_strsplit(tmp->content, ' ');
		if (o_str)
		{
			i = 0;
			while(o_str[i])
			{
				col_str = ft_strsplit(o_str[i], ',');
				oppa[k]->z = ft_atoi(col_str[0]);
				oppa[k]->color = atoi_color(col_str[1]);
				oppa[k]->x = i;
				oppa[k]->y = g;
				k++;
				i++;
			}
		}
		tmp = tmp->next;
		g++;
		if (map->h != 0)
			load_perc = g*100/map->h;
		if (cur_l < load_perc)
		{
			cur_l = load_perc;
			if (!(cur_l % perc) && perc < 6)
			{
				ft_putstr("\rCreating map ["COLOR_YELLOW);
				ft_putnbr(perc);
				ft_putstr("%"COLOR_RESET"]");
				perc += 5;
			}
		}
	}
	ft_putstr("\rCreating map ["COLOR_YELLOW"10%"COLOR_RESET"]");
	//NEEED TO DELETE OUTPUT check
	// i = 0;
	// while (i < (map->w * map->h))
	// {
	// 	printf("\n#%d X=%d Y=%d Z=%d  Color=%s\n", i, oppa[i]->x, oppa[i]->y,oppa[i]->z, oppa[i]->color);
	// 	i++;
	// }
	return (oppa);
}

t_point		**ft_read(char *av, t_map *map)
{
	int					file;
	char				buffer[BUFF_SIZE + 1];
	ssize_t			bytes;
	char				*str;
	t_list			*list;
	t_list			*elem;
	const void 	*a;
	t_point			**broken;

	list = NULL;
	file = open(av, O_RDONLY);
	if (file < 0)
		return (NULL);
	ft_putstr("\nReading map  ["COLOR_YELLOW"waiting..."COLOR_RESET"]");
  while (get_next_line(file,&str) == 1)
  {
    //ft_putendl(str); // output in console           dellllll!!!!!!!!!!!!
		if (!list)
			list = ft_lstnew(str, ft_strlen(str)+1);
		else
		{
			elem = ft_lstnew(str, ft_strlen(str)+1);
			ft_lstadd(&list, elem);
		}
		free(str);
  }
	ft_putstr("\r                              ");
	ft_putstr("\rReading map  ["COLOR_GREEN"OK"COLOR_RESET"]\n");
	broken = cr_map(list, map);
  close (file);
	return (broken);
}

t_point	**add_next_x(t_point	**points, t_map *map)
{
	int		i;
	int		next_x_l;
	int		perc;
	int		load_perc;
	int		cur_l;

	i = 0;
	perc = 10;
	cur_l = 0;
	while (i < map->size && points[i]->y < map->h - 1)
	{
		next_x_l = i;
		points[i]->x_next_line = i;
		if (points[i]->y < map->h - 1)
		{
			while (next_x_l + 1 < map->size && (points[next_x_l + 1]->x > points[next_x_l]->x))
				next_x_l++;
			if (points[i]->x == points[next_x_l + (points[next_x_l]->x - points[(next_x_l) - i]->x) + 1]->x)
				points[i]->x_next_line = next_x_l + (points[next_x_l]->x - points[(next_x_l) - i]->x) + 1;
		}
		i++;
		if (map->h != 0)
			load_perc = (points[i]->y*100)/map->h;
		if (cur_l < load_perc)
		{
			cur_l = load_perc;
			if (!(cur_l % perc) && perc < 84)
			{
				perc += 15;
				ft_putstr("\rCreating map ["COLOR_YELLOW);
				ft_putnbr(perc);
				ft_putstr("%"COLOR_RESET"]");
			}
		}
	}
	ft_putstr("\rCreating map ["COLOR_GREEN"100%"COLOR_RESET"]\n");
	return (points);
}

int   main(int ac, char **av)
{
  t_point	**ar;
	t_map		*map;
	int			i;

	if (ac != 2)
		how_to_use();
	map = (t_map*)malloc(sizeof(t_map));
  if (ac == 2)
	{
    ar = ft_read(av[1], map);
		ar = add_next_x(ar, map);
  	if (ar != 0)
    	fdf(ar, map);
  	else
    	write(2, "error\n",6);
	}
  write(1, "\n", 1);
  return (0);
}
