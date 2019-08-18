/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:21 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/18 15:18:45 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int main(int ac, char **av)
{
//	t_base	*base;

	if (ac != 2)
		mess_err(1);
	else
		check_map(av[1]);
//	base = init_base(sum_point);
//	record_map(base);

	return 0;
}