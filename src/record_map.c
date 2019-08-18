/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 15:02:26 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/08/18 16:43:07 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	record_map(char *str, t_base *base)
{
	int fd;
	char *line;
	int q;
	int r;
	int y;

	q = 0;
	r = 0;
	y = 0;
	if (!(base->map = malloc(sizeof(t_map) * (base->w_map * base->h_map))))
		mess_err(0);
	if(!(fd = open(str, O_RDONLY)))
		mess_err(2);
	while (get_next_line(fd, &line))
	{
		while (line[q])
		{
			base->map[r].x = q;
			base->map[r].y = y;
			base->map[r].data = line[q];
			q++;
			r++;
		}
		q = 0;
		y++;
	}
}