/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:42:59 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/18 19:27:30 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *res_dst, const void *res_src, size_t n)
{
	char			*dst;
	const char		*src;

	dst = res_dst;
	src = res_src;
	while (n--)
		*(dst++) = *(src++);
	return (res_dst);
}
