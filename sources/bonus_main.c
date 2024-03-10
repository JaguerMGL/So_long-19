/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:57:26 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/26 14:36:44 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_so_long_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static int	verif_arg(int ac, char *av)
{
	int	map_name;
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (ft_error(1));
	}
	close(fd);
	if (ac != 2)
		return (ft_error(1));
	map_name = ft_strlen(av) - 1;
	if (map_name < 4 || av[map_name - 3] != '.' || av[map_name - 2] != 'b'
		|| av[map_name - 1] != 'e' || av[map_name] != 'r')
		return (ft_error(1));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (verif_arg(argc, argv[1]) || init_map(&game, argv[1]))
		return (1);
	if (verif_map(&game))
		return (1);
	game.anim_piece = 0;
	init_game(&game);
	return (0);
}
