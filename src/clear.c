/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:43:10 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/30 01:00:10 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	clear_sdl_buf(t_base *base)
{
	int q;

	q = 0;
	while (q < 1000000)
	{
		base->sdl->buf[q].a = 0 ;
		base->sdl->buf[q].b = 0 ;
		base->sdl->buf[q].g = 0 ;
		base->sdl->buf[q].r = 0 ;
		q++;
	}
}
