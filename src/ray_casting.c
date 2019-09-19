/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:49:39 by tglandai          #+#    #+#             */
/*   Updated: 2019/09/19 14:44:51 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	dda_init(t_wolf3d *t)
{
	t->x_delta_dis = sqrt(1 + (t->y_raydir * t->y_raydir)
			/ (t->x_raydir * t->x_raydir));
	t->y_delta_dis = sqrt(1 + (t->x_raydir * t->x_raydir)
			/ (t->y_raydir * t->y_raydir));
	if (t->x_raydir < 0)
	{
		t->x_step = -1;
		t->x_side_dist = (t->x_rayp - t->x_map) * t->x_delta_dis;
	}
	else
	{
		t->x_step = 1;
		t->x_side_dist = (t->x_map + 1.0 - t->x_rayp) * t->x_delta_dis;
	}
	if (t->y_raydir < 0)
	{
		t->y_step = -1;
		t->y_side_dist = (t->y_rayp - t->y_map) * t->y_delta_dis;
	}
	else
	{
		t->y_step = 1;
		t->y_side_dist = (t->y_map + 1.0 - t->y_rayp) * t->y_delta_dis;
	}
}

void	dda(t_wolf3d *t)
{
	t->hit = 0;
	while (t->hit == 0)
	{
		if (t->x_side_dist < t->y_side_dist)
		{
			t->x_side_dist += t->x_delta_dis;
			t->x_map += t->x_step;
			t->side = 0;
		}
		else
		{
			t->y_side_dist += t->y_delta_dis;
			t->y_map += t->y_step;
			t->side = 1;
		}
		if (t->map[t->x_map][t->y_map] > 0)
			t->hit = 1;
	}
}

void	ray_casting_init(t_wolf3d *t, int x)
{
	t->x_cam = 2 * x / (double)(WINX) - 1;
	t->x_rayp = t->x_pos;
	t->y_rayp = t->y_pos;
	t->x_raydir = t->x_dir + t->x_plane * t->x_cam;
	t->y_raydir = t->y_dir + t->y_plane * t->x_cam;
	t->x_map = (int)t->x_rayp;
	t->y_map = (int)t->y_rayp;
	dda_init(t);
	dda(t);
	if (t->side == 0)
		t->walldist = (t->x_map - t->x_rayp +
				(1 - t->x_step) / 2) / t->x_raydir;
	else
		t->walldist = (t->y_map - t->y_rayp +
				(1 - t->y_step) / 2) / t->y_raydir;
}

void	floor_and_ceiling(t_wolf3d *t, int x)
{
	if (t->texture == 0)
	{
		if (t->start > 0)
		{
			t->color = 0x4682b4;
			t->y = -1;
			if (x < WINX && t->y < WINY)
				while (++t->y < t->start)
				{
					ft_memcpy(t->img_ptr + 4 * WINX * t->y + x * 4,
							&t->color, sizeof(int));
				}
		}
	}
	if (t->end > 0)
	{
		t->color = 0x333333;
		t->y = t->end - 1;
		if (x < WINX && t->y < WINY)
			while (++t->y < WINY)
				ft_memcpy(t->img_ptr + 4 * WINX * t->y + x * 4,
						&t->color, sizeof(int));
	}
}

void	ray_casting(t_wolf3d *t)
{
	t->x = -1;
	t->img = mlx_new_image(t->mlx, WINX, WINY);
	t->img_ptr = mlx_get_data_addr(t->img, &t->bpp, &t->sl, &t->endian);
	if (t->texture == 1)
		draw_sky(t);
	while (++t->x < WINX)
	{
		ray_casting_init(t, t->x);
		t->lineheight = (int)(WINY / t->walldist);
		t->start = -t->lineheight / 2 + WINY / 2;
		if (t->start < 0)
			t->start = 0;
		t->end = t->lineheight / 2 + WINY / 2;
		if (t->end >= WINY)
			t->end = WINY - 1;
		if (t->side == 1)
			t->color = 0x9932cc;
		else
			t->color = 0x2e8b57;
		draw_wall(t->x, t->start - 1, t->end, t);
		if (t->texture == 0)
			floor_and_ceiling(t, t->x);
	}
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_destroy_image(t->mlx, t->img);
}
