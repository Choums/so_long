/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:31 by chaidel           #+#    #+#             */
/*   Updated: 2022/02/17 14:55:40 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../srcs/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

# define WIDTH	1920
# define HEIGHT	1080

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}	t_data;

typedef struct s_map {
	size_t	x;
	size_t	y;
	int		cons;
	char	**map;
}	t_map;

typedef struct s_char {
	size_t	x;
	size_t	y;
	int		item;
}	t_char;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_draw_square(t_data img, int color);
int		ft_key_hook(int keycode, t_data *vars);
int		ft_close(int keycode, t_data *var);

void	ft_err(char *msg);

void	ft_get_map(int map_fd, t_map *pos);
int		ft_check_map(t_map *pos);

#endif
