/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:10:57 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/25 14:44:27 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	char_verif(t_data *game)
{
	int	rows;
	int	lines;
	int	i;

	lines = 0;
	while (lines < game->y)
	{
		rows = 0;
		while (rows < game->x)
		{
			if (game->map[lines][rows] != '0' && game->map[lines][rows] != '1'
			&& game->map[lines][rows] != 'C' && game->map[lines][rows] != 'P'
			&& game->map[lines][rows] != 'E')
				return (1);
			rows++;
			i = rows;
		}
		lines++;
	}
	return (check_dim(lines, i));
}

static int	ft_void(char *line, char *entire_map)
{
	if (line)
		free(line);
	if (entire_map)
		free(entire_map);
	return (ft_error(1));
}

static void	init_map_utils(t_data *game, char *entire_map, char *line, int fd)
{
	char	*test;

	test = NULL;
	while (line)
	{
		if (ft_so_long_len(line) != game->x)
		{
			ft_void(line, entire_map);
			free_map_2(game->map, game->check_path_map);
		}
		entire_map = ft_strjoin(entire_map, line);
		if (test)
			free(test);
		game->y++;
		free(line);
		line = get_next_line(fd);
		test = entire_map;
	}
	line = NULL;
	free(line);
	game->map = ft_split(entire_map, '\n');
	game->check_path_map = ft_split(entire_map, '\n');
	free(entire_map);
}

int	init_map(t_data *game, char *av)
{
	int		fd;
	char	*line;
	char	*entire_map;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_void(line, NULL);
	game->y = 0;
	game->x = ft_strlen(line) - 1;
	entire_map = NULL;
	init_map_utils(game, entire_map, line, fd);
	if (char_verif(game))
		return (ft_error(1));
	return (0);
}
