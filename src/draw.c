/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:24 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/08 13:13:38 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/wolf.h"

static	SDL_Color	get_color(SDL_Surface *wall, int x, int y)
{
	uint8_t	*color;
	color = wall->pixels + wall->pitch * y + wall->format->BytesPerPixel * x;
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
				ft_printf("!!!\n");
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
