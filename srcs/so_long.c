/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:26 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/09 16:09:38 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_render(int keycode, t_vars *var)
{
	printf("%d\n", keycode);
	return (0);
}


int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 640, 480, "so_long");
	img.img = mlx_new_image(vars.mlx_win, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_draw_square(img, 0xFFFFFF);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 320, 240);
	mlx_key_hook(vars.mlx_win, ft_key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
