/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_verif_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:25:20 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/26 17:42:52 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_dim(int lines, int rows)
{
	if (lines > 20 || rows > 40)
		return (1);
	return (0);
}

static int	verif_form(t_data *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->y)
	{
		x = ft_so_long_len(game->map[y]);
		if (x != game->x)
			return (1);
	}
	return (0);
}

static int	verif_wall(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	x = -1;
	while (++x < game->x)
		if (game->map[y][x] != '1')
			return (1);
	x -= 1;
	y = -1;
	while (++y < game->y)
		if (game->map[y][x] != '1')
			return (1);
	y -= 1;
	x += 1;
	while (--x > -1)
		if (game->map[y][x] != '1')
			return (1);
	x += 1;
	y += 1;
	while (--y > -1)
		if (game->map[y][x] != '1')
			return (1);
	return (0);
}

static int	verif_elem(t_data *game)
{
	int	row;
	int	line;
	int	checker[3];

	line = -1;
	checker[0] = 0;
	checker[1] = 0;
	checker[2] = 0;
	while (++line < game->y)
	{
		row = -1;
		while (++row < game->x)
		{
			if (game->map[line][row] == 'P')
				checker[0] += 1;
			else if (game->map[line][row] == 'C')
				checker[1]++;
			else if (game->map[line][row] == 'E')
				checker[2] += 1;
		}
	}
	if (checker[0] != 1 || checker[1] < 1 || checker[2] != 1)
		return (1);
	game->nbr_piece = checker[1];
	return (0);
}

int	verif_map(t_data *game)
{
	if (verif_elem(game) || verif_wall(game) || verif_form(game))
		return (ft_error(1)); 
	return (0);
}
