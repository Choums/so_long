/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:20:11 by chaidel           #+#    #+#             */
/*   Updated: 2022/04/01 11:15:13 by chaidel          ###   ########.fr       */
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
			break ;
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
	int		ex;
	int		pl;

	vars->pos.cons = 0;
	if (vars->pos.x <= vars->pos.y)
		return (0);
	y = 0;
	ex = 0;
	pl = 0;
	while (y <= vars->pos.y)
	{
		x = -1;
		while (++x <= vars->pos.x - 1 && (y == 0 || y == vars->pos.y - 1))
			if (vars->pos.map[y][x] != '1')
				return (0);
		if (!ft_check_mapi(vars, y, &ex, &pl) || !ft_lim(vars, y))
			return (0);
		y++;
	}
	if (ex != 1 || pl != 1 || !vars->pos.cons)
		return (0);
	return (1);
}

int	ft_check_mapi(t_data *vars, size_t y, int *ex, int *pl)
{
	size_t	x;

	x = -1;
	while (++x <= vars->pos.x - 1 && (y > 0 && y < vars->pos.y - 1))
	{
		if (vars->pos.map[y][0] != '1'
			|| vars->pos.map[y][vars->pos.x - 1] != '1')
			return (0);
		if (vars->pos.map[y][x] == 'E')
			(*ex)++;
		if (vars->pos.map[y][x] == 'C')
			vars->pos.cons++;
		if (vars->pos.map[y][x] == 'P')
		{
			ft_init_char(x, y, vars);
			(*pl)++;
		}
	}
	return (1);
}

int	ft_lim(t_data *vars, size_t y)
{
	size_t	len;

	if (y == vars->pos.y)
		return (1);
	len = ft_strlen(vars->pos.map[y]);
	if (y < vars->pos.y - 1 && len != ft_strlen(vars->pos.map[y + 1]))
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
