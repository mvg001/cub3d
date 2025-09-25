/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:55:27 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/25 11:18:25 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ctx.h"
#include "cub3d.h"
#include "draw.h"
#include "minimap.h"
#include "ray.h"

static void	minimap_draw_map(t_ctx *ctx)
{
	t_rectangle	r;
	int			i;
	int 		j;
	
	if (ctx == NULL)
		return ;
	r.width = ctx->mmap.tile_size - 1;
	r.height = r.width;
	i = -1;
	while (++i < ctx->map->n_lines)
	{
		j = -1;
		r.pos.y = i * ctx->mmap.tile_size;
		while (++j < ctx->map->n_columns)
		{
			if (!map_is_cell_wall_d(ctx->map, j, i))
				continue;
			r.pos.x = j * ctx->mmap.tile_size;
			draw_rectangle(ctx->img, &r, MINIMAP_TILE_COLOR);
		}
	}
	return ;
}

static void	minimap_draw_rays(t_ctx *ctx, t_point	*player_position)
{
	uint32_t		i;
	t_ray		*rays;
	t_point		pcolision;

	rays = ray_casting(ctx->player, ctx->map, MINIMAP_N_RAYS);
	if (rays == NULL)
		return ;
	i = 0;
	while (i < MINIMAP_N_RAYS)
	{
		pcolision.x = ctx->mmap.tile_size * rays[i].colision.x;
		pcolision.y = ctx->mmap.tile_size * rays[i].colision.y;
		draw_line(ctx->img, player_position, &pcolision, MINIMAP_RAY_COLOR);
		i++;
	}
	free(rays);
}

static void	minimap_draw_player(t_ctx *ctx)
{
	t_circle	c;
	
	c.center.x = (ctx->player->pos.x * ctx->mmap.tile_size);
	c.center.y = (ctx->player->pos.y * ctx->mmap.tile_size);
	c.radius = (ctx->mmap.tile_size * PLAYER_SIZE);
	minimap_draw_rays(ctx, &c.center);
	draw_circle(ctx->img, &c, COLOR_RED);
}

void	minimap_draw(t_ctx *ctx)
{
	t_rectangle	wallpaper;

	if (ctx == NULL || !ctx->redraw || !ctx->mmap.draw
		|| ctx->mmap.tile_size <= 0)
		return ;
	wallpaper.pos.x = 0;
	wallpaper.pos.y = 0;
	wallpaper.width = ctx->mmap.tile_size * ctx->map->n_columns;
	wallpaper.height = ctx->mmap.tile_size * ctx->map->n_lines;
	draw_rectangle(ctx->img, &wallpaper, COLOR_BLACK);
	minimap_draw_map(ctx);
	minimap_draw_player(ctx);
}

void	minimap_calculate(t_ctx *ctx)
{
	double	ts_y;
	double	ts;

	ts = round((WINDOW_WIDTH * MINIMAP_SCALE) / ctx->map->n_columns);
	ts_y = round((WINDOW_HEIGHT * MINIMAP_SCALE) / ctx->map->n_lines);
	if (ts > ts_y)
		ts = ts_y;
	if (ts < MINIMAP_MIN_TILESIZE)
		ts = 0;
	ctx->mmap.tile_size = ts;
	ctx->mmap.draw = false;
}