/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:10:28 by mvassall          #+#    #+#             */
/*   Updated: 2025/10/01 12:38:41 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "ctx.h"
#include "cub3d.h"
#include "draw.h"
#include "libft.h"
#include "map.h"
#include "minimap.h"
#include "ray.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

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
	aux *= ctx->img->height;
	return ((uint32_t)aux % ctx->textures[ray->face]->width);
}

static uint32_t	get_texture_pixel(mlx_texture_t *t, uint32_t x, uint32_t y)
{
	uint32_t	*p;

	if (x >= t->width || y >= t->height)
		return (COLOR_RED);
	p = (uint32_t *)t->pixels;
	return (p[y * t->width + x]);
}

static void	cub3d_draw_ray(t_ray *ray, uint32_t img_x, t_ctx *ctx)
{
	t_point			p1;
	uint32_t		ray_h;
	uint32_t		k;
	mlx_texture_t	*tre;
	double			c;

	if (ray->p_len < 0.1)
		ray->p_len = 0.1;
	ray_h = round(ctx->img->height / ray->p_len);
	if (ray_h >= ctx->img->height)
		ray_h = ctx->img->height - 1;
	p1.x = img_x;
	p1.y = (ctx->img->height - ray_h + 1) / 2;
	tre = ctx->textures[ray->face];
	c = round((tre->height - 1.0) / (ray_h - 1.0));
	k = 0;
	while (k < ray_h)
	{
		mlx_put_pixel(ctx->img, 
			img_x, p1.y + k,
			get_texture_pixel(tre, texture_column(ray, ctx), c * k));
		k++;
	}
}


void	cub3d_display_3d(void *param)
{
	t_ctx		*ctx;
	t_ray		*rays;
	uint32_t	x;

	ctx = (t_ctx *)param;
	cub3d_print_fps(ctx->mlx);
	if (!ctx->redraw)
		return ;
	cub3d_draw_floor_ceiling(ctx);
	rays = ray_casting(ctx->player, ctx->map, ctx->img->width);
	if (rays != NULL)
	{
		x = 0;
		while (x < ctx->img->width)
		{
			cub3d_draw_ray(rays + x, x, ctx);
			x++;
		}
		free(rays);
		if (ctx->mmap.draw)
			minimap_draw(ctx);
	}
}
