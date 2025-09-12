/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:33:10 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/12 12:46:55 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "ctx.h"
#include "cub3d.h"
#include "player.h"

// static void	cub3d_move_player(key_t key, t_player *player, int is_fast)
// {
// 	if (key == MLX_KEY_UP)
// 	{
		
// 	}
// }

static void move(t_player *player, double dx, double dy)
{
	player->pos.x += dx;
	player->pos.y += dy;
}

void	cub3d_key_callback(mlx_key_data_t keydata, void *param)
{
	t_ctx		*ctx;
	t_player	*player;
	double		step;
	
	ctx = (t_ctx *)param;
	player = (t_player *)ctx->player;
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	step = PLAYER_STEP;
	if (keydata.modifier == MLX_SHIFT)
		step = PLAYER_FAST_STEP;
	if (keydata.key == MLX_KEY_W)
		move(player, 0, -step);
	else if (keydata.key == MLX_KEY_A)
		move(player, -step, 0);
	else if (keydata.key == MLX_KEY_S)
		move(player, 0, step);
	else if (keydata.key == MLX_KEY_D)
		move(player, step, 0);
	else if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(ctx->mlx);
}
