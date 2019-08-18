/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:24 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/18 15:10:07 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF_H
#define WOLF3D_WOLF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>


typedef struct s_map
{
	int			x;
	int			y;
	int			data;
}				t_map;

void	mess_err(int num);
int		check_map(char *str, int sum_point);



#endif
