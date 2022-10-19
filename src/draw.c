/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pos31d0n <pos31d0n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:29:37 by pos31d0n          #+#    #+#             */
/*   Updated: 2022/10/17 13:52:25 by pos31d0n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_ceiling_and_floor(t_game *game)
{
	unsigned int	*dst;
	unsigned int	i;

	dst = (unsigned int *)game->img.addr;
	i = WINDOW_W * WINDOW_H / 2 + 1;
	while (--i > 0)
		*dst++ = game->color_ceiling;
	i = WINDOW_W * WINDOW_H / 2 + 1;
	while (--i > 0)
		*dst++ = game->color_floor;
}

void	ft_line(t_game *game, int w, float disk)
{
	unsigned int	h;
	unsigned int	*dst;
	unsigned int	*src;
	float			src_f;
	float			d_shift;

	h = (float) WINDOW_H / disk;
	src_f = 0.0f;
	d_shift = (float) game->txt[game->txt_idx].height / h;
	if (h > WINDOW_H)
	{
		src_f = 0.5f * (h - WINDOW_H) / h * game->txt[game->txt_idx].height;
		h = WINDOW_H;
	}
	src = (unsigned int *) game->txt[game->txt_idx].addr;
	src += (int)(float) game->txt_w * game->txt[game->txt_idx].width;
	dst = (unsigned int *) game->img.addr + w + (WINDOW_H - h) / 2 * WINDOW_W;
	while (h-- > 0)
	{
		*dst = *(src +((int)src_f) * game->txt[game->txt_idx].width);
		// Ниже как проверка на прорисовку, там каждая стена имеет свой цвет
		//*dst = game->txt_idx * 255 + (1 - game->txt_idx) * (255 << 8);
		dst += WINDOW_W;
		src_f += d_shift;
	}
}

void	ft_redraw(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WINDOW_W, WINDOW_H);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	ft_draw_ceiling_and_floor(game);
	ft_ray_casting(game);
	mlx_put_image_to_image(game->mlx, game->win, game->img.img, 0, 0);
	mlx_destroy_img(game->mlx, game->img.img);
	// Тут похоже для бонусов, миникарты
	if (game->minimap_on)
		print_bonus_map_pictures(game);
}
