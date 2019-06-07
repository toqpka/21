/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:50:12 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/04/01 22:02:32 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_size(char *str)
{
	int		i;
	int		j;

	i = 4;
	j = 0;
	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (str[i] != '\n')
			return (1);
		j++;
		if (j == 4 || (j - 4) % 5 == 0)
		{
			i++;
			if (str[i] != '\n' && str[i] != '\0' && str[i + 1] == '\0')
				return (1);
		}
		else
			i += 5;
	}
	return (0);
}

int		ft_check_valid(char *str)
{
	int		i;
	int		sharp;
	int		n;

	i = 0;
	sharp = 0;
	n = 0;
	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (1);
		if (str[i] == '#')
			sharp++;
		if (str[i] == '\n')
			n++;
		i++;
	}
	if ((sharp % 4 != 0) || sharp > 104 || sharp < 4 || (n - 4) % 5 != 0 \
		|| (i - 20) % 21 != 0)
		return (1);
	return (sharp);
}

int		ft_check_conection(char *str, int i)
{
	int res;

	res = 0;
	if (str[i] == '#')
	{
		if ((i - 1 >= 0) && str[i - 1] == '#')
			res++;
		if (str[i + 1] && str[i + 1] == '#')
			res++;
		if (i + 5 < ((i / 21 + 1) + 20 * (1 + (i / 21))))
		{
			if (str[i + 5] && str[i + 5] == '#')
				res++;
		}
		if (i - 5 >= ((i / 21) + 20 * (i / 21)))
		{
			if (str[i - 5] && str[i - 5] == '#')
				res++;
		}
	}
	return (res);
}

int		main_test(char *str)
{
	int		i;
	int		k;
	int		count;

	i = 0;
	count = 0;
	k = 0;
	while (str[i])
	{
		if (((i - (i / 21) + 1) % 5) && ((i - (i / 21)) / 20 - (i / 21 + 1)))
		{
			if (str[i] == '#')
				count += ft_check_conection(str, i);
			k++;
		}
		if (k > 15)
		{
			if ((count != 8) && (count != 6))
				return (0);
			k = 0;
			count = 0;
		}
		i++;
	}
	return (1);
}

char	check_valid(char *str)
{
	int		s;
	int		nb_fig;

	s = 0;
	s = ft_check_valid(str);
	nb_fig = count_num(str);
	if ((s % 4 == 0) && (check_size(str)) == 0 && main_test(str) != 0)
		return (0);
	return (1);
}
