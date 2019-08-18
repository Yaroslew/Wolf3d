/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:16:59 by tjuana            #+#    #+#             */
/*   Updated: 2019/08/18 14:21:09 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	mlx_win_init(t_wolf3d *t)
{
	char	*title;

	title = ft_strjoin("Wolf3d : ", t->map_name);
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, WINX, WINY, title);
	ft_strdel(&title);
}

int		main(int ac, char **av)
{
	t_wolf3d *t;

	if (ac != 2)
	{
		ft_printf(USAGE);
		return (0);
	}
	if (!(t = (t_wolf3d *)malloc(sizeof(t_wolf3d))))
		return (0);
	mlx_win_init(t);
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
}
