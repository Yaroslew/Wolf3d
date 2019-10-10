/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:21:32 by qweissna          #+#    #+#             */
/*   Updated: 2019/10/10 11:22:05 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_act_pos(t_base *base, int x)
{
	base->dist->x_camera = 2 * x / (double)base->win_s.x - 1;
	base->dist->raydir.x = base->hero->dir.x + base->dist->plane.x *
		base->dist->x_camera;
	base->dist->raydir.y = base->hero->dir.y + base->dist->plane.y *
		base->dist->x_camera;
	base->dist->deltadist.x = fabs(1.0 / base->dist->raydir.x);
	base->dist->deltadist.y = fabs(1.0 / base->dist->raydir.y);
	base->dist->map.x = (int)base->hero->pnt.x;
	base->dist->map.y = (int)base->hero->pnt.y;
}

void	put_walls(t_sdl *sdl)
{
	if (!(sdl->walls = malloc(sizeof(SDL_Surface*) * 5)))
		mess_err(0);
	sdl->walls[0] = IMG_Load(STH);
	sdl->walls[1] = IMG_Load(NRTH);
	sdl->walls[2] = IMG_Load(WEST);
	sdl->walls[3] = IMG_Load(EAST);
	sdl->walls[4] = IMG_Load(BACK);
	if (!sdl->walls[0] || !sdl->walls[1] || !sdl->walls[2] ||
		!sdl->walls[3] || !sdl->walls[4])
		mess_err(10);
}

void	check_hero_step(t_base *base)
{
	if (base->dist->raydir.x < 0)
	{
		base->hero->step.x = -1;
		base->dist->sidedist.x = (base->hero->pnt.x -
			base->dist->map.x) * base->dist->deltadist.x;
	}
	else
	{
		base->hero->step.x = 1;
		base->dist->sidedist.x = (base->dist->map.x + 1.0 -
			base->hero->pnt.x) * base->dist->deltadist.x;
	}
	if (base->dist->raydir.y < 0)
	{
		base->hero->step.y = -1;
		base->dist->sidedist.y = (base->hero->pnt.y -
			base->dist->map.y) * base->dist->deltadist.y;
	}
	else
	{
		base->hero->step.y = 1;
		base->dist->sidedist.y = (base->dist->map.y + 1.0 -
			base->hero->pnt.y) * base->dist->deltadist.y;
	}
}

void	wall_dist(t_base *base, int x)
{
	if (base->hero->side == 0)
		base->dist->walldist = (base->dist->map.x - base->hero->pnt.x +
				(1.0 - base->hero->step.x) / 2) / base->dist->raydir.x;
	else
		base->dist->walldist = (base->dist->map.y - base->hero->pnt.y +
				(1.0 - base->hero->step.y) / 2) / base->dist->raydir.y;
	if (base->dist->walldist == 0)
		base->line_height[x] = 0;
	else
		base->line_height[x] = (int)(base->win_s.y / base->dist->walldist);
}

void	base_draw(t_base *base, int x)
{
	base->start_draw[x] = -base->line_height[x] / 2 + base->win_s.y / 2;
	if (base->start_draw[x] < 0)
		base->start_draw[x] = 0;
	base->end_draw[x] = base->line_height[x] / 2 + base->win_s.y / 2;
	if (base->end_draw[x] >= base->win_s.y)
		base->end_draw[x] = base->win_s.y - 1;
}
