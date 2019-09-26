/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:24 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/09/26 20:44:42 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF_H
#define WOLF3D_WOLF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <stdlib.h>
# include <math.h> //https://permadi.com/1996/05/ray-casting-tutorial-14/
# include <sys/stat.h>
# include <fcntl.h>
#include "/Users/pcorlys-/Library/Frameworks/SDL2.framework/Headers/SDL.h"

typedef struct s_hero
{
	double		x;
	double 		y;
	double 		x_dir;
	double 		y_dir;
	int			x_step;
	int			y_step;
	int			hit;
	int			side;

}				t_hero;

typedef struct	s_dist
{
	double 		x_plane;
	double 		y_plane;
	double 		time;
	double 		time_old;
	double 		x_camera;
	double 		x_raydir;
	double 		y_raydir;

	int			x_map;
	int			y_map;
	double 		x_sidedist;
	double 		y_sidedist;
	double 		x_deltadist;
	double 		y_deltadist;
	double 		walldist;

}				t_dist;

typedef struct s_map
{
	int			x;
	int			y;
	char		data;
}				t_map;

typedef	struct s_time
{
	double		time;
	double 		old_time;
	double 		frame_time;
	double 		move_speed;
	double 		rot_speed;

}				t_time;

typedef struct	s_sdl
{
	SDL_Window		*window;
	SDL_Event		event;
	SDL_Renderer	*ren;

	SDL_Texture		*texture;

//	SDL_Surface		*wall_n;
//	SDL_Surface		*wall_w;
//	SDL_Surface		*wall_e;
	SDL_Surface		*wall_s;
	SDL_Color		buf[1000000];

}				t_sdl;

typedef struct	s_base
{
	int			width;
	int			height;
	int			w_map;
	int			h_map;

	t_map		*map;
	t_hero		*hero;
	t_dist		*dist;
	t_sdl		*sdl;
	t_time		*time;

	int			line_height[1000];
	int			start_draw[1000];
	int			end_draw[1000];

}t_base;

void			mess_err(int num);
void			check_map(char *str, t_base *base);
t_base			*init_base(void);
void			record_map(char *str, t_base *base);
void			init_hero(t_base *base, int q, int y);
void			ray_casting(t_base *base);
void			distance(t_base *base);
int				check_walls(t_base *base, int x, int y);
void			height_wall(t_base *base);
void			draw_wall(t_base *base);

void			init_sdl(t_base *base);
void			esc(int a);
void			handler(t_base *base);

void			move_hero(t_base *base, int step);
void			init_time(t_base *base);

void			frames(t_base *base);

// clear
void			clear_sdl_buf(t_base *base);



#endif
