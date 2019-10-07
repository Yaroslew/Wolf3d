/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:09:27 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/08 01:25:48 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int  check_hit_wall(t_base *base, int ind)
{
//	int q;

//	q = 0;
//	base->check_wall[0] = ind + 1;
//	base->check_wall[1] = ind - 1;
//	base->check_wall[2] = ind + base->w_map;
//	base->check_wall[3] = ind - base->w_map;
//	base->check_wall[4] = ind + base->w_map + 1;
//	base->check_wall[5] = ind + base->w_map - 1;
//	base->check_wall[6] = ind - base->w_map + 1;
//	base->check_wall[7] = ind - base->w_map - 1;
//	while (q < 8)
//	{
//		if (base->check_wall[q] > base->w_map * base->h_map || base->check_wall[q] < 0)
//			return (0);
//		if (base->map[base->check_wall[q]].data == 'x')
//			return (0);
//		q++;
//	}

	if (base->map[ind].data == 'x')
		return (0);
	return (1);
}


void	move_hero(t_base *base, int step)
{
	int ind_x;
	int ind_y;

	if (step == 1)
	{
		ind_x = ((int)(base->hero->x + base->hero->x_dir * base->time->move_speed) + ((int)base->hero->y * base->w_map));
		ind_y = ((int)(base->hero->x) + (base->w_map * (int)(base->hero->y + base->hero->y_dir * base->time->move_speed)));

		if (check_hit_wall(base, ind_x))
			base->hero->x += base->hero->x_dir * base->time->move_speed;
		if (check_hit_wall(base, ind_y))
			base->hero->y += base->hero->y_dir * base->time->move_speed;
	}
	if (step == 2)
	{
		ind_x = ((int)(base->hero->x - base->hero->x_dir * base->time->move_speed) + ((int)base->hero->y * base->w_map));
		ind_y = ((int)(base->hero->x) + (base->w_map * (int)(base->hero->y - base->hero->y_dir * base->time->move_speed)));
		//ft_printf("%d %d\n", ind_x, ind_y);
		if (check_hit_wall(base, ind_x))
			base->hero->x -= base->hero->x_dir * base->time->move_speed;
		if (check_hit_wall(base, ind_y))
			base->hero->y -= base->hero->y_dir * base->time->move_speed;
	}
//	ft_printf("  ++%f %f++\n", base->hero->x_dir, base->hero->y_dir);
	ft_printf("%f %f | %d %d, test_x=%d  test_y=%d\n", base->hero->x, base->hero->y, ind_x, ind_y, check_hit_wall(base, ind_x), check_hit_wall(base, ind_y));

	ray_casting(base);
}

void	rotation(t_base *base, int rl)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = base->hero->x_dir;
	old_plane_x = base->dist->x_plane;
	if (rl == 1)
	{
		base->hero->x_dir = base->hero->x_dir * cos(-base->time->rot_speed) - base->hero->y_dir * sin(-base->time->rot_speed);
		base->hero->y_dir = old_dir_x * sin(-base->time->rot_speed) + base->hero->y_dir * cos(-base->time->rot_speed);
		base->dist->x_plane = base->dist->x_plane * cos(-base->time->rot_speed) - base->dist->y_plane * sin(-base->time->rot_speed);
		base->dist->y_plane = old_plane_x * sin(-base->time->rot_speed) + base->dist->y_plane * cos(-base->time->rot_speed);
	}
	if (rl == 2)
	{
		base->hero->x_dir = base->hero->x_dir * cos(base->time->rot_speed) - base->hero->y_dir * sin(base->time->rot_speed);
		base->hero->y_dir = old_dir_x * sin(base->time->rot_speed) + base->hero->y_dir * cos(base->time->rot_speed);
		base->dist->x_plane = base->dist->x_plane * cos(base->time->rot_speed) - base->dist->y_plane * sin(base->time->rot_speed);
		base->dist->y_plane = old_plane_x * sin(base->time->rot_speed) + base->dist->y_plane * cos(base->time->rot_speed);
	}
	//ft_printf("  ==%f %f==\n", base->hero->x_dir, base->hero->y_dir);
	ray_casting(base);
}
