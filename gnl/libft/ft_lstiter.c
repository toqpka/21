/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:45:50 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/11 15:03:25 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (f && lst)
		while (lst)
		{
			f(lst);
			lst = lst->next;
		}
	return ;
}
