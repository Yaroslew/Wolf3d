/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:40:39 by tjuana            #+#    #+#             */
/*   Updated: 2019/09/18 17:40:41 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	help_text(t_wolf3d *t)
{
	mlx_string_put(t->mlx, t->win, 10, 10,
			0xEEEEEE, "Press W A S D or the arrow keys to move.");
	mlx_string_put(t->mlx, t->win, 10, 30, 0xEEEEEE, "Press SHIFT to sprint.");
	mlx_string_put(t->mlx, t->win, 10, 50,
			0xEEEEEE, "Press DEL to reset the level.");
	mlx_string_put(t->mlx, t->win, 10, 70,
			0xEEEEEE, "Press T to show or hide textures.");
	mlx_string_put(t->mlx, t->win, 10, 90,
			0xEEEEEE, "Press H to show or hide this help.");
	mlx_string_put(t->mlx, t->win, 10, 110,
			0xEEEEEE, "Press ESC to quit.");
}
