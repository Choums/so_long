/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:25:22 by root              #+#    #+#             */
/*   Updated: 2022/03/30 18:43:30 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_char(size_t x, size_t y, t_data *vars)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	vars->chara.item = 0;
	vars->chara.mv = 0;
	vars->chara.pos = pos;
}

void	ft_up(t_data *vars)
{
	if (vars->pos.map[vars->chara.pos.y - 1][vars->chara.pos.x] == '0')
	{
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x] = '0';
		vars->pos.map[vars->chara.pos.y - 1][vars->chara.pos.x] = 'P';
		vars->chara.pos.y--;
		ft_print(vars);
	}
	else if (vars->pos.map[vars->chara.pos.y - 1][vars->chara.pos.x] == '1')
		return ;
	else if (vars->pos.map[vars->chara.pos.y - 1][vars->chara.pos.x] == 'C')
	{
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x] = '0';
		vars->chara.item++;
		vars->pos.map[vars->chara.pos.y - 1][vars->chara.pos.x] = 'P';
		vars->chara.pos.y--;
		ft_print(vars);
	}
	else if (vars->pos.map[vars->chara.pos.y - 1][vars->chara.pos.x] == 'E')
	{
		if (vars->chara.item == vars->pos.cons)
		{
			ft_print(vars);
			ft_close(vars);
		}
	}
}

void	ft_bot(t_data *vars)
{	
	if (vars->pos.map[vars->chara.pos.y + 1][vars->chara.pos.x] == '0')
	{
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x] = '0';
		vars->pos.map[vars->chara.pos.y + 1][vars->chara.pos.x] = 'P';
		vars->chara.pos.y++;
		ft_print(vars);
	}
	else if (vars->pos.map[vars->chara.pos.y + 1][vars->chara.pos.x] == '1')
		return ;
	else if (vars->pos.map[vars->chara.pos.y + 1][vars->chara.pos.x] == 'C')
	{
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x] = '0';
		vars->chara.item++;
		vars->pos.map[vars->chara.pos.y + 1][vars->chara.pos.x] = 'P';
		vars->chara.pos.y++;
		ft_print(vars);
	}
	else if (vars->pos.map[vars->chara.pos.y + 1][vars->chara.pos.x] == 'E')
	{
		if (vars->chara.item == vars->pos.cons)
		{
			ft_print(vars);
			ft_close(vars);
		}
	}
}

void	ft_left(t_data *vars)
{
	if (vars->pos.map[vars->chara.pos.y][vars->chara.pos.x - 1] == '0')
	{
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x] = '0';
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x - 1] = 'P';
		vars->chara.pos.x--;
		ft_print(vars);
	}
	else if (vars->pos.map[vars->chara.pos.y][vars->chara.pos.x - 1] == '1')
		return ;
	else if (vars->pos.map[vars->chara.pos.y][vars->chara.pos.x - 1] == 'C')
	{
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x] = '0';
		vars->chara.item++;
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x - 1] = 'P';
		vars->chara.pos.x--;
		ft_print(vars);
	}
	else if (vars->pos.map[vars->chara.pos.y][vars->chara.pos.x - 1] == 'E')
	{
		if (vars->chara.item == vars->pos.cons)
		{
			ft_print(vars);
			ft_close(vars);
		}
	}
}

void	ft_right(t_data *vars)
{
	if (vars->pos.map[vars->chara.pos.y][vars->chara.pos.x + 1] == '0')
	{
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x] = '0';
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x + 1] = 'P';
		vars->chara.pos.x++;
		ft_print(vars);
	}
	else if (vars->pos.map[vars->chara.pos.y][vars->chara.pos.x + 1] == '1')
		return ;
	else if (vars->pos.map[vars->chara.pos.y][vars->chara.pos.x + 1] == 'C')
	{
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x] = '0';
		vars->chara.item++;
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x + 1] = 'P';
		vars->chara.pos.x++;
		ft_print(vars);
	}
	else if (vars->pos.map[vars->chara.pos.y][vars->chara.pos.x + 1] == 'E')
	{
		if (vars->chara.item == vars->pos.cons)
		{
			ft_print(vars);
			ft_close(vars);
		}
	}
}
