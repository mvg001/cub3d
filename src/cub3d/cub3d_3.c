/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:10:28 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/19 16:59:02 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "cub3d.h"
#include "draw.h"
#include "map.h"
#include "ray.h"
#include <stdint.h>
#include <stdlib.h>

static void	cub3d_draw_floor_ceiling(t_ctx *ctx)
{
	t_rectangle	r;
	t_point		p;

	r.pos.x = 0;
	r.pos.y = 0;
	r.width = ctx->img->width;
	r.height = ctx->img->height / 2;
	draw_rectangle(ctx->img, &r, ctx->map->ceiling_color);
	r.pos.y = r.height;
	draw_rectangle(ctx->img, &r, ctx->map->floor_color);
	p.x = ctx->img->width - 1;
	p.y = r.pos.y;
	draw_line(ctx->img, &r.pos, &p, COLOR_GRAY);
}

static void	cub3d_draw_ray(t_ray *rays, uint32_t col, t_ctx *ctx, uint32_t color)
{
	t_point		p1;
	t_point 	p2;
	double		h;
	double		plen;

	plen = rays[col].p_len;
	if (plen < 0.1)
		plen = 0.1;
	h = ctx->img->height / plen;
	if (h >= ctx->img->height)
		h = ctx->img->height - 1;
	p1.x = col;
	p1.y = (ctx->img->height - h) / 2.0;
	p2.x = col;
	p2.y = p1.y + h;
	draw_line(ctx->img, &p1, &p2, color);
}

void	cub3d_display_3d(void *param)
{
	t_ctx		*ctx;
	t_ray		*rays;
	uint32_t	i;
	uint32_t	color[4];

	ctx = (t_ctx *)param;
	color[FACE_NORTH] = 0xff0000ff;
	color[FACE_SOUTH] = 0x00ff00ff;
	color[FACE_EAST]  = 0x0000ffff;
	color[FACE_WEST]  = 0xffff00ff;
	cub3d_draw_floor_ceiling(ctx);
	rays = ray_casting(ctx->player, ctx->map, ctx->img->width);
	if (rays != NULL)
	{
		i = 0;
		while (i < ctx->img->width)
		{
			cub3d_draw_ray(rays, i, ctx, color[rays[i].face]);
			i++;
		}
		free(rays);
	}
}
