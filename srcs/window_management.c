/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:50:05 by chaidel           #+#    #+#             */
/*   Updated: 2022/05/21 16:59:19 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_map(t_data *img)
{
	size_t	wid;
	size_t	hei;

	hei = -1;
	while (++hei < img->pos.y)
	{
		wid = -1;
		while (++wid < img->pos.x)
			ft_put_image(img, hei, wid);
	}
}

void	ft_put_image(t_data *img, size_t hei, size_t wid)
{
	if (img->pos.map[hei][wid] == '1')
		mlx_put_image_to_window(img->mlx, img->win, img->img.wall,
			wid * SQUARE, hei * SQUARE);
	else if (img->pos.map[hei][wid] == '0')
		mlx_put_image_to_window(img->mlx, img->win, img->img.floor,
			wid * SQUARE, hei * SQUARE);
	else if (img->pos.map[hei][wid] == 'E')
		mlx_put_image_to_window(img->mlx, img->win, img->img.door,
			wid * SQUARE, hei * SQUARE);
	else if (img->pos.map[hei][wid] == 'C')
		mlx_put_image_to_window(img->mlx, img->win, img->img.item,
			wid * SQUARE, hei * SQUARE);
	else if (img->pos.map[hei][wid] == 'P')
		mlx_put_image_to_window(img->mlx, img->win, img->img.knight,
			wid * SQUARE, hei * SQUARE);
}

void	ft_init_img(t_data *img)
{
	int		imgw;
	int		imgh;

	img->img.wall = NULL;
	img->img.floor = NULL;
	img->img.door = NULL;
	img->img.item = NULL;
	img->img.knight = NULL;
	img->img.wall = mlx_xpm_file_to_image(img->mlx, WALL, &imgw, &imgh);
	if (img->img.wall == NULL)
		ft_xpm_err(img);
	img->img.floor = mlx_xpm_file_to_image(img->mlx, FLOOR, &imgw, &imgh);
	if (img->img.floor == NULL)
		ft_xpm_err(img);
	img->img.door = mlx_xpm_file_to_image(img->mlx, DOOR, &imgw, &imgh);
	if (img->img.door == NULL)
		ft_xpm_err(img);
	img->img.item = mlx_xpm_file_to_image(img->mlx, ITEM, &imgw, &imgh);
	if (img->img.item == NULL)
		ft_xpm_err(img);
	img->img.knight = mlx_xpm_file_to_image(img->mlx, KNIGHT, &imgw, &imgh);
	if (img->img.knight == NULL)
		ft_xpm_err(img);
}
