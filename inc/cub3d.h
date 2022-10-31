/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pos31d0n <pos31d0n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:23:17 by pos31d0n          #+#    #+#             */
/*   Updated: 2022/10/27 17:30:19 by pos31d0n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define WINDOW_W 100
# define WINDOW_H 100

# define LINEAR_STEP // ?
# define ON_KEYDOWN // ?
# define KeyPressMask // ?
# define ANGEL_STEP // ?
# define ON_DESTROY // ?
# define NoEventMask // ?
# define FOV 66

# define ESC_KEY 53

# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_Q 12

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
	char			win;
	void			*mlx;
	t_txt			*txt;
	int				map_l;
	char			all_map;
	int				txt_idx;
	char			trim_map;
	char			*path_nswe;
	int				only_map_h;
	int				minimap_on;
	int				color_floor;
	int				color_ceiling;
	t_npc_img		npc_img;
	t_wall_img		wall_img;
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

typedef struct t_npc_img
{
	char	img;
}			t_npc_img;

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
	int		height;
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

typedef struct t_wall_img
{
	char	img;
}			t_wall_img;

typedef struct s_vector
{
	float x;
	float y;
	int pos;
	char **newmap;
	char	side;
	char *north;
	char *south;
	char *east;
	char *west;
	int *floor;
	int *celling;
}				t_vector;

typedef struct s_map
{
	t_vector	size;
	t_vector	position;
	int			north;
	int			south;
	int			west;
	int			east;
}				t_map;

int ft_compare(char *str, char *str2);
char	**map_reader(char *file);
t_vector valid_colors(char **map, t_vector vector);
t_vector valid_objects(char **map, t_vector vector);
t_vector map_finder(char **map, t_vector vector);
void error(t_vector vector);
int valid(int bool, t_vector vector);
void	ft_free_chartable(char **map);
void errormap(t_vector vector, char **map);
void ft_free(t_vector vector);
t_vector ft_init(t_vector vector);
int *fillobj(int h, char *tmp, t_vector vector, char **map, int *object);
void	freetmp(int h, char *tmp, t_vector vector, char ** map);
void	freetmp(int h, char *tmp, t_vector vector, char ** map);
void booling(int bool, int i, int j, char *str, t_vector vector);
void checks(int j, int i, t_vector vector);
void checkssss(t_vector vector, int i, int j);
t_vector newmapp(char **map, int i, int tmp, int tmp2, t_vector vector);
t_vector *finder(int tmp, t_vector *vector, char *str);
//draw.c
void	ft_line(t_game *game, int w, float disk);
void	ft_redraw(t_game *game);

//game.c
void	find_position(t_game *game);
void	start_game(t_game *game);

//main.c
void	check_args(int argc, char **argv, t_game *game);
void	init_struct(t_game *game);

//map.c
void	height_map(t_game game, char *argv);
void	read_map(t_game game, char *argv);

//moving_key_destroy.c
void	ft_move(t_game *game, int direction);
int		ft_key(int keycode, t_game *game);
int		ft_destroy_exit(t_game *game);

//ray.c
float	ft_ray(t_game *game, float v);
void	ft_ray_casting(t_game *game);

//utils.c
int		ft_sign(int d);

#endif