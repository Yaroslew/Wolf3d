/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:09:27 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/12 10:59:04 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	check_hit_wall(t_base *base, int ind)
{
	if (base->map[ind].data == 'x')
		return (0);
	return (1);
}

void		move_forward(t_base *base)
{
	t_pnti ind;

	ind.x = ((int)(base->hero->pnt.x + base->hero->dir.x + 0.5 *
		base->time->move_speed) + ((int)(base->hero->pnt.y) * base->map_s.x));
	ind.y = ((int)(base->hero->pnt.x) + (base->map_s.x * (int)(base->hero->pnt.y
		+ base->hero->dir.y + 0.5 * base->time->move_speed)));
	if (check_hit_wall(base, ind.x))
		base->hero->pnt.x += base->hero->dir.x * base->time->move_speed;
	if (check_hit_wall(base, ind.y))
		base->hero->pnt.y += base->hero->dir.y * base->time->move_speed;
	ray_casting(base);
}

void		move_back(t_base *base)
{
	t_pnti ind;

	ind.x = ((int)(base->hero->pnt.x - base->hero->dir.x - 0.5 *
		base->time->move_speed) + ((int)base->hero->pnt.y * base->map_s.x));
	ind.y = ((int)(base->hero->pnt.x) + (base->map_s.x * (int)(base->hero->pnt.y
		- base->hero->dir.y - 0.5 * base->time->move_speed)));
	if (check_hit_wall(base, ind.x))
		base->hero->pnt.x -= base->hero->dir.x * base->time->move_speed;
	if (check_hit_wall(base, ind.y))
		base->hero->pnt.y -= base->hero->dir.y * base->time->move_speed;
	ray_casting(base);
}

void		rot_rght(t_base *base)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = base->hero->dir.x;
	old_plane_x = base->dist->plane.x;
	base->hero->dir.x = base->hero->dir.x * cos(-base->time->rot_speed) -
		base->hero->dir.y * sin(-base->time->rot_speed);
	base->hero->dir.y = old_dir_x * sin(-base->time->rot_speed) +
		base->hero->dir.y * cos(-base->time->rot_speed);
	base->dist->plane.x = base->dist->plane.x * cos(-base->time->rot_speed) -
		base->dist->plane.y * sin(-base->time->rot_speed);
	base->dist->plane.y = old_plane_x * sin(-base->time->rot_speed) +
		base->dist->plane.y * cos(-base->time->rot_speed);
	ray_casting(base);
}

void		rot_lft(t_base *base)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = base->hero->dir.x;
	old_plane_x = base->dist->plane.x;
	base->hero->dir.x = base->hero->dir.x * cos(base->time->rot_speed) -
		base->hero->dir.y * sin(base->time->rot_speed);
	base->hero->dir.y = old_dir_x * sin(base->time->rot_speed) +
		base->hero->dir.y * cos(base->time->rot_speed);
	base->dist->plane.x = base->dist->plane.x *
		cos(base->time->rot_speed) - base->dist->plane.y *
		sin(base->time->rot_speed);
	base->dist->plane.y = old_plane_x * sin(base->time->rot_speed) +
		base->dist->plane.y * cos(base->time->rot_speed);
	ray_casting(base);
}
