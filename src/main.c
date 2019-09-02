/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:16:59 by tjuana            #+#    #+#             */
/*   Updated: 2019/09/02 15:13:09 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	mlx_win_init(t_wolf3d *w)
{
	char	*title;

	title = ft_strjoin("Wolf3d : ", w->map_name);
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, WINX, WINY, title);
	ft_strdel(&title);
}

void	wolf3d_init(t_wolf3d *w)
{
	w->x_pos = 3;
	w->y_pos = 3;
	w->x_dir = -1;
	w->y_dir = 0;
	w->x_plane = 0;
	w->y_plane = 0.66;
	w->ms = 0.05;
	w->rs = 0.05;
	w->move_up = 0;
	w->move_down = 0;
	w->move_left = 0;
	w->move_right = 0;
	w->x_text = 0;
	w->y_text = 0;
	w->texture = 1;
}

void			ft_display_map(t_wolf3d *map)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (j < map->len_line)
		{
			ft_putnbr(map->map[i][j++]);
			(j < map->len_line) ? ft_putchar('\t') : 0;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	t_wolf3d *w;

	if (ac != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	if (!(w = (t_wolf3d *)malloc(sizeof(t_wolf3d))))
		return (0);
	if (!(read_map(w, av)))
		return (0);
	mlx_win_init(w);
	wolf3d_init(w);
	ray_casting(w);
	mlx_hook(w->win, 17, 0L, ft_close, w);
		
	//ft_display_map(w);
	//mlx_loop_hook(w->mlx, move, w);
	mlx_loop(w->mlx);
}
