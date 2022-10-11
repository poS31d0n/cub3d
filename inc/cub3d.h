/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pos31d0n <pos31d0n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:23:17 by pos31d0n          #+#    #+#             */
/*   Updated: 2022/10/10 14:28:20 by pos31d0n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct t_game
{
	int				i;
	char			*hz;
	int				pos_x;
	int				pos_y;
	float			txt_w;
	float			view;
	t_img			img;
	t_ray			ray;
	float			**map;
	t_win			win;
	t_txt			*txt;
	t_map_l			map_l;
	t_all_map		all_map;
	int				txt_idx;
	t_trim_map		trim_map;
	char			*path_nswe;
	int				only_map_h;
	t_minimap_on	minimap_on;
	t_color_floor	color_floor;
	t_color_ceiling	color_ceiling;
}					t_game;

typedef struct t_ray
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	vert_w;
	int	vert_x;
	int	vert_y;
	int	vert_dist;
	int	hor_w;
	int	hor_x;
	int	hor_y;
	int	hor_dist;
}		t_ray;

typedef struct t_img
{
	int		img;
	int		addr;
	char	*hz;
	int		endian;
	int		bits_per_pixel;
	int		line_length;
}			t_img;

typedef struct t_color_floor
{
	int		hz;
}			t_color_floor;

typedef struct t_color_ceiling
{
	int		hz;
}			t_color_ceiling;

typedef struct t_minimap_on
{
	int		hz;
}			t_minimap_on;

typedef struct t_win
{
	int		hz;
}			t_win;

typedef struct t_txt
{
	int		hight;
	t_game	game;
	int		img;
	int		width;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
	int		addr;
}			t_txt;

typedef struct t_txt_idx
{
	int		hz;
}			t_txt_idx;

typedef struct t_path_nswe
{
	int		hz;
}			t_path_nswe;

typedef struct t_map
{
	int		hz;
}			t_map;

typedef struct t_trim_map
{
	int		hz;
}			t_trim_map;

typedef struct t_only_map_h
{
	int		hz;
}			t_only_map_h;

typedef struct t_all_map
{
	int		hz;
}			t_all_map;

typedef struct t_map_l
{
	int		hz;
}			t_map_l;

typedef struct t_only_map_h
{
	int		hz;
}			t_only_map_h;

void	ft_redraw(t_game *game);
void	ft_line(t_game *game, int w, float disk);

void	start_game(t_game *game);

void	init_struct(t_game *game);
void	check_args(int argc, char **argv, t_game *game);

void	height_map(t_game game, char argv[1]);
void	read_map(t_game game, char argv[1]);

float	ft_ray(t_game *game, float v);

#endif