/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:45:29 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/26 17:48:14 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	put_anim_piece(t_data *game, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = game->mlx;
	win = game->win;
	put_floor(game, x, y);
	if (game->anim_piece >= 30 && game->anim_piece <= 40)
		mlx_put_image_to_window(mlx, win, 
			game->img_adr.piece_1, x * 64, y * 64);
	if (game->anim_piece >= 20 && game->anim_piece < 30)
		mlx_put_image_to_window(mlx, win, 
			game->img_adr.piece_2, x * 64, y * 64);
	if (game->anim_piece >= 10 && game->anim_piece < 20)
		mlx_put_image_to_window(mlx, win, 
			game->img_adr.piece_3, x * 64, y * 64);
	if (game->anim_piece >= 0 && game->anim_piece < 10)
		mlx_put_image_to_window(mlx, win, 
			game->img_adr.piece_4, x * 64, y * 64);
	return (1);
}

int	put_anim_exit(t_data *game, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = game->mlx;
	win = game->win;
	put_floor(game, x, y);
	if (game->anim_piece >= 30 && game->anim_piece <= 40)
		mlx_put_image_to_window(mlx, win, game->img_adr.exit_1, x * 64, y * 64);
	if (game->anim_piece >= 20 && game->anim_piece < 30)
		mlx_put_image_to_window(mlx, win, game->img_adr.exit_2, x * 64, y * 64);
	if (game->anim_piece >= 10 && game->anim_piece < 20)
		mlx_put_image_to_window(mlx, win, game->img_adr.exit_3, x * 64, y * 64);
	if (game->anim_piece >= 0 && game->anim_piece < 10)
		mlx_put_image_to_window(mlx, win, game->img_adr.exit_4, x * 64, y * 64);
	return (1);
}

int	put_anim_wall(t_data *game, int x, int y)
{
	void	*mlx;
	void	*win;
	char	*str;

	mlx = game->mlx;
	win = game->win;
	str = ft_strjoin_frees2("Moves : ", ft_itoa(game->moves));
	if (game->anim_piece >= 20 && game->anim_piece <= 25)
	{
		mlx_put_image_to_window(mlx, win, game->img_adr.wall, x * 64, y * 64);
		mlx_string_put(game->mlx, game->win, 10, 32, 000, str);
	}
	if (game->anim_piece >= 0 && game->anim_piece < 5)
	{
		mlx_put_image_to_window(mlx, win, game->img_adr.wall_2, x * 64, y * 64);
		mlx_string_put(game->mlx, game->win, 10, 32, 000, str);
	}
	free(str);
	str = NULL;
	return (1);
}

static int	ft_loop(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < game->x)
		{
			if (game->map[y][x] == 'C')
				put_anim_piece(game, x, y);
			if (game->map[y][x] == '1')
				put_anim_wall(game, x, y);
			if (game->map[y][x] == 'E' && game->nbr_piece == game->piece)
				put_anim_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

int	anim(t_data *game)
{
	ft_loop(game);
	if (game->anim_piece == 40)
		game->anim_piece = 0;
	game->anim_piece++;
	return (1);
}
