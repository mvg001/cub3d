/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:40:55 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/25 14:03:51 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "ctx.h"
#include "cub3d.h"
#include "libft.h"
#include "map.h"
#include "minimap.h"
#include "player.h"
#include "vec2d.h"
#include <stdint.h>

static int	load_textures(t_ctx *ctx)
{
	int	i;

	if (ctx == NULL || ctx->map == NULL)
		return (0);
	i = -1;
	while (++i < LAST_TEXTURE)
	{
		ctx->textures[i] = mlx_load_png(ctx->map->textures[i]);
		if (ctx->textures[i] == NULL)
		{
			return (0);
		}
	}
	return (1);
}

static int	destroy_textures(t_ctx *ctx)
{
	int	i;

	if (ctx == NULL)
		return (0);
	i = -1;
	while (++i < LAST_TEXTURE)
		if (ctx->textures[i] != NULL)
		{
			mlx_delete_texture(ctx->textures[i]);
			ctx->textures[i] = NULL;
		}
	return (1);
}

static int	add_map_player(t_ctx *ctx)
{
	if (ctx == NULL)
		return (0);
	ctx->player = player_create_char_dir(
		ctx->map->player_init_x + 0.5,
		ctx->map->player_init_y + 0.5,
		ctx->map->player_init_dir);
	if (ctx->player == NULL)
		return (map_destroy(&ctx->map), 0);
	return (1);
}

t_ctx	*ctx_create(char *filename)
{
	t_ctx		*ctx;

	if (filename == NULL)
		return (NULL);
	ctx = ft_calloc(1, sizeof(t_ctx));
	if (ctx == NULL)
		return (NULL);
	ctx->map = map_read(filename);
	if (ctx->map == NULL || !add_map_player(ctx) || !load_textures(ctx))
		return (ctx_destroy(&ctx), NULL);
	minimap_calculate(ctx);
	vec2d_gen_rotation_degree(ctx->player_rotation, PLAYER_ROTATION);
	vec2d_gen_rotation_degree(ctx->player_fast_rotation, PLAYER_FAST_ROTATION);
	ctx->redraw = true;
	return (ctx);
}

int		ctx_destroy(t_ctx **ctx)
{
	if (ctx == NULL)
		return (0);
	if ((*ctx)->player != NULL)
		player_destroy(&(*ctx)->player);
	if ((*ctx)->map != NULL)
		map_destroy(&(*ctx)->map);
	destroy_textures(*ctx);
	free(*ctx);
	*ctx = NULL;
	return (1);
}
