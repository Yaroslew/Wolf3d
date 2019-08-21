/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:21 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/18 16:44:56 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int de_key(int key, t_base *base)
{
	if (key == 53)
		exit(0);
	return (0);
}

int main(int ac, char **av)
{
	t_base	*base;

	base = init_base();
	if (ac != 2)
		mess_err(1);
	else
		check_map(av[1], base);
	record_map(av[1], base);
	ray_casting(base);

	init_mlx(base);

	draw_wall(base);

	mlx_hook(base->win_ptr, 2, 0, de_key, base);
	mlx_loop(base->mlx_ptr);

	return (0);
}