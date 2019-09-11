/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:42:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 20:25:14 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int value)
{
	int		ln;
	long	len_nbr;

	ln = 0;
	len_nbr = value;
	while (len_nbr)
	{
		len_nbr /= 10;
		ln += 1;
	}
	if (value < 0)
		ln += 1;
	return (ln);
}

static char	*ft_constr(int len, long nbr, int value)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
	{
		free(str);
		return (NULL);
	}
	str[len] = '\0';
	while (nbr)
	{
		str[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (value < 0)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int value)
{
	int		len;
	long	nbr;
	char	*str;

	if (value == 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * 2)))
		{
			free(str);
			return (NULL);
		}
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		nbr = value;
		len = ft_len(value);
		if (nbr < 0)
			nbr *= -1;
		str = ft_constr(len, nbr, value);
	}
	return (str);
}
