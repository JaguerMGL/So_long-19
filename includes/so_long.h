/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:51:40 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/26 15:26:39 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESCAPE	53

typedef struct s_img {
	void	*floor;
	void	*wall;
	void	*wall_2;
	void	*player_face;
	void	*player_back;
	void	*player_r;
	void	*player_l;
	void	*piece_1;
	void	*piece_2;
	void	*piece_3;
	void	*piece_4;
	void	*exit_1;
	void	*exit_2;
	void	*exit_3;
	void	*exit_4;
	void	*danger_2;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	char	**map;
	char	**check_path_map;
	int		y;
	int		x;
	int		piece;
	int		nbr_piece;
	int		verif_total;
	int		player_y;
	int		player_x;
	int		exit_y;
	int		exit_x;
	int		moves;
	int		img_pxl;
	int		anim_piece;
	t_img	img_adr;
}	t_data;

//----------display.c----------//
void		init_display(void *m, void *w, t_data *game, char **map);
void		put_player(t_data *game, int x, int y, int pos);
void		put_floor(t_data *game, int x, int y);
void		put_exit(t_data *game, int x, int y);
void		destroy_image(t_data *game);

//----------error.c------------//
int			ft_error(int i);
void		ft_path_error(char **map, char **map2);
void		ft_destroy(t_data *game);
void		free_map(char **map1, char **map2);
void		free_map_2(char **map, char **map2);

//----------get_img.c---------//
void		get_img_adr(t_data *game);

//-----------hook.c-----------//
int			cross_escape(t_data *data);
int			escape(int keycode, t_data *game);
int			key_press(int keycode, t_data *game);

//---------init_game.c--------//
void		init_game(t_data *game);

//---------init_map.c---------//
int			init_map(t_data *game, char *av);

//---------verif_map.c--------//
int			check_dim(int lines, int rows);
int			verif_map(t_data *game);

int			ft_so_long_len(char *str);

int			anim(t_data *game);

void		destroy_image(t_data *game);

#endif