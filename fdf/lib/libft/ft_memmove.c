/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:46:18 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/11 14:35:48 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*my_dst;
	char	*my_src;

	my_dst = (char*)dst;
	my_src = (char*)src;
	if (my_src == my_dst)
		return (dst);
	else if (my_src < my_dst)
	{
		my_dst = my_dst + len - 1;
		my_src = my_src + len - 1;
		while (len-- > 0)
			*my_dst-- = *my_src--;
	}
	else
	{
		while (len-- > 0)
			*my_dst++ = *my_src++;
	}
	return (dst);
}
