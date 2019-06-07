/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:51:08 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/11 12:38:57 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*src;
	size_t					k;

	src = s;
	k = 0;
	while (k < n)
	{
		if (src[k] == (unsigned char)c)
			return ((void*)src + k);
		k++;
	}
	return (NULL);
}
