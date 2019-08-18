/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 16:51:37 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/18 19:09:44 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ray_casting(t_base *base)
{
	distance(base);
}

void	distance(t_base *base)
{
	int ay;
	int ax;
	int ya;
	int xa;

	if (base->hero->angle_vector > 0 && base->hero->angle_vector < 3.14159)
	{
		ay = (base->hero->y / 64) * 64 - 1;
		ay /= 64;
	}
	else
	{
		ay = (base->hero->y / 64) * 64 + 64 + 0.5;
	}
	ax = (base->hero->x + (base->hero->y - ay)) / tan(1.0472); //неправильно считаю координаты игрока (init_hero)?
	ax /= 64;
	ft_printf("x=%d y=%d\n", ax, ay);

	// ошибка (по оси x) при наличии игрока в нижнем правом углу, показывает ближайший квадрат не над ним, а правее на 2.
//	if (base->hero->angle_vector > 0 && base->hero->angle_vector < 3.14159)
//		ya = -64;
//	else
//		ya = 64;
//	xa = 64 / tan(1.0472);
}

void	check_walls(t_base *base, int ax, int ay)
{

}