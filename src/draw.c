/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:24 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/18 21:18:08 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/wolf.h"

void	draw_wall(t_base *base)
{
	int q;
	int	r;
	int ceiling;
	int wall;

	q = 0;
	r = 0;
	wall = 0;
	while (r < 320)
	{
    	ceiling = (base->height - base->h_wall[r]) / 2;
		while (q < base->height * base->width)
		{
			if (ceiling > 0 || wall > base->h_wall[r])
				base->img_data[q] = 0;
			else
			{
				base->img_data[q] = 0x808080;
				wall++;
			}
			ceiling--;
			q += base->width;
		}
		r++;
		q = r;
		wall = 0;
	}
	mlx_put_image_to_window(base->mlx_ptr, base->win_ptr, base->img_ptr, 0, 0);
}