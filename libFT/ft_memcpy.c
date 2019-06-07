/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:42:59 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/01 21:55:27 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *res_dst, const void *res_src, size_t n)
{
	char		*r_dst;
	const char	*r_src;

	r_dst = res_dst;
	r_src = res_src;
	while (n-- > 0)
		*r_dst++ = *r_src++;
	return (res_dst);
}
