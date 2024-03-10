/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:35:45 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/25 11:56:39 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	valid_cross(t_data *game, int x, int y)
{
	if (x < 0 || x > game->x - 1)
		return (0);
	if (y < 0 || y > game->y - 1)
		return (0);
	if (game->map[y][x] != '1')
		return (1);
	return (0);
}

static void	mark_map(t_data *game, int x, int y)
{
	if (valid_cross(game, x, y))
	{
		if (game->check_path_map[y][x] == '.')
			return ;
		if (game->check_path_map[y][x] == 'C')
			game->verif_total++;
		game->check_path_map[y][x] = '.';
		mark_map(game, x - 1, y);
		mark_map(game, x + 1, y);
		mark_map(game, x, y - 1);
		mark_map(game, x, y + 1);
	}
	return ;
}

static void	verif_path(t_data *game)
{
	int	x;
	int	y;

	game->verif_total = 0;
	mark_map(game, game->player_x, game->player_y);
	y = -1;
	while (++y < game->y)
	{
		x = -1;
		while (++x < game->x)
		{
			if ((game->map[y][x] == 'C' || game->map[y][x] == 'E')
				&& game->check_path_map[y][x] != '.')
				ft_path_error(game->map, game->check_path_map);
		}
	}
}

static void	check_pos(t_data *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->y)
	{
		x = -1;
		while (++x < game->x)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
			}
			else if (game->map[y][x] == 'E')
			{
				game->exit_y = y;
				game->exit_x = x;
			}
		}
	}
}

void	init_game(t_data *game)
{
	check_pos(game);
	verif_path(game);
	game->img_pxl = 64;
	game->moves = 0;
	game->piece = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->img_pxl * 
			game->x, game->img_pxl * game->y, "so_long");
	get_img_adr(game);
	init_display(game->mlx, game->win, game, game->map);
	mlx_hook(game->win, 17, 0, &cross_escape, game);
	mlx_hook(game->win, 2, 0, &key_press, game);
	mlx_loop(game->mlx);
}
