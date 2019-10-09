/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:43:10 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/09 12:32:06 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	clear_sdl_buf(t_base *base)
{
	int q;

	q = 0;
	while (q < 1000000)
	{
		base->sdl->buf[q].a = 0;
		base->sdl->buf[q].b = 0;
		base->sdl->buf[q].g = 0;
		base->sdl->buf[q].r = 0;
		q++;
	}
}

void	clear_temp_dist(t_base *base)
{
	base->dist->temp[0] = -1;
	base->dist->temp[1] = -1;
}
