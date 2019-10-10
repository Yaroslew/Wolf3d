/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:21 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/10 21:57:56 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(int ac, char **av)
{
	t_base	*base;

	if (ac != 2)
		mess_err(1);
	base = init_base();
	check_map(av[1], base);
	record_map(av[1], base);
	
	int r = 0;
	while (r < base->map_s.x * base->map_s.y)
	{
		ft_printf("%d %d %c\n", base->map[r].x, base->map[r].y, base->map[r].data);
		r++;
	}
	ray_casting(base);
	handler(base);
	return (0);
}
