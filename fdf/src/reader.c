/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 01:23:27 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 13:50:23 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static unsigned long int	count_w_list(t_list *tmp, int *x_max)
{
	unsigned long int	size_m;
	char				**o_str;
	int					i;

	size_m = 0;
	while (tmp)
	{
		i = 0;
		if (!(o_str = ft_strsplit(tmp->content, ' ')))
			ft_error_out("rdc", 26);
		else
		{
			while (o_str[i])
				free(o_str[i++]);
			free(o_str);
		}
		if (*x_max < i)
			*x_max = i;
		size_m += i;
		tmp = tmp->next;
	}
	return (size_m);
}

static t_point				**cr_map_points(t_list *list, t_map *map)
{
	t_point				**oppa;
	t_list				*tmp;
	unsigned long int	size_m;
	int					x_max;
	int					y;

	x_max = 0;
	size_m = 0;
	ft_list_reverse(&list);
	y = ft_lstsize(list);
	tmp = list;
	ft_putstr("Creating map ["COLOR_YELLOW"0%"COLOR_RESET"]");
	size_m = count_w_list(tmp, &x_max);
	ft_fill_map(&map, y, x_max, size_m);
	if (!(oppa = (t_point**)malloc(sizeof(t_point*) * size_m)))
		return (NULL);
	ft_fill_points(&oppa, tmp, map);
	ft_putstr("\rCreating map ["COLOR_YELLOW"10%"COLOR_RESET"]");
	return (oppa);
}

static void					create_list_f_file(int file, t_list **begin_list)
{
	char			*str;
	t_list			*elem;
	char			gnl;

	while ((gnl = get_next_line(file, &str)) == 1)
	{
		if (!*begin_list)
		{
			if (!(*begin_list = ft_lstnew(str, ft_strlen(str) + 1)))
				ft_error_out("rdc", 74);
		}
		else
		{
			if (!(elem = ft_lstnew(str, ft_strlen(str) + 1)))
				ft_error_out("rdc", 79);
			ft_lstadd(begin_list, elem);
		}
	}
	free(str);
	if (gnl == -1)
		ft_error_out("rdc", 86);
	return ;
}

t_point						**ft_read(char *av, t_map *map)
{
	int				file;
	t_list			*list;
	t_point			**broken;

	file = open(av, O_RDONLY);
	if (file < 0)
		return (NULL);
	ft_putstr("\nReading map  ["COLOR_YELLOW"waiting..."COLOR_RESET"]");
	create_list_f_file(file, &list);
	ft_putstr("\r                                             ");
	ft_putstr("\rReading map  ["COLOR_GREEN"OK"COLOR_RESET"]\n");
	if (list)
		broken = cr_map_points(list, map);
	else
		ft_error_out("rdc", 103);
	close(file);
	return (broken);
}
