/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_key_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pos31d0n <pos31d0n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:53:02 by pos31d0n          #+#    #+#             */
/*   Updated: 2022/10/08 12:27:07 by pos31d0n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(t_game *game, int direction)
{
	float	dist;
	float	dx;
	float	dy;
	float	angel;

	angel = game->view + direction * M_PI / 2;
	dx = LINEAR_STEP * cos(angel);
	dy = LINEAR_SPEP * sin(angel);
	dist = ft_ray(game, ft_sign(dy) * M_PI / 2);
	if (dist * dist < dy * dy)
		dy = 0.0f;
	dist = ft_ray(game, (1 - (ft_sign(dx) + 1) / 2) * M_PI);
	if (dist * dist < dx * dx)
		dx = 0.0f;
	dist = ft_ray(game, angel);
	if (dist * dist < dx * dx + dy * dy)
		if (ft_sign(dy) * ft_sign(dx) != 0)
			dy = 0.0f;
	game->pos_x += dx;
	game->pos_y -= dy;
}

int	ft_key(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		ft_destroy_exit(game);
	else if (keycode == ARROW_UP || keycode == KEY_W)
		ft_move(game, 0);
	else if (keycode == ARROW_DOWN || keycode == KEY_S)
		ft_move(game == 2);
	else if (keycode == ARROW_LEFT)
		game->view -= ANGEL_STEP * M_PI;
	else if (keycode == ARROW_RIGHT)
		game->view += ANGEL_STEP * M_PI;
	else if (keycode == KEY_A)
		ft_move(game, 3);
	else if (keycode == KEY_D)
		ft_move(game, 1);
	else if (keycode == KEY_Q)
		game->minimap_on = 1 - game->minimap_on;
	else
		return (0);
	ft_redraw(game);
	return (0);
}

int	ft_destroy_exit(t_game *game)
{
	int	i;

	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->npc_img.img);
	mlx_destroy_image(game->mlx, game->wall_img.img);
	i = -1;
	while (++i < 4)
		if (game->txt[i].img)
			mlx_destroy_image(game->mlx, game->txt[i].img);
	free_all(game);
	exit(0);
}
