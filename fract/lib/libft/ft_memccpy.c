/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:49:35 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/01 21:53:58 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *res_dst, const void *res_src, int c, size_t n)
{
	unsigned char	*r_dst;
	unsigned char	*r_src;
	size_t			k;

	r_src = (unsigned char*)res_src;
	r_dst = res_dst;
	k = 0;
	while (k < n)
	{
		r_dst[k] = r_src[k];
		if (r_dst[k] == (unsigned char)c)
			return (r_dst + k + 1);
		k++;
	}
	return (NULL);
}
