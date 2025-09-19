/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:48:18 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/19 16:52:38 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "ctx.h"
#include "cub3d.h"
#include "libft.h"
#include "draw.h"
#include "map.h"
#include "ray.h"
#include <stdint.h>

static void	cub3d_draw_map(t_ctx *ctx)
{
	t_rectangle	r;
	int			i;
	int 		j;
	
	if (ctx == NULL)
		return ;
	r.width = ctx->tilesize - 1;
	r.height = r.width;
	i = -1;
	while (++i < ctx->map->n_lines)
	{
		j = -1;
		r.pos.y = i * ctx->tilesize;
		while (++j < ctx->map->n_columns)
		{
			if (!map_is_cell_wall_d(ctx->map, j, i))
				continue;
			r.pos.x = j * ctx->tilesize;
			draw_rectangle(ctx->img, &r, TILE_COLOR);
		}
	}
	return ;
}

static void	cub3d_draw_rays(t_ctx *ctx, t_point	*player_position)
{
	uint32_t		i;
	t_ray		*rays;
	t_point		pcolision;

	rays = ray_casting(ctx->player, ctx->map, N_RAYS);
	if (rays == NULL)
		return ;
	i = 0;
	while (i < N_RAYS)
	{
		pcolision.x = ctx->tilesize * rays[i].colision.x;
		pcolision.y = ctx->tilesize * rays[i].colision.y;
		draw_line(ctx->img, player_position, &pcolision, RAY_COLOR);
		i++;
	}
	free(rays);
}

static void	cub3d_draw_player(t_ctx *ctx)
{
	t_circle	c;
	t_point		p[3];
	
	c.center.x = (ctx->player->pos.x * ctx->tilesize);
	c.center.y = (ctx->player->pos.y * ctx->tilesize);
	c.radius = (ctx->tilesize * PLAYER_SIZE);
	cub3d_draw_rays(ctx, &c.center);
	draw_circle(ctx->img, &c, COLOR_RED);
	c.radius = (c.radius * 3 + 2) / 4;
	p[0].x = c.center.x + ctx->player->dir.x * c.radius;
	p[0].y = c.center.y + ctx->player->dir.y * c.radius;
	p[1].x = c.center.x - ctx->player->dir.y * c.radius;
	p[1].y = c.center.y + ctx->player->dir.x * c.radius;
	p[2].x = c.center.x + ctx->player->dir.y * c.radius;
	p[2].y = c.center.y - ctx->player->dir.x * c.radius;
	draw_line(ctx->img, p, p+1, COLOR_BLACK);
	draw_line(ctx->img, p, p+2, COLOR_BLACK);
	draw_line(ctx->img, p+1, p+2, COLOR_BLACK);
}

void	cub3d_draw_minimap(void *param)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)param;
	draw_fill_image(ctx->img, COLOR_BLACK);
	cub3d_draw_map(ctx);
	cub3d_draw_player(ctx);
}
int run_app(t_ctx *ctx)
{
    if (ctx == NULL)
        return (0);
    ctx->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "MINIMAP", false);
    if (ctx->mlx == NULL)
        return (ft_dprintf(2,"Error\nUnable to create window\n"), 0);
    ctx->img = mlx_new_image(ctx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (ctx->img == NULL
        || (mlx_image_to_window(ctx->mlx, ctx->img, 0, 0) < 0))
	{
		ft_dprintf(2, "Error\nUnable to img to window\n");
		mlx_terminate(ctx->mlx);
		return (0);
	}
	//mlx_loop_hook(ctx->mlx, cub3d_draw_minimap, ctx);
	mlx_loop_hook(ctx->mlx, cub3d_display_3d, ctx);
	mlx_key_hook(ctx->mlx, cub3d_key_callback, ctx);
	mlx_loop(ctx->mlx);
	mlx_terminate(ctx->mlx);
    return (1);
}
