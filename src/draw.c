/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:30:10 by tjuana            #+#    #+#             */
/*   Updated: 2019/08/18 17:44:47 by tjuana           ###   ########.fr       */
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
