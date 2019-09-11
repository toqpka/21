/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:55:03 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/11 17:26:06 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *begin_lst)
{
	t_list		*tmp;
	size_t		i;

	i = 0;
	if (begin_lst)
	{
		i = 1;
		tmp = begin_lst;
		while (tmp->next)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}
