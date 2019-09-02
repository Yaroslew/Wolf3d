/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:30:15 by tjuana            #+#    #+#             */
/*   Updated: 2019/09/02 16:25:39 by tjuana           ###   ########.fr       */
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

void	ray_casting_init(t_wolf3d *w, int x)
{
	w->x_cam = 2 * x / (double)(WINX) - 1;
	w->x_rayp = w->x_pos;
	w->y_rayp = w->y_pos;
	w->x_raydir = w->x_dir + w->x_plane * w->x_cam;
	w->y_raydir = w->y_dir + w->y_plane * w->x_cam;
	w->x_map = (int)w->x_rayp;
	w->y_map = (int)w->y_rayp;
	dda_init(w);
	dda(w);
	if (w->side == 0)
		w->walldist = (w->x_map - w->x_rayp +
				(1 - w->x_step) / 2) / w->x_raydir;
	else
		w->walldist = (w->y_map - w->y_rayp +
				(1 - w->y_step) / 2) / w->y_raydir;
}

void	floor_and_ceiling(t_wolf3d *t, int x)
{
if (t->texture == 0){
	if (t->start > 0)
	{
		t->color = 0x66CCFF;
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

void	ray_casting(t_wolf3d *w)
{
	w->x = -1;
	w->img = mlx_new_image(w->mlx, WINX, WINY);
	w->img_ptr = mlx_get_data_addr(w->img, &w->bpp, &w->sl, &w->endian);
	if (w->texture == 1)
		draw_sky(w);
	while (++w->x < WINX)
	{
		ray_casting_init(w, w->x);
		w->lineheight = (int)(WINY / w->walldist);
		w->start = -w->lineheight / 2 + WINY / 2;
		if (w->start < 0)
			w->start = 0;
		w->end = w->lineheight / 2 + WINY / 2;
		if (w->end >= WINY)
			w->end = WINY - 1;
		if (w->side == 1)
			w->color = 0xdd8800;
		else
			w->color = 0x00FF00;
		draw_wall(w->x, w->start - 1, w->end, w);
		// if (t->texture == 0)
			floor_and_ceiling(w, w->x);
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
}