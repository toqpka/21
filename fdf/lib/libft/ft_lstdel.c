/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:29:06 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/11 15:02:35 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*cur;

	cur = *alst;
	if (!cur || !*alst || !del)
		return ;
	while (cur)
	{
		tmp = cur;
		del(cur->content, cur->content_size);
		free(cur);
		cur = tmp->next;
	}
	*alst = NULL;
	return ;
}
