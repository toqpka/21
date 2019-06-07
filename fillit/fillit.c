/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:50:20 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/04/08 19:56:24 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	how_to_use(void)
{
	write(1, "use: fillit source_file\n", 24);
	return (1);
}

int		main(int argc, char **argv)
{
	t_etrim			*tetrimin;
	int				num_f;
	int				side;
	char			*str_file;

	if (argc != 2)
		return (how_to_use());
	str_file = read_input(argv);
	if (str_file == NULL)
		ft_putstr("error\n");
	else
	{
		num_f = 0;
		side = 0;
		tetrimin = create_tet_tabs(str_file);
		num_f = count_num(str_file);
		side = minimum_grid(num_f);
		solve(tetrimin, num_f, side);
		free(tetrimin);
	}
	free(str_file);
	return (0);
}
