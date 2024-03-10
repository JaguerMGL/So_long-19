/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:03:45 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/25 11:55:47 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_exit(t_data *game, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = game->mlx;
	win = game->win;
	mlx_put_image_to_window(mlx, win, game->img_adr.exit_1, 64 * x, 64 * y);
}

void	put_floor(t_data *game, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = game->mlx;
	win = game->win;
	mlx_put_image_to_window(mlx, win, game->img_adr.floor, 64 * x, 64 * y);
}

void	put_player(t_data *game, int x, int y, int pos)
{
	void	*mlx;
	void	*win;

	mlx = game->mlx;
	win = game->win;
	if (pos == 0)
		mlx_put_image_to_window(mlx, win, 
			game->img_adr.player_face, 64 * x, 64 * y);
	if (pos == 1)
		mlx_put_image_to_window(mlx, win, 
			game->img_adr.player_back, 64 * x, 64 * y);
	if (pos == 2)
		mlx_put_image_to_window(mlx, win, 
			game->img_adr.player_r, 64 * x, 64 * y);
	if (pos == 3)
		mlx_put_image_to_window(mlx, win, 
			game->img_adr.player_l, 64 * x, 64 * y);
	game->player_x = x;
	game->player_y = y;
}

void	init_display(void *m, void *w, t_data *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			put_floor(game, x, y);
			if (map[y][x] == '1')
				mlx_put_image_to_window(m, w, 
					game->img_adr.wall, 64 * x, 64 * y);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(m, w, 
					game->img_adr.piece_1, 64 * x, 64 * y);
			else if (map[y][x] == 'P')
				put_player(game, x, y, 0);
			x++;
		}
		y++;
	}
}
