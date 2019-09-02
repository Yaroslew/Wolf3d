/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:51:03 by tglandai          #+#    #+#             */
/*   Updated: 2019/09/02 16:26:08 by tjuana           ###   ########.fr       */
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

typedef struct	s_tex
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_text;

typedef struct	s_wolf3d
{
	t_text		tex[9];
	char		*map_name;
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			**map;
	int			nb_lines;
	int			len_line;
	int			bpp;
	int			endian;
	int			texture;
	int			x_map;
	int			y_map;
	int			x_text;
	int			x_step;
	int			y_step;
	int			y_text;
	int			id;
	double		x_pos;
	double		y_pos;
	double		y_dir;
	double		x_dir;
	double		x_plane;
	double		y_plane;
	double		x_cam;
	double		x_rayp;
	double		y_rayp;
	double		x_raydir;
	double		y_raydir;
	double		x_side_dist;
	double		y_side_dist;
	double		x_delta_dis;
	double		y_delta_dis;
	double		ms;
	double		rs;
	double		walldist;
	double		x_wall;
	double		move_up;
	double		move_down;
	double		move_right;
	double		move_left;
	int			lineheight;
	int			sl;
	int			start;
	int			end;
	int			color;
	int			x;
	int			y;
	int			side;
	int			hit;


	
}				t_wolf3d;

void			mlx_win_init(t_wolf3d *w);
int				ft_close(void);
int				read_map(t_wolf3d *w, char **av);
int				check_side(t_wolf3d *w);
int				second_read(t_wolf3d *w, char **av);
int				check_map(char *buff, t_wolf3d *w);
void			wolf3d_init(t_wolf3d *w);
void			ft_display_map(t_wolf3d *map);
void			put_pxl_to_img(t_wolf3d *w, int x, int y, int color);
void			draw_sky(t_wolf3d *w);
void			ray_casting(t_wolf3d *w);
void			dda_init(t_wolf3d *t);
void			dda(t_wolf3d *t);
void			ray_casting_init(t_wolf3d *w, int x);
void			floor_and_ceiling(t_wolf3d *t, int x);
void			draw_wall(int x, int start, int end, t_wolf3d *w);

#endif
