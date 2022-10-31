/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pos31d0n <pos31d0n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:02:15 by pos31d0n          #+#    #+#             */
/*   Updated: 2022/10/07 18:07:47 by pos31d0n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
t_vector validation(char **argv, t_vector vector)
{
	char **map;

	map = map_reader(argv[1]);
	if (!map)
		{
			ft_free_chartable(map);
			errormap(vector, map);
		}
	vector = valid_objects(map, vector);
	vector = valid_colors(map, vector);
	vector = map_finder(map, vector);
	ft_free_chartable(map);
	return (vector);
}

void	check_args(int argc, char **argv, t_game *game)
{
	char	*tmp;

	if (!game)
		error_exit(game, 4);
	if (argc != 2)
		error_exit(game, 1);
	tmp = ft_strrchr(argv[1], '.');
	if (ft_strncmp(tmp, ".cub\0", 5))
		error_exit(game, 5);
}

void	init_struct(t_game *game)
{
	int	i;

	game->color_ceiling = -1;
	game->color_floor = -1;
	game->only_map_h = 0;
	game->map_l = 0;
	i = -1;
	while (++i < 4)
	{
		game->path_nswe[i] = NULL;
		game->txt[i].img = NULL;
	}
	game->minimap_on = 0;
	game->all_map = NULL;
	game->trim_map = NULL;
	game->map = NULL;
	game->win = NULL;
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_vector vector;

	vector.pos = 0;
	vector = ft_init(vector);
	if (argc != 2)
		return (0);
	if (ft_compare(argv[1], ".cub") != 1)
		exit(1);
	vector = validation(argv, vector);
	game = malloc(sizeof(t_game));
	init_struct(game);
	check_args(argc, argv, game);
	height_map(*game, argv[1]);
	read_map(*game, argv[1]);
	start_game(game);
	return (0);
}
