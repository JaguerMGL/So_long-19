/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:02:10 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/26 17:42:27 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	verif_img_adr(t_data *game)
{
	if (!game->img_adr.floor || !game->img_adr.wall || 
		!game->img_adr.wall_2 || !game->img_adr.player_back)
		ft_destroy(game);
	if (!game->img_adr.player_face || !game->img_adr.player_l || 
		!game->img_adr.player_r || !game->img_adr.piece_1)
		ft_destroy(game);
	if (!game->img_adr.piece_2 || !game->img_adr.piece_3 || 
		!game->img_adr.piece_4 || !game->img_adr.exit_1)
		ft_destroy(game);
	if (!game->img_adr.exit_2 || !game->img_adr.exit_3 || 
		!game->img_adr.exit_4)
		ft_destroy(game);
	if (!game->img_adr.danger_2)
		ft_destroy(game);
}

static void	get_img_adr_2(t_data *game, int height, int width)
{
	game->img_adr.piece_1 = mlx_xpm_file_to_image(game->mlx, 
			"./img/piece_1.xpm", &width, &height);
	game->img_adr.piece_2 = mlx_xpm_file_to_image(game->mlx, 
			"./img/piece_2.xpm", &width, &height);
	game->img_adr.piece_3 = mlx_xpm_file_to_image(game->mlx, 
			"./img/piece_3.xpm", &width, &height);
	game->img_adr.piece_4 = mlx_xpm_file_to_image(game->mlx, 
			"./img/piece_4.xpm", &width, &height);
	game->img_adr.exit_1 = mlx_xpm_file_to_image(game->mlx, 
			"./img/exit_1.xpm", &width, &height);
	game->img_adr.exit_2 = mlx_xpm_file_to_image(game->mlx, 
			"./img/exit_2.xpm", &width, &height);
	game->img_adr.exit_3 = mlx_xpm_file_to_image(game->mlx, 
			"./img/exit_3.xpm", &width, &height);
	game->img_adr.exit_4 = mlx_xpm_file_to_image(game->mlx, 
			"./img/exit_4.xpm", &width, &height);
	verif_img_adr(game);
}

void	get_img_adr(t_data *game)
{
	int	img_height;
	int	img_width;

	game->img_adr.floor = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm", 
			&img_width, &img_height);
	game->img_adr.wall = mlx_xpm_file_to_image(game->mlx, "./img/wall_1.xpm", 
			&img_width, &img_height);
	game->img_adr.wall_2 = mlx_xpm_file_to_image(game->mlx, "./img/wall_2.xpm", 
			&img_width, &img_height);
	game->img_adr.player_face = mlx_xpm_file_to_image(game->mlx, 
			"./img/player_face.xpm", &img_width, &img_height);
	game->img_adr.player_back = mlx_xpm_file_to_image(game->mlx, 
			"./img/player_back.xpm", &img_width, &img_height);
	game->img_adr.player_l = mlx_xpm_file_to_image(game->mlx, 
			"./img/player_l.xpm", &img_width, &img_height);
	game->img_adr.player_r = mlx_xpm_file_to_image(game->mlx, 
			"./img/player_r.xpm", &img_width, &img_height);
	game->img_adr.danger_2 = mlx_xpm_file_to_image(game->mlx, 
			"./img/danger_2.xpm", &img_width, &img_height);
	get_img_adr_2(game, img_height, img_width);
}
