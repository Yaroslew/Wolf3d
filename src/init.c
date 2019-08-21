/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:24:09 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/18 18:45:18 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_base *init_base(void)
{
	t_base *base;

	if (!(base = malloc(sizeof(t_base) * 1)))
		mess_err(0);
	base->width = 320;
	base->height = 200;
	base->w_map = 20;
	base->h_map = 20;


	return (base);
}

void	init_hero(t_base *base, int q, int y)
{
	if (!(base->hero = malloc(sizeof(t_hero) * 1)))
		mess_err(0);

	base->hero->fov = 1.0472;
	base->hero->h_man = 32;
	base->hero->x = (q * 64) + 32;
	base->hero->y = (y * 64) + 32;
	base->hero->angle_vector = 0.785398;

}

void	init_mlx(t_base *base)
{
	int bits;
	int size;
	int endian;

	base->mlx_ptr = mlx_init();
	base->win_ptr = mlx_new_window(base->mlx_ptr, 320, 200, "Wolf3d");
	base->img_ptr = mlx_new_image(base->mlx_ptr, 320, 200);
	base->img_data = (int*)mlx_get_data_addr(base->img_ptr, &bits, &size, &endian);
}
