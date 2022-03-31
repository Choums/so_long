/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:20:11 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/31 21:11:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_get_map(int map_fd, t_data *vars)
{
	char	*line;
	char	*map;

	line = "\0";
	map = "\0";
	vars->pos.y = 1;
	line = get_next_line(map_fd);
	map = ft_strjoin(map, line);
	while (line)
	{
		free(line);
		line = get_next_line(map_fd);
		if (!line)
			break;
		map = ft_join(map, line);
		vars->pos.y++;
	}
	vars->pos.map = ft_split(map, '\n');
	free(map);
	free(line);
}

int	ft_check_map(t_data *vars)
{
	size_t	y;
	size_t	x;
	int		E;
	int		P;

	vars->pos.cons = 0;
	if (vars->pos.x <= vars->pos.y)
		return (0);
	y = 0;
	E = 0;
	P = 0;
	while (y <= vars->pos.y)
	{
		x = -1;
		while (++x <= vars->pos.x - 1 && (y == 0 || y == vars->pos.y - 1))
			if (vars->pos.map[y][x] != '1')
				return (0);
		if (!ft_check_mapi(vars, y, &E, &P))
			return (0);
		y++;
	}
	if (E != 1 || P != 1 || !vars->pos.cons)
		return (0);
	return (1);
}

int	ft_check_mapi(t_data *vars, size_t y, int *E, int P)
{
	size_t	x;

	x = -1;
	while (++x <= vars->pos.x && (y > 0 && y < vars->pos.y - 1))
	{
		if (vars->pos.map[y][0] != '1' || vars->pos.map[y][vars->pos.x - 1] != '1')
			return (0);
		if (vars->pos.map[y][x] == 'E')
			E++;
		if (vars->pos.map[y][x] == 'C')
			vars->pos.cons++;
		if (vars->pos.map[y][x] == 'P')
		{
			ft_init_char(x, y, vars);
			P++;
		}
	}
	if (x > vars->pos.x)
		return (0);
	return (1);
}

void	ft_free_map(t_data *vars)
{
	size_t	i;

	i = 0;
	while (vars->pos.map[i])
		i++;
	while (i--)
		free(vars->pos.map[i]);
	free(vars->pos.map);
}