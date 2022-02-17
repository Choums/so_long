/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:26 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/17 13:47:27 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	int		map_fd;
	t_map	*pos;
	// t_data	vars;

	// vars.mlx = mlx_init();
	// vars.mlx_win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "so_long");
	// vars.img = mlx_new_image(vars.mlx_win, WIDTH, HEIGHT);
	// vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	// ft_draw_square(vars, 0xFFFFFF);
	// mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 0, 0);

	// mlx_key_hook(vars.mlx_win, ft_key_hook, &vars);
	// mlx_loop(vars.mlx);

	/* Recup la map et la check */

	map_fd = open("map.ber", O_RDONLY);
	ft_get_map(map_fd, pos);
	pos->x = ft_strlen(pos->map[0]);
	// printf("fst: %c\nlst: %c\n", pos->map[1][0], pos->map[1][pos->x - 1]);
	if (!ft_check_wall(pos))
		ft_err("Invalid map");
	return (0);
}
