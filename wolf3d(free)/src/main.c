/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 18:32:56 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/11 19:41:18 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int main( int argc, char* args[] )
{
	const char *map =  "0000222222220000"\
										 "1              0"\
										 "1      11111   0"\
										 "1     0        0"\
										 "0     0  1110000"\
										 "0     3        0"\
										 "0   10000      0"\
										 "0   0   11100  0"\
										 "0   0   0      0"\
										 "0   0   1  00000"\
										 "0       1      0"\
										 "2       1      0"\
										 "0       0      0"\
										 "0 0000000      0"\
										 "0              0"\
										 "0002222222200000"; // our game map
	t_sdl		*sdl;

	ft_init(&sdl);
	while (sdl->run_main)
	{
		while ( SDL_PollEvent( &(sdl->event) ) != 0 )
		{
			if((SDL_QUIT == sdl->event.type) || (SDL_KEYDOWN == sdl->event.type && SDL_SCANCODE_ESCAPE == sdl->event.key.keysym.scancode))
				sdl->run_main = 0;
		}
	}
	ft_close(&sdl);
	return (0);
}
