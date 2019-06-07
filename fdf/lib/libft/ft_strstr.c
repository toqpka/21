/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:58:01 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/11 14:41:14 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		find_index;
	size_t		temp;

	i = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		find_index = 0;
		if (s1[i] == s2[find_index])
		{
			temp = i;
			while (s1[i] == s2[find_index])
			{
				if (s2[find_index + 1] == '\0')
					return ((char*)&s1[temp]);
				find_index++;
				i++;
			}
			i = temp;
		}
		i++;
	}
	return (0);
}
