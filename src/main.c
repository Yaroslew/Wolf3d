/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:16:59 by tjuana            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/18 16:16:57 by tjuana           ###   ########.fr       */
=======
/*   Updated: 2019/08/18 14:52:57 by tjuana           ###   ########.fr       */
>>>>>>> 55154a7773987e36a2eb7e5889c94adf32936d75
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
<<<<<<< HEAD

=======
	
>>>>>>> 55154a7773987e36a2eb7e5889c94adf32936d75
	if (ac != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	if (!(w = (t_wolf3d *)malloc(sizeof(t_wolf3d))))
<<<<<<< HEAD
		return (0);
	if (!(read_map(w, av)))
		return (0);
=======
		return (0);
	if (!(read_map(w, av)))
		return (0);
>>>>>>> 55154a7773987e36a2eb7e5889c94adf32936d75
	mlx_win_init(w);
	mlx_hook(w->win, 17, 0L, ft_close, w);
	//mlx_loop_hook(w->mlx, move, w);
	mlx_loop(w->mlx);
}
