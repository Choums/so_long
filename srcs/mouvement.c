/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:25:22 by root              #+#    #+#             */
/*   Updated: 2022/03/27 16:12:38 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void	ft_init_char(size_t x, size_t y, t_char *chara)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	chara->item = 0;
	chara->pos = &pos;
}

void	ft_up(t_map *pos, t_char *chara)
{
	if (pos->map[chara->pos->y - 1][chara->pos->x] == '0')
	{
		pos->map[chara->pos->y][chara->pos->x] = '0';
		chara->pos->y--;
		pos->map[chara->pos->y - 1][chara->pos->x] = 'P';
	}
	else if (pos->map[chara->pos->y - 1][chara->pos->x] == '1')
		return ;
	else if (pos->map[chara->pos->y - 1][chara->pos->x] == 'C')
	{
		pos->map[chara->pos->y][chara->pos->x] = '0';
		chara->pos->y--;
		chara->item++;
		pos->map[chara->pos->y - 1][chara->pos->x] = 'P';
	}
	else if (pos->map[chara->pos->y - 1][chara->pos->x] == 'E')
	{
		if (chara->item == pos->cons)
			exit(EXIT_FAILURE);
		else
			return ;
	}
}

void	ft_bot(t_map *pos, t_char *chara)
{
	if (pos->map[chara->pos->y + 1][chara->pos->x] == '0')
	{
		printf("move up\n");
		pos->map[chara->pos->y][chara->pos->x] = '0';
		chara->pos->y++;
		pos->map[chara->pos->y + 1][chara->pos->x] = 'P';
	}
	else if (pos->map[chara->pos->y + 1][chara->pos->x] == '1')
		return ;
	else if (pos->map[chara->pos->y + 1][chara->pos->x] == 'C')
	{
		pos->map[chara->pos->y][chara->pos->x] = '0';
		chara->pos->y++;
		chara->item++;
		pos->map[chara->pos->y + 1][chara->pos->x] = 'P';
	}
	else if (pos->map[chara->pos->y + 1][chara->pos->x] == 'E')
	{
		if (chara->item == pos->cons)
			exit(EXIT_FAILURE);
		else
			return ;
	}
}

void	ft_left(t_map *pos, t_char *chara)
{
	if (pos->map[2][10] == '0')
	{
		pos->map[chara->pos->y][chara->pos->x] = '0';
		chara->pos->x--;
		pos->map[chara->pos->y][chara->pos->x - 1] = 'P';
	}
	else if (pos->map[chara->pos->y][chara->pos->x - 1] == '1')
		return ;
	else if (pos->map[chara->pos->y][chara->pos->x - 1] == 'C')
	{
		pos->map[chara->pos->y][chara->pos->x] = '0';
		chara->pos->x--;
		chara->item++;
		pos->map[chara->pos->y][chara->pos->x - 1] = 'P';
	}
	else if (pos->map[chara->pos->y][chara->pos->x - 1] == 'E')
	{
		if (chara->item == pos->cons)
			exit(EXIT_FAILURE);
		else
			return ;
	}
}

void	ft_right(t_map *pos, t_char *chara)
{
	if (pos->map[chara->pos->y][chara->pos->x + 1] == '0')
	{
		pos->map[chara->pos->y][chara->pos->x] = '0';
		chara->pos->x++;
		pos->map[chara->pos->y][chara->pos->x + 1] = 'P';
	}
	else if (pos->map[chara->pos->y][chara->pos->x + 1] == '1')
		return ;
	else if (pos->map[chara->pos->y][chara->pos->x + 1] == 'C')
	{
		pos->map[chara->pos->y][chara->pos->x] = '0';
		chara->pos->x++;
		chara->item++;
		pos->map[chara->pos->y][chara->pos->x + 1] = 'P';
	}
	else if (pos->map[chara->pos->y][chara->pos->x + 1] == 'E')
	{
		if (chara->item == pos->cons)
			exit(EXIT_FAILURE);
		else
			return ;
	}
}