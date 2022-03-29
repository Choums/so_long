/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:25:22 by root              #+#    #+#             */
/*   Updated: 2022/03/29 19:50:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

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
	printf("---chara debug up---\n");
	printf("pos x: %zu\npos y: %zu\nitem: %d", vars->chara.pos.x, vars->chara.pos.y, vars->chara.item);
	if (vars->pos.map[vars->chara.pos.y - 1][vars->chara.pos.x] == '0')
	{
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x] = '0';
		vars->pos.map[vars->chara.pos.y - 1][vars->chara.pos.x] = 'P';
		vars->chara.pos.y--;
		ft_print(vars);
		printf("---chara debug up change---\n");
		printf("pos x: %zu\npos y: %zu\nitem: %d", vars->chara.pos.x, vars->chara.pos.y, vars->chara.item);
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
		printf("---chara debug up item---\n");
		printf("pos x: %zu\npos y: %zu\nitem: %d", vars->chara.pos.x, vars->chara.pos.y, vars->chara.item);
	}
	else if (vars->pos.map[vars->chara.pos.y - 1][vars->chara.pos.x] == 'E')
	{
		if (vars->chara.item == vars->pos.cons)
		{
			ft_print(vars);
			ft_close(vars);
		}
		else
			return ;
	}
}

void	ft_bot(t_data *vars)
{	
	printf("---chara debug bot---\n");
	printf("pos x: %zu\npos y: %zu\nitem: %d", vars->chara.pos.x, vars->chara.pos.y, vars->chara.item);
	if (vars->pos.map[vars->chara.pos.y + 1][vars->chara.pos.x] == '0')
	{
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x] = '0';
		vars->pos.map[vars->chara.pos.y + 1][vars->chara.pos.x] = 'P';
		vars->chara.pos.y++;
		ft_print(vars);
		printf("---chara debug bot change---\n");
		printf("pos x: %zu\npos y: %zu\nitem: %d", vars->chara.pos.x, vars->chara.pos.y, vars->chara.item);
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
		printf("---chara debug bot item---\n");
		printf("pos x: %zu\npos y: %zu\nitem: %d", vars->chara.pos.x, vars->chara.pos.y, vars->chara.item);
	}
	else if (vars->pos.map[vars->chara.pos.y + 1][vars->chara.pos.x] == 'E')
	{
		if (vars->chara.item == vars->pos.cons)
		{
			ft_print(vars);
			ft_close(vars);
		}
		else
			return ;
	}
}

void	ft_left(t_data *vars)
{
	printf("---chara debug left---\n");
	printf("pos x: %zu\npos y: %zu\nitem: %d", vars->chara.pos.x, vars->chara.pos.y, vars->chara.item);
	if (vars->pos.map[vars->chara.pos.y][vars->chara.pos.x - 1] == '0')
	{
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x] = '0';
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x - 1] = 'P';
		vars->chara.pos.x--;
		ft_print(vars);
		printf("---chara debug left change---\n");
		printf("pos x: %zu\npos y: %zu\nitem: %d", vars->chara.pos.x, vars->chara.pos.y, vars->chara.item);
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
		printf("---chara debug left item---\n");
		printf("pos x: %zu\npos y: %zu\nitem: %d", vars->chara.pos.x, vars->chara.pos.y, vars->chara.item);
	}
	else if (vars->pos.map[vars->chara.pos.y][vars->chara.pos.x - 1] == 'E')
	{
		if (vars->chara.item == vars->pos.cons)
		{
			ft_print(vars);
			ft_close(vars);
		}
		else
			return ;
	}
}

void	ft_right(t_data *vars)
{
	printf("---chara debug right---\n");
	printf("pos x: %zu\npos y: %zu\nitem: %d", vars->chara.pos.x, vars->chara.pos.y, vars->chara.item);
	if (vars->pos.map[vars->chara.pos.y][vars->chara.pos.x + 1] == '0')
	{
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x] = '0';
		vars->pos.map[vars->chara.pos.y][vars->chara.pos.x + 1] = 'P';
		vars->chara.pos.x++;
		ft_print(vars);
		printf("---chara debug right change---\n");
		printf("pos x: %zu\npos y: %zu\nitem: %d", vars->chara.pos.x, vars->chara.pos.y, vars->chara.item);
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
		printf("---chara debug right item---\n");
		printf("pos x: %zu\npos y: %zu\nitem: %d", vars->chara.pos.x, vars->chara.pos.y, vars->chara.item);
	}
	else if (vars->pos.map[vars->chara.pos.y][vars->chara.pos.x + 1] == 'E')
	{
		if (vars->chara.item == vars->pos.cons)
		{
			ft_print(vars);
			ft_close(vars);
		}
		else
			return ;
	}
}