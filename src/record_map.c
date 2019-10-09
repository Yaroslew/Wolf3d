/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 15:02:26 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/09 22:14:45 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		line_record(t_base *base, int fd)
{
	char	*line;
	int		q;
	int		r;
	int		y;

	q = 0;
	r = 0;
	y = 0;
	while (get_next_line(fd, &line))
	{
		while (line[q])
		{
			if (line[q] == 'z')
				init_hero(base, q, y);
			base->map[r].x = q;
			base->map[r].y = y;
			base->map[r].data = line[q];
			q++;
			r++;
		}
		q = 0;
		y++;
		free(line);
	}
}

void			record_map(char *str, t_base *base)
{
	int		fd;

	if (!(base->map = malloc(sizeof(t_map) * (base->map_s.x * base->map_s.y))))
		mess_err(0);
	if (!(fd = open(str, O_RDONLY)))
		mess_err(2);
	line_record(base, fd);
}
