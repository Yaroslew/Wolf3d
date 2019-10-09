/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:24 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/09 21:59:21 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	handler(t_base *base)
{
	int run;

	run = 1;
	while (run)
	{
		while (SDL_PollEvent(&base->sdl->event))
		{
			if (base->sdl->event.type == SDL_QUIT)
				esc(1);
			if (base->sdl->event.type == SDL_KEYDOWN)
			{
				if (base->sdl->event.key.keysym.sym == SDLK_ESCAPE)
					esc(1);
				if (base->sdl->event.key.keysym.sym == SDLK_UP)
					move_forward(base);
				if (base->sdl->event.key.keysym.sym == SDLK_DOWN)
					move_back(base);
				if (base->sdl->event.key.keysym.sym == SDLK_RIGHT)
					rot_rght(base);
				if (base->sdl->event.key.keysym.sym == SDLK_LEFT)
					rot_lft(base);
			}
		}
	}
}
