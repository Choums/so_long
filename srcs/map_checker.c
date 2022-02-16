/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:20:11 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/16 18:28:50 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check(int map_fd)
{
	char	*line;

	while (line)
	{
		line = get_next_line(map_fd);
		if (!ft_check_wall(line))
			ft_err("Invalid map");
		if (!ft_check_obj(line))
			ft_err("Invalid map");
		if (!ft_check_size(line))
			ft_err("Invalid map");
	}
	return (1);
}

int	ft_check_wall(char *line)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(line);
	while (i < size)
	{
		if (line[i] != 1 || line[i])
		i++;
	}
	return (1);
}
