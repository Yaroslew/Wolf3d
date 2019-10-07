/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:24 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/08 02:24:51 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf.h"

static SDL_Color    get_color(SDL_Surface *surface, int x, int y) // получение пикселя используя координаты текстур
{
	uint8_t *color;

	color = surface->pixels	+ surface->pitch * y + surface->format->BytesPerPixel * x;
	return ((SDL_Color){color[0], color[1], color[2], color[3]});
}

static void		draw_column(t_base *base, int column, int x)
{
	int y;
	int d;

	y = base->start_draw[column];
	while (y < base->end_draw[column])
	{
		d = y * 256 - base->height * 128 + base->line_height[column] * 128;
		base->color->tex_y = ((d * base->color->h_w_tex) / base->line_height[column]) / 256;
		base->sdl->buf[y * base->width + column] = get_color(base->sdl->walls[base->select_wall[column]], x, base->color->tex_y);
		y++;
	}
}

void	draw_wall(t_base *base)
{
	int q;

	if (base->hero->side == 0)
		base->color->wall_x = base->hero->y + base->dist->walldist * base->dist->y_raydir;
	else
		base->color->wall_x = base->hero->x + base->dist->walldist * base->dist->x_raydir;
	base->color->wall_x -= floor(base->color->wall_x);

	base->color->tex_x = (int)(base->color->wall_x * (double)base->color->h_w_tex);
	if (base->hero->side == 0 && base->dist->x_raydir > 0)
		base->color->tex_x = base->color->h_w_tex - base->color->tex_x - 1;
	if (base->hero->side == 1 && base->dist->y_raydir < 0)
		base->color->tex_x = base->color->h_w_tex - base->color->tex_x - 1;

	q = 0;
	int x = 0;

	while (q < base->width)
	{
		draw_column(base, q, x);
		q++;
		x++;
		if (x > base->color->h_w_tex - 1)
			x = 0;
	}

	SDL_UpdateTexture(base->sdl->texture, NULL, base->sdl->buf, base->width * 4);
	SDL_RenderCopy(base->sdl->ren, base->sdl->texture, NULL, NULL);
	SDL_RenderPresent(base->sdl->ren);

}

void		frames(t_base *base)
{
	base->time->old_time = base->time->time;
	base->time->time = SDL_GetTicks();
	base->time->frame_time = (base->time->time - base->time->old_time) / 1000.0;
	clear_sdl_buf(base);
	draw_wall(base);
	clear_sdl_buf(base);
	base->time->move_speed = 0.1;
	base->time->rot_speed = 0.1;
//	base->time->move_speed = base->time->frame_time * 2.0;
//	base->time->rot_speed = base->time->frame_time * 1.0;
}
