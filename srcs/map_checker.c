/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:20:11 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/17 15:06:13 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_get_map(int map_fd, t_map *pos)
{
	char	*line;
	char	*map;

	map = "\0";
	line = "\0";
	pos->y = 1;
	line = get_next_line(map_fd);
	map = ft_join(map, line);
	while (line)
	{
		line = get_next_line(map_fd);
		if (!line)
			break;
		map = ft_join(map, line);
		pos->y++;
	}
	pos->map = ft_split(map, '\n');
	free(map);
	free(line);
}

int	ft_check_map(t_map *pos)
{
	size_t	y;
	size_t	x;
	int		E;
	int		P;

	pos->cons = 0;
	if (pos->x <= pos->y)
		return (0);
	y = 0;
	E = 0;
	P = 0;
	while (y <= pos->y)
	{
		x = -1;
		while (++x <= pos->x - 1 && (y == 0 || y == pos->y - 1)) // Check la 1er et derniere ligne, que des 1
			if (pos->map[y][x] != '1')
				return (0);
		x = -1;
		while (++x <= pos->x && (y > 0 && y < pos->y - 1)) // Entre la 1ere et derniere ligne
		{
			if (pos->map[y][0] != '1' || pos->map[y][pos->x - 1] != '1') // Check bordure
				return (0);
			if (pos->map[y][x] == 'E')
				E++;
			if (pos->map[y][x] == 'C')
				pos->cons++;
			if (pos->map[y][x] == 'P')
				P++;
		}
		y++;
	}
	if (E != 1 || P != 1)
		return (0);
	return (1);
}
