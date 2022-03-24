/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:50:05 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/24 17:43:49 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_map(t_data img, t_map pos)
{
	int	img_width;
	int	img_height;
	int	wid;
	int	hei;

	hei = 0;
	while (hei < pos.y)
	{
		wid = 0;
		while (wid < pos.x)
		{
			if (pos.map[wid][hei] == '1')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, WALL, &img_width, &img_height);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, wid * SQUARE, hei * SQUARE);
			}
			else if (pos.map[wid][hei] == '0' || pos.map[wid][hei] == 'P')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, FLOOR, &img_width, &img_height);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, wid * SQUARE, hei * SQUARE);
			}
			else if (pos.map[wid][hei] == 'E')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, DOOR, &img_width, &img_height);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, wid * SQUARE, hei * SQUARE);
			}
			else if (pos.map[wid][hei] == 'C')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, ITEM, &img_width, &img_height);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, wid * SQUARE, hei * SQUARE);
			}
			wid++;
		}
		hei++;
	}
}