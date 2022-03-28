/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:50:05 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/28 17:23:54 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_map(t_data img)
{
	int		img_width;
	int		img_height;
	size_t	wid;
	size_t	hei;

	hei = 0;
	while (hei < img.pos.y)
	{
		wid = 0;
		while (wid < img.pos.x)
		{
			if (img.pos.map[hei][wid] == '1')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, WALL, &img_width, &img_height);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, wid * SQUARE, hei * SQUARE);
			}
			else if (img.pos.map[hei][wid] == '0')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, FLOOR, &img_width, &img_height);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, wid * SQUARE, hei * SQUARE);
			}
			else if (img.pos.map[hei][wid] == 'E')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, DOOR, &img_width, &img_height);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, wid * SQUARE, hei * SQUARE);
			}
			else if (img.pos.map[hei][wid] == 'C')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, ITEM, &img_width, &img_height);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, wid * SQUARE, hei * SQUARE);
			}
			else if (img.pos.map[hei][wid] == 'P')
			{
				img.img = mlx_xpm_file_to_image(img.mlx, KNIGHT, &img_width, &img_height);
				mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, wid * SQUARE, hei * SQUARE);
			}
			wid++;
		}
		hei++;
	}
}