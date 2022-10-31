/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pos31d0n <pos31d0n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:01:08 by pos31d0n          #+#    #+#             */
/*   Updated: 2022/10/18 11:16:45 by pos31d0n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_position(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		game->txt[i].img = mlx_xpm_file_to_image(game->mlx,
				game->path_nswe[i], game->txt[i].width, & game->txt[i].height);
		if (!game->txt[i].img)
		{
			ft_putstr_fd("Error\nCann't read file '", 2);
			ft_putstr_fd(game->path_nswe[i], 2);
			ft_putstr_fd("'\n", 2);
			ft_destroy_exit(game);
		}
		game->txt[i].addr = mlx_get_data_addr(game->txt[i].img,
				&game->txt[i].bits_per_pixel, &game->txt[i].line_length,
				&game->txt[i].endian);
	}
}

void	start_game(t_game *game)
{
	find_position(game);
	game->mlx = init_mlx();
	game->win = mlx_new_window(game->mlx, WINDOW_W, WINDOW_H, "cub3d");
	ft_redraw(game);
	mlx_hook(game->win, ON_KEYDOWN, KeyPressMask, ft_key, game);
	mlx_hook(game->win, ON_DESTROY, NoEventMask, ft_destroy_exit, game);
	mlx_loop(game->mlx);
}
