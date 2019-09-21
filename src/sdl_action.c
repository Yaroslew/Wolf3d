/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:24 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/17 22:33:21 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h" // исправить заголовки

void	handler(t_base *base)
{
	int run;

	run = 1;
	while (run)
	{
		while(SDL_PollEvent(&base->sdl->event))
		{
			if (base->sdl->event.type == SDL_QUIT)
				esc(1);
		}
	}
}