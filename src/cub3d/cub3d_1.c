/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:48:18 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/11 16:28:29 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "ctx.h"
#include "cub3d.h"
#include "libft.h"
#include "draw.h"
#include "map.h"
#include <stdint.h>

static void	draw_map(t_ctx	*ctx)
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

static void	draw_player(t_ctx *ctx)
{
	t_rectangle	r;
	uint32_t	d;

	r.width	= (ctx->tilesize * 3) / 4;
	r.height = r.width;
	d = (r.width + 1) / 2;
	r.pos.x = (ctx->player->pos.x * ctx->tilesize) - d;
	r.pos.y = (ctx->player->pos.y * ctx->tilesize) - d;
	draw_rectangle(ctx->img, &r, COLOR_RED);
}

static void	draw(void *param)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)param;
	draw_map(ctx);
	draw_player(ctx);
}

int run_app(t_ctx *ctx)
{
	t_rectangle	r;

    if (ctx == NULL)
        return (0);
    ctx->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "MINIMAP", false);
    if (ctx->mlx == NULL)
        return (ft_dprintf(2,"Error\nUnable to create window\n"), 0);
    ctx->img = mlx_new_image(ctx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	r.pos.x = 0;
	r.pos.y = 0;
	r.width = WINDOW_WIDTH;
	r.height = WINDOW_HEIGHT;
	draw_rectangle(ctx->img, &r, COLOR_BLACK);
    if (ctx->img == NULL
        || (mlx_image_to_window(ctx->mlx, ctx->img, 0, 0) < 0))
	{
		ft_dprintf(2, "Error\nUnable to img to window\n");
		mlx_terminate(ctx->mlx);
		return (0);
	}
	mlx_loop_hook(ctx->mlx, draw, ctx);
	mlx_loop(ctx->mlx);
	mlx_terminate(ctx->mlx);
    return (1);
}
