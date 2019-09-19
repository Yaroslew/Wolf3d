/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:30:10 by tjuana            #+#    #+#             */
/*   Updated: 2019/09/19 17:21:18 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pxl_to_img(t_wolf3d *w, int x, int y, int color)
{
	if (w->texture == 1 && x < WINX && y < WINY)
	{
		w->y_text = abs((((y * 256 - WINY * 128 + w->lineheight * 128) * 64)
					/ w->lineheight) / 256);
		ft_memcpy(w->img_ptr + 4 * WINX * y + x * 4,
				&w->tex[w->id].data[w->y_text % 64 * w->tex[w->id].sizeline +
				w->x_text % 64 * w->tex[w->id].bpp / 8], sizeof(int));
	}
	else if (x < WINX && y < WINY)
		ft_memcpy(w->img_ptr + 4 * WINX * y + x * 4,
				&color, sizeof(int));
}

void	draw_wall(int x, int start, int end, t_wolf3d *w)
{
	if (w->texture == 1)
	{
		w->id = w->map[w->x_map][w->y_map];
		if (w->side == 0)
			w->x_wall = w->y_rayp + w->walldist * w->y_raydir;
		else
			w->x_wall = w->x_rayp + w->walldist * w->x_raydir;
		w->x_text = (int)(w->x_wall * (double)(64));
		if (w->side == 0 && w->x_raydir > 0)
			w->x_text = 64 - w->x_text - 1;
		if (w->side == 1 && w->y_raydir < 0)
			w->x_text = 64 - w->x_text - 1;
		w->x_text = abs(w->x_text);
	}
	while (++start <= end)
		put_pxl_to_img(w, x, start, w->color);
}

void	draw_sky(t_wolf3d *w)
{
	w->x_text = 0;
	while (w->x_text < WINX)
	{
		w->y_text = 0;
		while (w->y_text < WINY / 2)
		{
			ft_memcpy(w->img_ptr + 4 * WINX * w->y_text + w->x_text * 4,\
			&w->tex[6].data[w->y_text % 512 * w->tex[6].sizeline +\
			w->x_text % 512 * w->tex[6].bpp / 8], sizeof(int));
			w->y_text++;
		}
		w->x_text++;
	}
}

void	draw_floor(t_wolf3d *w)
{
	w->x_text = 0;
	while (w->x_text < WINX)
	{
		w->y_text = WINY / 2;
		while (w->y_text < WINY)
		{
			ft_memcpy(w->img_ptr + 4 * WINX * w->y_text + w->x_text * 4,
					&w->tex[5].data[w->y_text % 64 * w->tex[5].sizeline +
					w->x_text % 64 * w->tex[5].bpp / 8], sizeof(int));
			w->y_text++;
		}
		w->x_text++;
	}
}
