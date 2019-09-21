/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:24:09 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/18 00:09:46 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_base *init_base(void)
{
	t_base *base;

	if (!(base = malloc(sizeof(t_base) * 1)))
		mess_err(0);
	if (!(base->hero = malloc(sizeof(t_hero) * 1)))
		mess_err(0);
	if (!(base->sdl = malloc(sizeof(t_sdl) * 1)))
		mess_err(0);
	base->width = 1000;
	base->height = 1000;
	base->w_map = 20;
	base->h_map = 20;
	init_sdl(base);
	return (base);
}

void	init_hero(t_base *base, int q, int y)
{
	base->hero->fov = 1.0472;
	base->hero->h_man = 32;
	base->hero->x = (q * 64) + 32;
	base->hero->y = (y * 64) + 32;
	base->hero->angle_vector = 0.785398;
}

void	init_sdl(t_base *base)
{
//  Инициализация окна и рендера
	base->sdl->window = NULL;
	base->sdl->screen_surface = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		mess_err(7);
	base->sdl->window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, base->width, base->height, SDL_WINDOW_SHOWN);
	if (base->sdl->window == NULL)
		mess_err(8);
	base->sdl->screen_surface = SDL_GetWindowSurface(base->sdl->window);
	if (base->sdl->screen_surface == NULL)
		mess_err(7);
	base->sdl->ren = SDL_CreateRenderer(base->sdl->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (base->sdl->ren == NULL)
		mess_err(9);

//    Загрузка текстур
	base->sdl->temp = SDL_LoadBMP("/img/wall.bmp");
	if (base->sdl->temp == NULL)
		mess_err(10);
	base->sdl->wall = SDL_CreateTextureFromSurface(base->sdl->ren, base->sdl->temp);
	if (base->sdl->wall == NULL)
		mess_err(11);
	SDL_FreeSurface(base->sdl->temp);
	SDL_RenderClear(base->sdl->ren);

	base->sdl->temp = SDL_LoadBMP("/img/back.bmp");
	if (base->sdl->temp == NULL)
		mess_err(10);
	base->sdl->background = SDL_CreateTextureFromSurface(base->sdl->ren, base->sdl->temp);
	if (base->sdl->background == NULL)
		mess_err(11);
	SDL_FreeSurface(base->sdl->temp);
	SDL_RenderClear(base->sdl->ren);

//	Параметры текстур

	base->sdl->back_rect.h = base->height;
	base->sdl->back_rect.w = base->width;
	base->sdl->back_rect.x = 0;
	base->sdl->back_rect.y = 0;

	base->sdl->wall_rect.h = 64;
	base->sdl->wall_rect.w = 64;
	base->sdl->wall_rect.x = 0;
	base->sdl->wall_rect.y = 0;

// Загрузка на экран

	SDL_RenderCopy(base->sdl->ren, base->sdl->background, NULL, &base->sdl->back_rect);
	SDL_RenderCopy(base->sdl->ren, base->sdl->wall, NULL, &base->sdl->wall_rect);
	SDL_RenderPresent(base->sdl->ren);
}

