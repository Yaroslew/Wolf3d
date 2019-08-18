/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:21 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/18 15:08:24 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int main(int ac, char **av)
{
	int sum_point;
//	t_base	*base;

	if (ac != 2)
		mess_err(1);
	else
		sum_point = check_map(av[1], sum_point);
	ft_printf("%d\n", sum_point);
//	base = init_base(sum_point);
//	record_map(base);

	return 0;
}