/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:16:59 by tjuana            #+#    #+#             */
/*   Updated: 2019/08/18 16:45:14 by tjuana           ###   ########.fr       */
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
	mlx_hook(w->win, 17, 0L, ft_close, w);
	//mlx_loop_hook(w->mlx, move, w);
	mlx_loop(w->mlx);
}
