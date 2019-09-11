/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:12:57 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/11 17:27:18 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	tmp;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = -1;
	while (++i < --len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
	}
	s[i] = '\0';
	return (s);
}
