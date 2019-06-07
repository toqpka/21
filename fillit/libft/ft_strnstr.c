/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:13:05 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/03 16:33:10 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && (i < len))
	{
		j = 0;
		if (s2[j] == s1[i])
		{
			while ((s2[j] == s1[i + j]) && (i + j < len))
			{
				if (s2[j + 1] == '\0')
					return ((char *)s1 + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}
