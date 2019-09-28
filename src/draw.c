/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:24 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/28 14:32:39 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/wolf.h"

SDL_Color    get_color(SDL_Surface *surface, int x, int y)
{
	uint8_t *color;

	while (x > 63)
		x /= 64;
	while (y > 63)
		y /= 64;

	color = surface->pixels + surface->pitch * y + surface->format->BytesPerPixel * x;
	//ft_printf("%d %d %d %d\n", (SDL_Color){color[0], color[1], color[2], color[3]});
	return ((SDL_Color){color[0], color[1], color[2], color[3]});
}


void	draw_wall(t_base *base)
{
	int q;
	int line;

	q = 0;
	line = 0;
	while (line < base->width)
	{
		while (q < base->height)
		{
			if (q > base->start_draw[line] && q < base->end_draw[line])
			{
				base->sdl->buf[base->width * q + line] = get_color(base->sdl->wall_s, q * base->width, q);
			}

			q++;
		}
		q = 0;
		line++;
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
	base->time->move_speed = base->time->frame_time * 5.0;
	base->time->rot_speed = base->time->frame_time * 3.0;
}
