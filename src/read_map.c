/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:44:46 by tjuana            #+#    #+#             */
/*   Updated: 2019/08/18 15:11:10 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		read_map(t_wolf3d *w, char **av)
{
    int		fd;
	char	*buff;
	int		i;

	i = 0;
	buff = ft_strnew(65536);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || (read(fd, buff, 65536)) < 1)
	{
		ft_putstr("wolf3d: ");
		ft_putstr(av[1]);
		ft_putstr(": No such file\n");
		return (0);
	}
    if (!(w->map = (int **)malloc(sizeof(int *) * w->nb_lines)))
		return (0);
    return (1);
}