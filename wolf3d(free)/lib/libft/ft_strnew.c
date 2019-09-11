/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:47:38 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/05 20:38:11 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*str;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size + 1)
		str[i] = '\0';
	return (str);
}
