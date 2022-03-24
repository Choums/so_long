/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:26 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/24 19:31:49 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	int		map_fd;
	t_map	pos;
	t_data	vars;
	int		img_width;
	int		img_height;
	vars.mlx = mlx_init();

	/* Recup la map et la check */

	map_fd = open("map.ber", O_RDONLY);
	ft_get_map(map_fd, &pos);
	pos.x = ft_strlen(pos.map[0]);
	if (!ft_check_map(&pos))
		ft_err("Invalid map");
	vars.mlx_win = mlx_new_window(vars.mlx, pos.x * SQUARE, pos.y * SQUARE, "so_long");
	vars.img = mlx_new_image(vars.mlx_win, pos.x * SQUARE, pos.y * SQUARE);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	// ft_mlx_pixel_put(vars.img, 100, 100, 0xFFFFF);
	vars.img = mlx_xpm_file_to_image(vars.mlx, "wall_2.xpm", &img_width, &img_height);
	int wid = 0;
	int	heo = 0;
	while (wid < pos.x)
	{
		mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, wid * SQUARE, 0);
		wid ++;
	}
	ft_free_map(&pos);
	mlx_key_hook(vars.mlx_win, ft_key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
