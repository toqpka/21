/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:48:30 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/11 15:30:55 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_redel(t_list *tmp)
{
	free(tmp);
	return (NULL);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*tmp;
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		if (!(tmp->content = (void*)malloc(sizeof(void) * (content_size))))
			return (ft_redel(tmp));
		ptr1 = (unsigned char *)content;
		ptr2 = (unsigned char *)tmp->content;
		i = -1;
		while (++i <= content_size)
			ptr2[i] = ptr1[i];
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	return (tmp);
}
