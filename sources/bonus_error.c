/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:39:15 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/26 14:49:47 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(int i)
{
	if (i == 1)
		write(2, "Error\nINVALID_MAP\n", 18);
	exit (1);
}

void	free_map(char **map, char **map2)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
	}
	i = 0;
	if (map2)
	{
		while (map2[i])
		{
			free(map2[i]);
			map2[i] = NULL;
			i++;
		}
		free(map2);
	}
}

void	free_map_2(char **map, char **map2)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
	}
	i = 0;
	if (map2)
	{
		while (map2[i])
		{
			free(map2[i]);
			map2[i] = NULL;
			i++;
		}
		free(map2);
	}
	ft_error(1);
}

void	ft_path_error(char **map, char **map2)
{
	free_map(map, map2);
	write(2, "Error\nInvalide path\n", 20);
	exit(1);
}

void	ft_destroy(t_data *game)
{
	free_map(game->map, game->check_path_map);
	mlx_destroy_window(game->mlx, game->win);
	destroy_image(game);
	exit(1);
}
