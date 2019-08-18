/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:51:03 by tglandai          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/18 16:32:15 by tjuana           ###   ########.fr       */
=======
/*   Updated: 2019/08/18 14:55:57 by tjuana           ###   ########.fr       */
>>>>>>> 55154a7773987e36a2eb7e5889c94adf32936d75
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define WINX 1024
# define WINY 768
# define USAGE "usage: wolf3d \"map\"\n"


typedef struct	s_wolf3d
{
    char        *map_name;
    void        *mlx;
    void        *win;
    void        *img;
    void        *img_ptr;
    int         **map;
    int         nb_lines;
<<<<<<< HEAD
    int         len_line;
    
    
=======
>>>>>>> 55154a7773987e36a2eb7e5889c94adf32936d75
}				t_wolf3d;

void	        mlx_win_init(t_wolf3d *w);
int     		ft_close(void);
int     		read_map(t_wolf3d *w, char **av);
<<<<<<< HEAD

=======
>>>>>>> 55154a7773987e36a2eb7e5889c94adf32936d75
#endif