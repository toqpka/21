/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:36:39 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/03/19 21:02:12 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_input(char **argv)
{
	int		file;
	char	buffer[BUFF_SIZE + 1];
	ssize_t	bytes;
	char	*str;

	file = open(argv[1], O_RDONLY);
	if (file < 0)
		return (NULL);
	if ((bytes = read(file, buffer, BUFF_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		str = ft_strdup(buffer);
	}
	close(file);
	if (bytes == -1 || bytes == 0)
		return (NULL);
	if (check_valid(str) == 1)
		return (NULL);
	return (str);
}
