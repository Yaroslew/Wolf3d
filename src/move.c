/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:09:27 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/26 22:53:07 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	move_hero(t_base *base, int step)
{
	int step_up_x;
	int step_up_y;

	if (step == 1)
	{
		step_up_x = (int)((base->hero->x + base->hero->x_dir * base->time->move_speed) + (base->hero->y * base->w_map));
		step_up_y = (int)(((base->hero->y + base->hero->y_dir * base->time->move_speed) * base->w_map) + base->hero->x);
		ft_printf("x=%d y=%d      ", (int)base->hero->x, (int)base->hero->y);
		if (base->map[step_up_x].data != 'x' && base->hero->x > 0 && (base->hero->x + base->hero->x_dir * base->time->move_speed) > 0)
			base->hero->x += base->hero->x_dir * base->time->move_speed;
		if (base->map[step_up_y].data != 'x' && base->hero->y > 0 && (base->hero->y + base->hero->y_dir * base->time->move_speed) > 0)
			base->hero->y += base->hero->y_dir * base->time->move_speed;
		ft_printf("|  x=%d y=%d\n", (int)base->hero->x, (int)base->hero->y);
	}
	if (step == 2)
	{
		step_up_x = (int)((base->hero->x - base->hero->x_dir * base->time->move_speed) + (base->hero->y * base->w_map));
		step_up_y = (int)(((base->hero->y - base->hero->y_dir * base->time->move_speed) * base->w_map) + base->hero->x);
		if (base->map[step_up_x].data != 'x' && base->hero->x > 0 && (base->hero->x - base->hero->x_dir * base->time->move_speed) > 0)
			base->hero->x -= base->hero->x_dir * base->time->move_speed;
		if (base->map[step_up_y].data != 'x' && base->hero->y > 0 && (base->hero->y - base->hero->y_dir * base->time->move_speed) > 0)
			base->hero->y -= base->hero->y_dir * base->time->move_speed;
	}
	//ft_printf("x=%d   y=%d | hero_x=%d hero_y=%d\n", step_up_x, step_up_y, (int)base->hero->x, (int)base->hero->y);
	ray_casting(base);
}

void	rotation(t_base *base, int rl)
{
	double old_dir_x;
	double old_plane_x;

	if (rl == 1)
	{
		old_dir_x = base->hero->x_dir;
		old_plane_x = base->dist->x_plane;
		base->hero->x_dir = base->hero->x_dir * cos(-base->time->rot_speed) - base->hero->y_dir * sin(-base->time->rot_speed);
		base->hero->y_dir = old_dir_x * sin(-base->time->rot_speed) + base->hero->y_dir * cos(-base->time->rot_speed);
		base->dist->x_plane = base->dist->x_plane * cos(-base->time->rot_speed) - base->dist->y_plane * sin(-base->time->rot_speed);
		base->dist->y_plane = old_plane_x * sin(-base->time->rot_speed) + base->dist->y_plane * cos(-base->time->rot_speed);
	}
	if (rl == 2)
	{
		old_dir_x = base->hero->x_dir;
		old_plane_x = base->dist->x_plane;
		base->hero->x_dir = base->hero->x_dir * cos(base->time->rot_speed) - base->hero->y_dir * sin(base->time->rot_speed);
		base->hero->y_dir = old_dir_x * sin(base->time->rot_speed) + base->hero->y_dir * cos(base->time->rot_speed);
		base->dist->x_plane = base->dist->x_plane * cos(base->time->rot_speed) - base->dist->y_plane * sin(base->time->rot_speed);
		base->dist->y_plane = old_plane_x * sin(base->time->rot_speed) + base->dist->y_plane * cos(base->time->rot_speed);
	}
	ray_casting(base);
}
