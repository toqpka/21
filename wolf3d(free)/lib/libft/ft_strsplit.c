/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:16:33 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/11 13:37:38 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_wlen(char const *s, char c, int start)
{
	int		wlen;
	int		i;

	i = start;
	wlen = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		wlen++;
	}
	return (wlen);
}

static int		ft_wcount(char const *s, char c)
{
	int		w_count;
	int		i;

	i = 0;
	w_count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		w_count++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c)
			i++;
	}
	return (w_count);
}

static char		**ft_free(char **split, int *k)
{
	while (*k > -1)
	{
		free(split[*k]);
		*k = *k - 1;
	}
	return (NULL);
}

static char		**ft_help(char const *s, char c)
{
	int				i;
	int				k;
	int				j;
	char			**split;

	i = 0;
	k = 0;
	if (!(split = (char **)malloc(sizeof(char*) * (ft_wcount(s, c) + 1))))
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		j = 0;
		if (!(split[k] = (char *)malloc(sizeof(char) * (ft_wlen(s, c, i) + 1))))
			return (ft_free(split, &k));
		while (s[i] != c && s[i])
			split[k][j++] = s[i++];
		while (s[i] == c)
			i++;
		split[k++][j] = '\0';
	}
	split[k] = NULL;
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;

	if (s != NULL)
	{
		split = ft_help(s, c);
		return (split);
	}
	return (NULL);
}
