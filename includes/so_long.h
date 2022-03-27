/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:31 by chaidel           #+#    #+#             */
/*   Updated: 2022/03/27 17:20:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../srcs/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../miniLibX_X11/mlx.h"

# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

# define WIDTH	1920
# define HEIGHT	1080
# define SQUARE 64

# define WALL "./set/wall_2.xpm"
# define FLOOR "./set/floor_1.xpm"
# define DOOR "./set/door_fullyopen.xpm"
# define ITEM "./set/bag_coins.xpm"
# define KNIGHT "./set/knight.xpm"

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

typedef struct s_pos {
	size_t	x;
	size_t	y;
}	t_pos;

typedef struct s_char {
	t_pos	*pos;
	int		item;
}	t_char;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_draw_map(t_data img, t_map *pos);
int		ft_key_hook(int keycode, t_data vars, t_map *map, t_char *chara);
int		ft_close(t_data *var);

void	ft_err(char *msg);

void	ft_get_map(int map_fd, t_map *pos);
int		ft_check_map(t_map *pos, t_char *chara);
void	ft_free_map(t_map *pos);

void	ft_init_char(size_t x, size_t y, t_char *chara);

void	ft_up(t_map *pos, t_char *chara);
void	ft_bot(t_map *pos, t_char *chara);
void	ft_left(t_map *pos, t_char *chara);
void	ft_right(t_map *pos, t_char *chara);

#endif
