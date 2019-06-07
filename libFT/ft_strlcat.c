/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:58:05 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/03 16:34:47 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *res_dst, const char *res_src, size_t size)
{
	size_t		i;
	size_t		dlen;

	i = 0;
	dlen = 0;
	while (res_dst[dlen] && dlen < size)
		dlen++;
	while (res_src[i] && (dlen + i + 1) < size)
	{
		res_dst[dlen + i] = res_src[i];
		i++;
	}
	if (dlen < size)
		res_dst[dlen + i] = 0;
	return (dlen + ft_strlen(res_src));
}
