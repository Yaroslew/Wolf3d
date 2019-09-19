/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:40:39 by tjuana            #+#    #+#             */
/*   Updated: 2019/09/19 14:46:32 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	help_text(t_wolf3d *t)
{
	mlx_string_put(t->mlx, t->win, 10, 10,
			0x8b, "W A S D or the arrow keys to move.");
	mlx_string_put(t->mlx, t->win, 10, 30, 0x8b, "Press SHIFT to sprint.");
	mlx_string_put(t->mlx, t->win, 10, 50,
			0x8b, "DEL to reset the level.");
	mlx_string_put(t->mlx, t->win, 10, 70,
			0x8b, "T textures.");
	mlx_string_put(t->mlx, t->win, 10, 90,
			0x8b, "H help.");
	mlx_string_put(t->mlx, t->win, 10, 110,
			0x8b, "ESC to quit.");
}
