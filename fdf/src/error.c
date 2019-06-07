/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 01:34:27 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 14:24:02 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_is_valid(char *str)
{
	while (*str)
	{
		if (*str != '-' && *str != '+' && !ft_isdigit(*str))
			return (0);
		if ((*str == '-' || *str == '+') && (!*(str + 1) ||
				!ft_isdigit(*(str + 1))))
			return (0);
		++str;
	}
	return (1);
}

void	ft_error_out(char *str, int nbr)
{
	ft_putstr("Error   Code:");
	ft_putstr(str);
	ft_putstr(" Line:");
	ft_putnbr(nbr);
	ft_putstr("\n");
	exit(0);
}
