/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:51:37 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/06 16:31:51 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ray_casting(t_base *base)
{
	distance(base);
}

static void	select_walls(t_base *base, int x)
{
	if (base->dist->y_raydir < 0 && (base->dist->x_raydir >= 0 && base->dist->x_raydir <= 1))
		base->select_wall[x] = 0;
	else if (base->dist->x_raydir < 0 && (base->dist->y_raydir >= -0.5 && base->dist->y_raydir <= 0.5))
		base->select_wall[x] = 1;
	else if (base->dist->x_raydir > 0 && (base->dist->y_raydir >= -0.5 && base->dist->y_raydir <= 0.5))
		base->select_wall[x] = 3;
	else if (base->dist->y_raydir > 0 && (base->dist->x_raydir >= -0.5 && base->dist->x_raydir <= 0.5))
		base->select_wall[x] = 2;
	else
		base->select_wall[x] = 4;
	if (x == 0 || x == 999)
		ft_printf("%d  %d | %f  %f\n", x, base->select_wall[x], base->dist->y_raydir, base->dist->x_raydir);

}

void	distance(t_base *base)
{
	int x;

	x = 0;
	while (x < base->width)
	{
		base->dist->x_camera = 2 * x / (double)base->width - 1;
		base->dist->x_raydir = base->hero->x_dir + base->dist->x_plane * base->dist->x_camera;
		base->dist->y_raydir = base->hero->y_dir + base->dist->y_plane * base->dist->x_camera;
		base->dist->x_deltadist = fabs(1.0 / base->dist->x_raydir);
		base->dist->y_deltadist = fabs(1.0 / base->dist->y_raydir);
		base->dist->x_map = (int)base->hero->x;
		base->dist->y_map = (int)base->hero->y;

		if (base->dist->x_raydir < 0)
		{
			base->hero->x_step = -1;
			base->dist->x_sidedist = (base->hero->x - base->dist->x_map) * base->dist->x_deltadist;
		}
		else
		{
			base->hero->x_step = 1;
			base->dist->x_sidedist = (base->dist->x_map + 1.0 - base->hero->x) * base->dist->x_deltadist;
		}
		if (base->dist->y_raydir < 0)
		{
			base->hero->y_step = -1;
			base->dist->y_sidedist = (base->hero->y - base->dist->y_map) * base->dist->y_deltadist;
		}
		else
		{
			base->hero->y_step = 1;
			base->dist->y_sidedist = (base->dist->y_map + 1.0 - base->hero->y) * base->dist->y_deltadist;
		}
			// DDA
		while (base->hero->hit == 0)
		{
			if (base->dist->x_sidedist < base->dist->y_sidedist)
			{
				base->dist->x_sidedist += base->dist->x_deltadist;
				base->dist->x_map += base->hero->x_step;
				base->hero->side = 0;
			}
			else
			{
				base->dist->y_sidedist += base->dist->y_deltadist;
				base->dist->y_map += base->hero->y_step;
				base->hero->side = 1;
			}
			if (base->map[base->dist->y_map * base->h_map + base->dist->x_map].data == 'x' )
			{
				base->hero->hit = 1;
				select_walls(base, x);
			}

		}
		if (base->hero->side == 0)
			base->dist->walldist = (base->dist->x_map - base->hero->x + (1.0 - base->hero->x_step) / 2) / base->dist->x_raydir;
		else
			base->dist->walldist = (base->dist->y_map - base->hero->y + (1.0 - base->hero->y_step) / 2) / base->dist->y_raydir;
		if (base->dist->walldist == 0)
			base->line_height[x] = 0;
		else
			base->line_height[x] = (int)(base->height / base->dist->walldist);


		base->start_draw[x] = -base->line_height[x] / 2 + base->height / 2;
		if (base->start_draw[x] < 0)
			base->start_draw[x] = 0;
		base->end_draw[x] = base->line_height[x] / 2 + base->height / 2;
		if (base->end_draw[x] >= base->height)
			base->end_draw[x] = base->height - 1;
		x++;
		base->hero->hit = 0;
	}
	draw_wall(base);
	frames(base);

	return;
}
