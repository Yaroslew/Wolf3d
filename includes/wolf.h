/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:08:24 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/10 20:36:40 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF_H
# define WOLF3D_WOLF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <stdlib.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

# define STH "/img/wall1.jpg"
# define NRTH "/img/wall2.jpg"
# define WEST "/img/wall3.png"
# define EAST "/img/wall4.jpg"
# define BACK "/img/back.jpg"
# define WDTH 1000
# define HGTH 800

typedef struct	s_pntd
{
	double		x;
	double		y;
}				t_pntd;

typedef struct	s_pnti
{
	int			x;
	int			y;
}				t_pnti;

typedef struct	s_hero
{
	t_pntd		pnt;
	t_pntd		dir;
	t_pnti		step;
	int			hit;
	int			side;
}				t_hero;

typedef struct	s_dist
{
	t_pntd		plane;
	t_pntd		raydir;
	t_pnti		map;
	t_pntd		sidedist;
	t_pntd		deltadist;
	double		time;
	double		time_old;
	double		x_camera;
	double		walldist;
	int			temp[2];
}				t_dist;

typedef struct	s_map
{
	int			x;
	int			y;
	char		data;
}				t_map;

typedef	struct	s_time
{
	double		time;
	double		old_time;
	double		frame_time;
	double		move_speed;
	double		rot_speed;
}				t_time;

typedef struct	s_colors
{
	t_pnti		tex;
	int			tex_num;
	double		wall_x;
	int			h_w_tex;
}				t_color;

typedef struct	s_sdl
{
	t_pnti			tex_p;
	SDL_Window		*win;
	SDL_Event		event;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
	SDL_Surface		**walls;
	SDL_Color		buf[1000000];
}				t_sdl;

typedef struct	s_base
{
	t_pnti		win_s;
	t_pnti		map_s;
	t_map		*map;
	t_hero		*hero;
	t_dist		*dist;
	t_sdl		*sdl;
	t_time		*time;
	t_color		*color;
	int			line_height[1000];
	int			start_draw[1000];
	int			end_draw[1000];
	int			select_wall[1000];
	int			check_wall[8];
}				t_base;

void			mess_err(int num);
void			check_map(char *str, t_base *base);
t_base			*init_base(void);
void			record_map(char *str, t_base *base);
void			init_hero(t_base *base, int q, int y);
void			ray_casting(t_base *base);
void			distance(t_base *base);
int				check_walls(t_base *base, int x, int y);
void			height_wall(t_base *base);
void			prepare_wall(t_base *base);
void			draw_wall(t_base *base);

void			put_walls(t_sdl *sdl);
void			init_sdl(t_base *base);
void			esc(int a);
void			handler(t_base *base);

void			move_forward(t_base *base);
void			move_back(t_base *base);
void			rot_rght(t_base *base);
void			rot_lft(t_base *base);
void			init_time(t_base *base);

void			base_draw(t_base *base, int x);
void			wall_dist(t_base *base, int x);
void			check_hero_step(t_base *base);
void			init_act_pos(t_base *base, int x);

void			frames(t_base *base);

void			clear_sdl_buf(t_base *base);
void			clear_temp_dist(t_base *base);

#endif
