/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:26 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/30 18:34:19 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	int		map_fd;
	t_data	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		ft_err("mlx");
	map_fd = open("map.ber", O_RDONLY);
	if (!map_fd)
		ft_err("Open");
	ft_get_map(map_fd, &vars);
	vars.pos.x = ft_strlen(vars.pos.map[0]);
	if (!ft_check_map(&vars))
		ft_err("Invalid map");
	vars.mlx_win = mlx_new_window(vars.mlx, vars.pos.x * SQUARE,
			vars.pos.y * SQUARE, "so_long");
	ft_draw_map(vars);
	mlx_hook(vars.mlx_win, 17, 1L << 0, ft_close, &vars);
	mlx_key_hook(vars.mlx_win, ft_key_hook, &vars);
	mlx_loop(vars.mlx);
}
