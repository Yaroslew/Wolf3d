/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:44:46 by tjuana            #+#    #+#             */
/*   Updated: 2019/08/18 16:40:35 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_map(char *buff, t_wolf3d *w)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	w->len_line = ft_line_len(buff);
	w->nb_lines = ft_count_lines(buff);
	while (buff[i] && buff[i] != '\0')
	{
		if ((buff[i] < 48 || buff[i] > 57) && buff[i] != ' ' && buff[i] != '\n')
			return (0);
		len++;
		if (buff[i] == '\n')
		{
			if (len - 1 != w->len_line)
				return (0);
			len = 0;
		}
		i++;
	}
	return (1);
}

int		second_read(t_wolf3d *w, char **av)
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	*str;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		j = -1;
		k = 0;
		if (!(w->map[i] = (int *)malloc(sizeof(int) * w->len_line)))
			return (0);
		while (++j < w->len_line)
		{
			if (str[k] == ' ')
				k++;
			w->map[i][j] = ft_atoi(&str[k]);
			k++;
		}
		i++;
		free(str);
	}
	return (1);
}

int		check_side(t_wolf3d *w)
{
	int i;
	
	i = 0;
	while(i < w->len_line)
	{
		if (w->map[0][i] == 0)
			return (0);
		if (w->map[w->nb_lines - 1][i] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < w->len_line)
	{
		if (w->map[i][0] == 0)
			return (0);
		if (w->map[i][w->len_line - 1] == 0)
			return (0);
		i++;
	}
	if (w->map[3][3] != 0)
		return (0);
	return (1);
}

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
	if (!(check_map(buff, w)))
	{
		ft_putstr("Map error\n");
		return (0);
	}
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		if (buff[i] == ' ')
			w->len_line--;
		i++;
	}
	ft_strdel(&buff);
	w->map_name = av[1];
	close(fd);
	if (!(w->map = (int **)malloc(sizeof(int *) * w->nb_lines))
			|| !(second_read(w, av)))
		return (0);
	if (!check_side(w))
	{
		ft_putstr("Map error\n");
		return (0);
	}
    return (1);
}
