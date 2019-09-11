/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:00:57 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/18 19:28:42 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1) + 1;
	dest = (char*)malloc(sizeof(char) * len);
	if (dest == NULL)
		return (dest);
	ft_strcpy(dest, s1);
	return (dest);
}
