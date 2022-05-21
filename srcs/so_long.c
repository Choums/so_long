/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:28:26 by chaidel           #+#    #+#             */
/*   Updated: 2022/05/21 17:00:22 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_nl(t_data *vars)
{
	size_t	i;

	i = 0;
	while (vars->pos.map[i])
		i++;
	if (i != vars->pos.y)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int		map_fd;
	t_data	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		ft_err("mlx");
	if (ac != 2 || !av[1] || !ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		ft_err("Invalid Argument");
	map_fd = open(av[1], O_RDONLY);
	if (!map_fd)
		ft_err("Open");
	ft_get_map(map_fd, &vars);
	vars.pos.x = ft_strlen(vars.pos.map[0]);
	if (!ft_check_map(&vars))
		ft_err("Invalid map");
	vars.win = mlx_new_window(vars.mlx, vars.pos.x * SQUARE,
			vars.pos.y * SQUARE, "so_long");
	ft_init_img(&vars);
	ft_draw_map(&vars);
	mlx_hook(vars.win, 17, 1L << 0, ft_close, &vars);
	mlx_key_hook(vars.win, ft_key_hook, &vars);
	mlx_loop(vars.mlx);
}
