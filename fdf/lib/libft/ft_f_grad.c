/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_grad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 05:20:36 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 11:58:03 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_f_grad(int first, int second, double p)
{
	if (first == second)
		return (first);
	return (int)((double)first + (second - first) * p);
}
