/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:31 by chaidel           #+#    #+#             */
/*   Updated: 2022/05/21 17:04:19 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define SQUARE 64

# define WALL "./set/wall_2.xpm"
# define FLOOR "./set/floor_10.xpm"
# define DOOR "./set/door_closed.xpm"
# define ITEM "./set/bag_coins.xpm"
# define KNIGHT "./set/knight.xpm"

typedef struct s_pos {
	size_t	x;
	size_t	y;
}	t_pos;

typedef struct s_char {
	t_pos	pos;
	int		item;
	int		mv;
}	t_char;

typedef struct s_map {
	size_t	x;
	size_t	y;
	int		cons;
	char	**map;
}	t_map;

typedef struct s_img {
	void	*wall;
	void	*floor;
	void	*door;
	void	*item;
	void	*knight;
}	t_img;

typedef struct s_data {
	t_img	img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	t_map	pos;
	t_char	chara;
}	t_data;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_put_image(t_data *img, size_t hei, size_t wid);
void	ft_draw_map(t_data *img);
int		ft_key_hook(int keycode, t_data *vars);
void	ft_print(t_data *vars);
int		ft_close(t_data *var);

void	ft_err(char *msg);
void	ft_xpm_err(t_data *vars);

void	ft_get_map(int map_fd, t_data *vars);
int		ft_check_nl(t_data *vars);
int		ft_check_map(t_data *vars);
int		ft_check_in(t_data *vars, size_t y);
int		ft_check_mapi(t_data *vars, size_t y, int *ex, int *pl);
int		ft_lim(t_data *vars, size_t y);
void	ft_free_map(t_data *vars);

void	ft_init_char(size_t x, size_t y, t_data *vars);
void	ft_init_img(t_data *img);

void	ft_up(t_data *vars);
void	ft_bot(t_data *vars);
void	ft_left(t_data *vars);
void	ft_right(t_data *vars);

#endif
