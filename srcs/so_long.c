/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:26 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/20 14:31:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	int		map_fd;
	t_map	pos;
	// t_data	vars;

	// vars.mlx = mlx_init();
	// vars.mlx_win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "so_long");
	// vars.img = mlx_new_image(vars.mlx_win, WIDTH, HEIGHT);
	// vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	// ft_draw_square(vars, 0xFFFFFF);
	// mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 0, 0);


	/* Recup la map et la check */

	map_fd = open("map.ber", O_RDONLY);
	ft_get_map(map_fd, &pos);
	pos.x = ft_strlen(pos.map[0]);
	if (!ft_check_map(&pos))
		ft_err("Invalid map");
	int i = -1;
	while (++i < pos.y)
		printf("%s\t| %d\n", pos.map[i], i);
	ft_free_map(&pos);
	// mlx_key_hook(vars.mlx_win, ft_key_hook, &vars);
	// mlx_loop(vars.mlx);
	return (0);
}
