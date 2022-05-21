/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:29 by chaidel           #+#    #+#             */
/*   Updated: 2022/05/21 15:02:43 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_hook(int keycode, t_data *vars)
{
	if (keycode == 65307)
		ft_close(vars);
	else if (keycode == 119)
		ft_up(vars);
	else if (keycode == 97)
		ft_left(vars);
	else if (keycode == 115)
		ft_bot(vars);
	else if (keycode == 100)
		ft_right(vars);
	ft_draw_map((*vars));
	return (0);
}

void	ft_print(t_data *vars)
{
	ft_putnbr_fd(vars->chara.mv++, STDIN_FILENO);
	ft_putchar_fd('\n', STDIN_FILENO);
}

int	ft_close(t_data *vars)
{
	ft_free_map(vars);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}

void	ft_err(char *msg)
{
	ft_putendl_fd(ft_strjoin("Error\n", msg), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
