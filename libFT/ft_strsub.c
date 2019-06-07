/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:39:09 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/18 17:23:47 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		k;

	if (s != NULL)
	{
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		i = start;
		k = 0;
		while (s[i] && k < len)
		{
			str[k] = s[i];
			i++;
			k++;
		}
		str[k] = '\0';
		return (str);
	}
	return (NULL);
}
