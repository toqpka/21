/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:48:11 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/01 21:56:02 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *res_s1, const char *res_s2)
{
	size_t		i;
	size_t		len_s1;

	i = 0;
	len_s1 = ft_strlen(res_s1);
	while (res_s2[i] != '\0')
	{
		res_s1[i + len_s1] = res_s2[i];
		i++;
	}
	res_s1[i + len_s1] = '\0';
	return (res_s1);
}
