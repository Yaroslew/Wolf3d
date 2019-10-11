/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:24:09 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/10 22:22:14 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	init_dist(t_base *base)
{
	base->dist->time = 0;
	base->dist->time_old = 0;
	base->dist->plane.x = 0;
	base->dist->plane.y = 0.66;
	base->dist->x_camera = 0;
	base->dist->raydir.x = 0;
	base->dist->raydir.y = 0;
	base->dist->temp[0] = -1;
	base->dist->temp[1] = -1;
}

void		init_hero(t_base *base, int q, int y)
{
	base->hero->pnt.x = q;
	base->hero->pnt.y = y;
	base->hero->dir.x = -1;
	base->hero->dir.y = 0;
	base->hero->side = 0;
	base->hero->hit = 0;
}

void		init_time(t_base *base)
{
	base->time->time = 0;
	base->time->old_time = 0;
}

t_base		*init_base(void)
{
	t_base *base;

	if ((!(base = malloc(sizeof(t_base) * 1))) ||
		(!(base->hero = malloc(sizeof(t_hero) * 1))) ||
		(!(base->sdl = malloc(sizeof(t_sdl) * 1))) ||
		(!(base->dist = malloc(sizeof(t_dist) * 1))) ||
		(!(base->time = malloc(sizeof(t_time) * 1))) ||
		(!(base->color = malloc(sizeof(t_color) * 1))))
		mess_err(0);
	base->win_s.x = WDTH;
	base->win_s.y = HGTH;
	base->map_s.x = 22;
	base->map_s.y = 23;
	init_sdl(base);
	init_dist(base);
	init_time(base);
	base->color->h_w_tex = 512;
	return (base);
}

void		init_sdl(t_base *base)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		mess_err(7);
	base->sdl->win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, base->win_s.x, base->win_s.y, SDL_WINDOW_SHOWN);
	if (base->sdl->win == NULL)
		mess_err(8);
	base->sdl->ren = SDL_CreateRenderer(base->sdl->win, -1, 0);
	if (base->sdl->ren == NULL)
		mess_err(9);
	put_walls(base->sdl);
	base->sdl->tex = SDL_CreateTexture(base->sdl->ren, SDL_PIXELFORMAT_RGBA32,
			SDL_TEXTUREACCESS_STREAMING, base->win_s.x, base->win_s.y);
	base->sdl->tex_p.x = 0;
	base->sdl->tex_p.y = 0;
}
