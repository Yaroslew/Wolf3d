/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:51:37 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/12 10:59:04 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ray_casting(t_base *base)
{
	distance(base);
}

static void	select_walls(t_base *base, int x)
{
	t_pnti	delta;

	if (base->dist->temp[0] == -1 && base->dist->temp[1] == -1)
	{
		base->dist->temp[0] = base->hero->pnt.x;
		base->dist->temp[1] = base->hero->pnt.y;
	}
	delta.x = base->dist->map.x - base->dist->temp[0];
	delta.y = base->dist->map.y - base->dist->temp[1];
	if (delta.x == 0 && delta.y == 1)
		base->select_wall[x] = 0;
	if (delta.x == 1 && delta.y == 0)
		base->select_wall[x] = 1;
	if (delta.x == 0 && delta.y == -1)
		base->select_wall[x] = 2;
	if (delta.x == -1 && delta.y == 0)
		base->select_wall[x] = 3;
	if ((delta.x == -1 && delta.y == -1) || (delta.x == 1 && delta.y == -1) ||
			(delta.x == 1 && delta.y == 1) || (delta.x == 2 && delta.y == 0))
		base->select_wall[x] = 4;
}

static void	move_dist(t_base *base, int x)
{
	if (base->dist->sidedist.x < base->dist->sidedist.y)
	{
		base->dist->sidedist.x += base->dist->deltadist.x;
		base->dist->map.x += base->hero->step.x;
		base->hero->side = 0;
	}
	else
	{
		base->dist->sidedist.y += base->dist->deltadist.y;
		base->dist->map.y += base->hero->step.y;
		base->hero->side = 1;
	}
	if (base->map[base->dist->map.y * base->map_s.y +
			base->dist->map.x].data == 'x')
	{
		base->hero->hit = 1;
		select_walls(base, x);
		clear_temp_dist(base);
	}
	else
	{
		base->dist->temp[0] = base->dist->map.x;
		base->dist->temp[1] = base->dist->map.y;
	}
}

void		distance(t_base *base)
{
	int x;

	x = 0;
	while (x < base->win_s.x)
	{
		init_act_pos(base, x);
		check_hero_step(base);
		while (base->hero->hit == 0)
			move_dist(base, x);
		wall_dist(base, x);
		base_draw(base, x);
		x++;
		base->hero->hit = 0;
	}
	prepare_wall(base);
	draw_wall(base);
	frames(base);
	return ;
}
