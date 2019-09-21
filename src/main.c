/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:21 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/18 00:11:18 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int main(int ac, char **av)
{
	t_base	*base;

	if (ac != 2)
		mess_err(1);
	base = init_base();
	check_map(av[1], base);
	record_map(av[1], base);
	ray_casting(base);
//	draw_wall(base);
	handler(base);
	return (0);
}
