/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:57:52 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/26 15:25:39 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	escape(int keycode, t_data *game)
{
	keycode = 0;
	free_map(game->map, game->check_path_map);
	mlx_destroy_window(game->mlx, game->win);
	destroy_image(game);
	exit(0);
}

int	cross_escape(t_data *data)
{
	escape(0, data);
	return (1);
}

void	move_danger(t_data *game)
{
	ft_printf("YOU DIED");
	escape(0, game);
}

void	move(t_data *game, int x, int y, int pos)
{
	if (game->map[y][x] == '1')
		return ;
	game->moves++;
	if (game->map[y][x] == 'C' || game->map[y][x] == '0')
	{
		if (game->map[y][x] == 'C')
			game->piece++;
		game->map[y][x] = '0';
		game->map[game->player_y][game->player_x] = '0';
		put_floor(game, game->player_x, game->player_y);
		put_floor(game, x, y);
		put_player(game, x, y, pos);
		if (game->piece == game->nbr_piece)
			put_exit(game, game->exit_x, game->exit_y);
	}
	if (game->map[y][x] == 'E')
	{
		put_floor(game, game->player_x, game->player_y);
		put_player(game, x, y, pos);
		if (game->piece == game->nbr_piece)
			cross_escape(game);
	}
	if (game->map[y][x] == 'R')
		move_danger(game);
}

int	key_press(int keycode, t_data *game)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		move(game, game->player_x, game->player_y - 1, 1);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		move(game, game->player_x, game->player_y + 1, 0);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		move(game, game->player_x - 1, game->player_y, 3);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(game, game->player_x + 1, game->player_y, 2);
	if (keycode == KEY_ESCAPE || game->moves > INT_MAX - 1)
		cross_escape(game);
	return (0);
}
