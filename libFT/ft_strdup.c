/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:00:57 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/03 16:34:14 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dest = (char*)malloc(sizeof(char) * len);
	if (dest == NULL)
		return (dest);
	ft_strcpy(dest, s1);
	return (dest);
}
