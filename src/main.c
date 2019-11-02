/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:21 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/12 12:34:53 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	music_player(t_base *base)
{
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		esc(2);
	if (!(base->sdl->ost = Mix_LoadMUS("/img/ost.wav")))
		esc(2);
}

int			main(int ac, char **av)
{
	t_base	*base;

	if (ac != 2)
		mess_err(1);
	base = init_base();
	check_map(av[1], base);
	record_map(av[1], base);
	ray_casting(base);
	music_player(base);
	Mix_PlayMusic(base->sdl->ost, -1);
	handler(base);
	return (0);
}
