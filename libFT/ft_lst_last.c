/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:00:24 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/11 17:25:40 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_last(t_list *begin_lst)
{
	t_list *tmp;
	t_list *last;

	if (begin_lst)
	{
		tmp = begin_lst;
		last = tmp;
		while (tmp->next)
		{
			last = tmp;
			tmp = tmp->next;
		}
		return (last);
	}
	else
		return (NULL);
}
