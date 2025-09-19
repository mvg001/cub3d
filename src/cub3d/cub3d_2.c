/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:33:10 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/19 14:10:53 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "ctx.h"
#include "cub3d.h"
#include "draw.h"
#include "map.h"
#include "player.h"
#include "vec2d.h"

static void move(t_ctx *ctx, double dx, double dy)
{
	double	nx;
	double	ny;

	nx = ctx->player->pos.x + dx;
	ny = ctx->player->pos.y + dy;
	if (map_is_cell_wall_d(ctx->map, nx, ny))
		return ;
	ctx->player->pos.x += dx;
	ctx->player->pos.y += dy;
}

static void	rotate(t_ctx *ctx, mlx_key_data_t kdata)
{
	double	*rot_ref;
	double	rotation[4];

	rot_ref = ctx->player_rotation;
	if (kdata.modifier == MLX_SHIFT)
		rot_ref = ctx->player_fast_rotation;
	if (kdata.key == MLX_KEY_LEFT)
	{
		rotation[0] = rot_ref[0];
		rotation[1] = rot_ref[2];
		rotation[2] = rot_ref[1];
		rotation[3] = rot_ref[3];
		rot_ref = rotation;
	}
	else if (kdata.key != MLX_KEY_RIGHT)
		return ;
	vec2d_rotate(&ctx->player->dir, rot_ref);
}	

void	cub3d_key_callback(mlx_key_data_t kdata, void *param)
{
	t_ctx		*ctx;
	t_player	*player;
	double		step;
	
	ctx = (t_ctx *)param;
	player = (t_player *)ctx->player;
	if (kdata.action != MLX_PRESS && kdata.action != MLX_REPEAT)
		return ;
	step = PLAYER_STEP;
	if (kdata.modifier == MLX_SHIFT)
		step = PLAYER_FAST_STEP;
	if (kdata.key == MLX_KEY_W)
		move(ctx, player->dir.x * step, player->dir.y * step);
	else if (kdata.key == MLX_KEY_A)
		move(ctx, player->dir.y * step, - player->dir.x * step);
	else if (kdata.key == MLX_KEY_S)
		move(ctx, - player->dir.x * step,  - player->dir.y * step);
	else if (kdata.key == MLX_KEY_D)
		move(ctx, - player->dir.y * step, player->dir.x * step);
	else if (kdata.key == MLX_KEY_ESCAPE)
		mlx_close_window(ctx->mlx);
	else
		rotate(ctx, kdata);
}
