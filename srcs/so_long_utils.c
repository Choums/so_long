/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:29 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/24 18:50:22 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_draw_square(t_data img, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x++ <= 100)
		ft_mlx_pixel_put(&img, x, 0, color);
	while (y++ <= 100)
		ft_mlx_pixel_put(&img, x, y, color);
	while (x--)
		ft_mlx_pixel_put(&img, x, y, color);
	while (y--)
		ft_mlx_pixel_put(&img, 0, y, color);
}

int	ft_key_hook(int keycode, t_data *vars)
{
	if (keycode == 53)
		ft_close(keycode, vars);
	// if (keycode == 13)
	// 	ft_advance();
	// else if (keycode == 0)
	// 	ft_left();
	// else if (keycode == 1)
	// 	ft_bot();
	// else if (keycode == 2)
	// 	ft_right();
	return (0);
}

int	ft_close(int keycode, t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	return (0);
}

void	ft_err(char *msg)
{
	ft_putendl_fd(ft_strjoin("Error\n", msg), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
