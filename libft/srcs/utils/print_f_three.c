/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:33:54 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/12 10:59:04 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		space_nan(int len, t_flags flags)
{
	if (flags.minus)
	{
		ft_putstr("nan");
		len += ft_print_spaces(flags, 3);
	}
	else
	{
		len += ft_print_spaces(flags, 3);
		ft_putstr("nan");
	}
	return (len);
}
