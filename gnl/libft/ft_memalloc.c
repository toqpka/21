/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:09:51 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/05 16:50:23 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memalloc(size_t n)
{
	void	*mem;

	if (!(mem = (void*)malloc(sizeof(void) * n)))
		return (NULL);
	ft_bzero(mem, n);
	return (mem);
}
