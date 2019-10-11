/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:25:16 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/11 15:09:36 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	free_this(char **matrix, int y)
{
	int i;

	i = 0;
	while (i < y)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static void	check_first_and_last(char **matrix, t_pnti tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (tmp.y < 4 || tmp.x < 4)
		mess_err(-1);
	if (tmp.x != tmp.y)
		mess_err(4);
	while (j < tmp.x)
	{
		if (matrix[0][j] != 'x' || matrix[tmp.y - 1][j] != 'x')
			mess_err(3);
		j++;
	}
	while (i < tmp.y)
	{
		if (matrix[i][0] != 'x' || matrix[i][tmp.x - 1] != 'x')
			mess_err(3);
		i++;
	}
}

static void	validate_this(char **matrix, t_pnti tmp)
{
	int z;
	int i;
	int j;

	z = 0;
	i = 0;
	j = 0;
	while (i < tmp.y)
	{
		while (j < tmp.x)
		{
			if (matrix[i][j] != 'x' && matrix[i][j] != '0'
					&& matrix[i][j] != 'z')
				mess_err(-1);
			if (matrix[i][j] == 'z')
				z += 1;
			j++;
		}
		i++;
		j = 0;
	}
	if (z != 1)
		mess_err(5);
	check_first_and_last(matrix, tmp);
}

void		check_map(char *str, t_base *base)
{
	t_pnti	tmp;
	int		fd;
	char	*line;
	char	**matrix;

	tmp.y = 0;
	tmp.x = 0;
	if (!(matrix = (char **)malloc(sizeof(char *) * 1000)))
		mess_err(2);
	if (!(fd = open(str, O_RDONLY)))
		mess_err(2);
	while (get_next_line(fd, &line) == 1)
	{
		matrix[tmp.y] = ft_strdup(line);
		if (tmp.y == 0)
			tmp.x = ft_strlen(line);
		else if (tmp.x != ft_strlen(line))
			mess_err(-1);
		free(line);
		tmp.y++;
	}
	validate_this(matrix, tmp);
	free_this(matrix, tmp.y);
	base->map_s.x = tmp.x;
	base->map_s.y = tmp.y;
}
