/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:26 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/27 16:12:08 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	int		map_fd;
	t_map	pos;
	t_data	vars;
	t_char	chara;

	vars.mlx = mlx_init();
	map_fd = open("map.ber", O_RDONLY);
	ft_get_map(map_fd, &pos);
	pos.x = ft_strlen(pos.map[0]);
	if (!ft_check_map(&pos, &chara))
		ft_err("Invalid map");
	vars.mlx_win = mlx_new_window(vars.mlx, pos.x * SQUARE, pos.y * SQUARE, "so_long");
	vars.img = mlx_new_image(vars.mlx_win, pos.x * SQUARE, pos.y * SQUARE);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	ft_draw_map(vars, &pos);
	mlx_key_hook(vars.mlx_win, ft_key_hook, &vars);
	mlx_loop(vars.mlx);
	ft_free_map(&pos);
	exit(EXIT_SUCCESS);
}
