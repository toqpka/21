/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:30:29 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/07/14 18:37:53 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "structs.h"
# include "prototypes.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define WIN_TITLE "Fractol"
# define ZOOM 1.1
# define MAX_COLOR 4
# define MAX_FRACT 5
# define INT2VOIDP(i) (const void*)(uintptr_t)(i)
# define COLOR_RESET "\033[0m"
# define COLOR_RED "\033[31m"
# define COLOR_BLUE "\033[34m"
# define COLOR_YELLOW "\033[33m"
# define COLOR_GREEN "\033[32m"

# define MANDELBROT 0
# define JULIA 1
# define DUOBROT 2
# define TRIOBROT 3
# define SHIP 4

# define TOP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define NUM_PLUS 69
# define NUM_MINUS 78
# define NUM_DIV 75
# define NUM_MULT 67
# define NUM_0 82
# define NUM_2 84
# define NUM_3 85
# define NUM_7 89
# define NUM_8 91
# define NUM_9 92
# define SPACE 49
# define ONE(k) (k == NUM_7 || k == SPACE || k == NUM_2 || k == NUM_3)
# define TWO(k) (k == NUM_MULT || k == NUM_DIV || k == TOP || k == DOWN)
# define TREE(k) (k == NUM_MINUS || k == NUM_PLUS || k == NUM_0)
# define FOUR(k) (k == RIGHT || k == NUM_MINUS || k == NUM_PLUS)
# define FIVE(k) (k == NUM_0 || k == NUM_8 || k == LEFT || k == NUM_9)
# define ACTIVE_KEY(k) (ONE(k) || TWO(k) || TREE(k) || FOUR(k) || FIVE(k))

#endif
