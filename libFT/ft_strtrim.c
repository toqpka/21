/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:32:14 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/11 14:38:24 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhite_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	k;

	if (s != NULL)
	{
		start = 0;
		end = ft_strlen(s);
		while (s[start] && ft_iswhite_space(s[start]))
			start++;
		while (ft_iswhite_space(s[end - 1]))
			end--;
		if (end < start)
			end = start;
		if (!(str = (char *)malloc(sizeof(char) * (end - start + 1))))
			return (NULL);
		k = 0;
		while (s[start] && start < end)
			str[k++] = s[start++];
		str[k] = '\0';
		return (str);
	}
	return (NULL);
}
