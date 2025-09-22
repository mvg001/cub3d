/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:42:52 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/22 16:20:57 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "ctx.h"
#include <stdbool.h>

bool player_move(t_ctx *ctx, double dx, double dy)
{
	double	nx;
	double	ny;

	nx = ctx->player->pos.x + dx;
	ny = ctx->player->pos.y + dy;
	if (map_is_cell_wall_d(ctx->map, nx, ny))
		return (false);
	ctx->player->pos.x += dx;
	ctx->player->pos.y += dy;
	ctx->redraw = true;
	return (true);
}

