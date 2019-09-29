/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:24 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/30 02:45:33 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/wolf.h"

static SDL_Color    get_color(SDL_Surface *surface, int x, int y) // получение пикселя используя координаты текстур
{
	uint8_t *color;

	color = surface->pixels	+ surface->pitch * y + surface->format->BytesPerPixel * x;

	return ((SDL_Color){color[0], color[1], color[2], color[3]});
}

void	draw_wall(t_base *base)
{


	// здесь должно быть рисование стен.

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
