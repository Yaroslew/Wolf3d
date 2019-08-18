/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:51:03 by tglandai          #+#    #+#             */
/*   Updated: 2019/08/18 16:32:15 by tjuana           ###   ########.fr       */
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
    int         len_line;
    
    
}				t_wolf3d;

void	        mlx_win_init(t_wolf3d *w);
int     		ft_close(void);
int     		read_map(t_wolf3d *w, char **av);

#endif