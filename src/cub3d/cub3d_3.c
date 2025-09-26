/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:10:28 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/26 12:42:02 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "ctx.h"
#include "cub3d.h"
#include "draw.h"
#include "map.h"
#include "minimap.h"
#include "ray.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

static void	cub3d_draw_floor_ceiling(t_ctx *ctx)
{
	t_rectangle	r;

	r.pos.x = 0;
	r.pos.y = 0;
	r.width = ctx->img->width;
	r.height = ctx->img->height / 2;
	draw_rectangle(ctx->img, &r, ctx->map->ceiling_color);
	r.pos.y = r.height;
	draw_rectangle(ctx->img, &r, ctx->map->floor_color);
}

// TODO
// static void	cub3d_draw_ray(t_ray *rays, uint32_t col, t_ctx *ctx, uint32_t color)
// {
// 	t_point		p1;
// 	t_point 	p2;
// 	double		h;
// 	double		plen;

// 	plen = rays[col].p_len;
// 	if (plen < 0.1)
// 		plen = 0.1;
// 	h = ctx->img->height / plen;
// 	if (h >= ctx->img->height)
// 		h = ctx->img->height - 1;
// 	p1.x = col;
// 	p1.y = (ctx->img->height - h) / 2.0;
// 	p2.x = col;
// 	p2.y = p1.y + h;
// 	draw_line(ctx->img, &p1, &p2, color);
// }

// void	cub3d_display_3d(void *param)
// {
// 	t_ctx		*ctx;
// 	t_ray		*rays;
// 	uint32_t	i;
// 	uint32_t	color[4];

// 	ctx = (t_ctx *)param;
// 	cub3d_print_fps(ctx->mlx);
// 	if (!ctx->redraw)
// 		return ;
// 	color[FACE_NORTH] = 0xff0000ff;
// 	color[FACE_SOUTH] = 0x00ff00ff;
// 	color[FACE_EAST]  = 0x0000ffff;
// 	color[FACE_WEST]  = 0xffff00ff;
// 	cub3d_draw_floor_ceiling(ctx);
// 	rays = ray_casting(ctx->player, ctx->map, ctx->img->width);
// 	if (rays != NULL)
// 	{
// 		i = 0;
// 		while (i < ctx->img->width)
// 		{
// 			cub3d_draw_ray(rays, i, ctx, color[rays[i].face]);
// 			i++;
// 		}
// 		free(rays);
// 		if (ctx->mmap.draw)
// 			minimap_draw(ctx);
// 	}
// }

static uint32_t	texture_column(t_ray *ray, t_ctx *ctx)
{
	double_t	aux;

	if (ray->face == NORTH || ray->face == SOUTH)
		aux = (ray->colision.x - floor(ray->colision.x));
	else
	 	aux = (ray->colision.y - floor(ray->colision.y));
	return ((uint32_t)aux % ctx->textures[ray->face]->width);
}

static void	cub3d_draw_ray(t_ray *ray, uint32_t col, t_ctx *ctx)
{
	t_point		p1;
	uint32_t	h;
	uint32_t	img_col[WINDOW_HEIGHT];
	uint32_t	i;
	mlx_texture_t	*txt;
	

	if (ray->p_len < 0.1)
		ray->p_len = 0.1;
	h = round(ctx->img->height / ray->p_len);
	if (h >= ctx->img->height)
		h = ctx->img->height - 1;
	p1.x = col;
	p1.y = (ctx->img->height - h + 1) / 2;
	txt = ctx->textures[ray->face];
	cub3d_slice_texture(txt, texture_column(ray, ctx),	h, img_col);
	i = 0;
	while (i < h)
	{
		mlx_put_pixel(ctx->img, col, p1.y + i, img_col[i]);
		i++;
	}
}


void	cub3d_display_3d(void *param)
{
	t_ctx		*ctx;
	t_ray		*rays;
	uint32_t	i;

	ctx = (t_ctx *)param;
	cub3d_print_fps(ctx->mlx);
	if (!ctx->redraw)
		return ;
	cub3d_draw_floor_ceiling(ctx);
	rays = ray_casting(ctx->player, ctx->map, ctx->img->width);
	if (rays != NULL)
	{
		i = 0;
		while (i < ctx->img->width)
		{
			cub3d_draw_ray(rays + i, i, ctx);
			i++;
		}
		free(rays);
		if (ctx->mmap.draw)
			minimap_draw(ctx);
	}
}
