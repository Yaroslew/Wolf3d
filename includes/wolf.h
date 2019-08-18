/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:24 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/18 17:55:23 by pcorlys-         ###   ########.fr       */
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

typedef struct s_hero
{
	int			x;
	int			y;
	double		angle_vector;
	double 		fov;
	int			h_man;
	int			distance;

}				t_hero;

typedef struct s_map
{
	int			x;
	int			y;
	char		data;
}				t_map;

typedef struct	s_base
{
	int			width;
	int			height;
	t_map		*map;
	t_hero		*hero;

	int			w_map;
	int			h_map;


}t_base;

void			mess_err(int num);
void			check_map(char *str, t_base *base);
t_base			*init_base(void);
void			record_map(char *str, t_base *base);
void			init_hero(t_base *base, int q, int y);
void			ray_casting(t_base *base);
void			distance(t_base *base);



#endif
