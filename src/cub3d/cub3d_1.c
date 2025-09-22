/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:48:18 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/22 16:33:10 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "ctx.h"
#include "cub3d.h"
#include "libft.h"
#include "draw.h"
#include "map.h"
#include "minimap.h"
#include "ray.h"
#include <stdint.h>



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
	mlx_loop_hook(ctx->mlx, cub3d_display_3d, ctx);
	mlx_key_hook(ctx->mlx, cub3d_key_callback, ctx);
	mlx_loop(ctx->mlx);
	mlx_terminate(ctx->mlx);
    return (1);
}
