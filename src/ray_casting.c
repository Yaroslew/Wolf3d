/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:51:37 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/18 21:29:06 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ray_casting(t_base *base)
{
	distance(base);
	height_wall(base);

	int q = 0;
//	while (q < 320)
//	{
//		ft_printf("%f\n", base->h_wall[q]);
//		q++;
//	}
}

void	height_wall(t_base *base)
{
	int q;
	double temp;

	q = 0;
	base->aqua = (60.0 / 320.0) * M_PI/180.0;
	temp = base->aqua * 160.0;

	while (q < 320)
	{
		base->h_distance[q] = base->distance * cos(temp);
		temp -= base->aqua;
		q++;
	}
	q = 0;
	while (q < 320)
	{
		base->h_wall[q] = 64.0 / base->h_distance[q];
		q++;
	}
}

void	distance(t_base *base)
{
	if (!(base->dist = malloc(sizeof(t_dist) * 1)))
		mess_err(0);

	if (base->hero->angle_vector > 0 && base->hero->angle_vector < 3.14159)
	{
		base->dist->ay = ((base->hero->y / 64) * 64 - 1) - 0.5;
		base->dist->Ya = -64;
	}
	else
	{
		base->dist->ay = ((base->hero->y / 64) * 64 + 64) - 0.5;
		base->dist->Ya = 64;
	}
	base->dist->ax = (base->hero->x + (base->hero->y - base->dist->ay) / tan(base->hero->fov));
	base->dist->Xa = 64 / tan(base->hero->fov);
	if (check_walls(base, base->dist->ax / 64, base->dist->ax /64))
		return;
	while (!(check_walls(base, base->dist->ax / 64, base->dist->ay /64)))
	{
		base->dist->ax = (base->dist->ax + base->dist->Xa);
		base->dist->ay = (base->dist->ay + base->dist->Ya);
	}
	free(base->dist);
	return;
}

int		check_walls(t_base *base, int x, int y)
{
	if (base->map[x + (y * base->w_map)].data == 'x')
		base->distance = ABS(base->hero->y - base->dist->ay) / sin(base->hero->fov); //странные расхождения при синусе.косинусе
	else
		return (0);
	return (1);
}