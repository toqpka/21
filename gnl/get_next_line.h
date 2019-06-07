/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:26:08 by gwaymar-          #+#    #+#             */
/*   Updated: 2018/12/21 06:07:24 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE (21)
# include "unistd.h"
# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"
# include "./libft/includes/libft.h"
# include "stdlib.h"

int		get_next_line(const int fd, char **line);

#endif
