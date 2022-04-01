/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:29 by chaidel           #+#    #+#             */
/*   Updated: 2022/04/01 11:17:48 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_hook(int keycode, t_data *vars)
{
	if (keycode == 53)
		ft_close(vars);
	else if (keycode == 13)
		ft_up(vars);
	else if (keycode == 0)
		ft_left(vars);
	else if (keycode == 1)
		ft_bot(vars);
	else if (keycode == 2)
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
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(EXIT_SUCCESS);
}

void	ft_err(char *msg)
{
	ft_putendl_fd(ft_strjoin("Error\n", msg), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
