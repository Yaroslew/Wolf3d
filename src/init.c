/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:24:09 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/26 20:37:08 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void	init_dist(t_base *base)
{
	base->dist->time = 0;
	base->dist->time_old = 0;
	base->dist->x_plane = 0;
	base->dist->y_plane = 0.66;
	base->dist->x_camera = 0;
	base->dist->x_raydir = 0;
	base->dist->y_raydir = 0;
}

void	init_hero(t_base *base, int q, int y)
{
	//base->hero->fov = 1.15192;
	base->hero->x = q;
	base->hero->y = y;
	base->hero->x_dir = -1;
	base->hero->y_dir = 0;
	base->hero->side = 0;
	base->hero->hit = 0;
}

void	init_time(t_base *base)
{
	base->time->time = 0;
	base->time->old_time = 0;
}

t_base *init_base(void)
{
	t_base *base;

	if (!(base = malloc(sizeof(t_base) * 1)))
		mess_err(0);
	if (!(base->hero = malloc(sizeof(t_hero) * 1)))
		mess_err(0);
	if (!(base->sdl = malloc(sizeof(t_sdl) * 1)))
		mess_err(0);
	if (!(base->dist = malloc(sizeof(t_dist) * 1)))
		mess_err(0);
	if (!(base->time = malloc(sizeof(t_time) * 1)))
		mess_err(0);
	base->width = 1000;
	base->height = 1000;
	base->w_map = 20;
	base->h_map = 20;
	init_sdl(base);
	init_dist(base);
	init_time(base);
	return (base);
}



void	init_sdl(t_base *base)
{
//  Инициализация окна и рендера

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		mess_err(7);
	base->sdl->window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, base->width, base->height, SDL_WINDOW_SHOWN);
	if (base->sdl->window == NULL)
		mess_err(8);

	base->sdl->ren = SDL_CreateRenderer(base->sdl->window, -1, 0);
	if (base->sdl->ren == NULL)
		mess_err(9);
	base->sdl->wall_s = SDL_LoadBMP("/img/wall.bmp");
	if (!base->sdl->wall_s)
		mess_err(10);
	base->sdl->texture = SDL_CreateTexture(base->sdl->ren, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, base->width, base->height);

}

