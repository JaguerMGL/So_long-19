/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:40:08 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/26 15:26:22 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	destroy_image_utils(void *mlx, t_data *game)
{
	if (game->img_adr.piece_2)
		mlx_destroy_image(mlx, game->img_adr.piece_2);
	if (game->img_adr.piece_3)
		mlx_destroy_image(mlx, game->img_adr.piece_3);
	if (game->img_adr.piece_4)
		mlx_destroy_image(mlx, game->img_adr.piece_4);
	if (game->img_adr.exit_1)
		mlx_destroy_image(mlx, game->img_adr.exit_1);
	if (game->img_adr.exit_2)
		mlx_destroy_image(mlx, game->img_adr.exit_2);
	if (game->img_adr.exit_3)
		mlx_destroy_image(mlx, game->img_adr.exit_3);
	if (game->img_adr.exit_4)
		mlx_destroy_image(mlx, game->img_adr.exit_4);
	if (game->img_adr.danger_2)
		mlx_destroy_image(mlx, game->img_adr.danger_2);
}

void	destroy_image(t_data *game)
{
	void	*mlx;

	mlx = game->mlx;
	if (game->img_adr.floor)
		mlx_destroy_image(mlx, game->img_adr.floor);
	if (game->img_adr.wall)
		mlx_destroy_image(mlx, game->img_adr.wall);
	if (game->img_adr.wall_2)
		mlx_destroy_image(mlx, game->img_adr.wall_2);
	if (game->img_adr.player_face)
		mlx_destroy_image(mlx, game->img_adr.player_face);
	if (game->img_adr.player_back)
		mlx_destroy_image(mlx, game->img_adr.player_back);
	if (game->img_adr.player_l)
		mlx_destroy_image(mlx, game->img_adr.player_l);
	if (game->img_adr.player_r)
		mlx_destroy_image(mlx, game->img_adr.player_r);
	if (game->img_adr.piece_1)
		mlx_destroy_image(mlx, game->img_adr.piece_1);
	destroy_image_utils(mlx, game);
}
