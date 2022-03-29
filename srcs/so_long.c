/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:26 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/29 14:02:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	int		map_fd;
	t_data	vars;

	vars.mlx = mlx_init();
	map_fd = open("map.ber", O_RDONLY);
	ft_get_map(map_fd, &vars);
	vars.pos.x = ft_strlen(vars.pos.map[0]);
	if (!ft_check_map(&vars))
		ft_err("Invalid map");
	vars.mlx_win = mlx_new_window(vars.mlx, vars.pos.x * SQUARE, vars.pos.y * SQUARE, "so_long");
	vars.img = mlx_new_image(vars.mlx_win, vars.pos.x * SQUARE, vars.pos.y * SQUARE);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	ft_draw_map(vars);
	// printf("---chara debug, before key---\n");
	// printf("pos x: %zu\npos y: %zu\nitem: %d\n", vars.chara.pos.x, vars.chara.pos.y, vars.chara.item);
	mlx_key_hook(vars.mlx_win, ft_key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
