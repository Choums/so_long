/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:29 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/26 15:16:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_hook(int keycode, t_data vars, t_map *map, t_char *chara)
{
	if (keycode == 53)
		ft_close(keycode, &vars);
	if (keycode == 13)
		ft_up(&map, &chara);
	else if (keycode == 0)
		ft_left(&map, &chara);
	else if (keycode == 1)
		ft_bot(&map, &chara);
	else if (keycode == 2)
		ft_right(&map, &chara);
	ft_draw_map(vars, &map);
	return (0);
}

int	ft_close(int keycode, t_data *vars)
{
	return (mlx_destroy_window(vars->mlx, vars->mlx_win));
}

void	ft_err(char *msg)
{
	ft_putendl_fd(ft_strjoin("Error\n", msg), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
