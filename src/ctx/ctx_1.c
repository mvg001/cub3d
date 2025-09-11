/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:40:55 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/11 16:04:29 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "cub3d.h"
#include "libft.h"
#include "map.h"
#include "player.h"
#include <stdint.h>

static int	add_map_player(t_ctx *ctx, char *filename)
{
	if (ctx == NULL || filename == NULL)
		return (0);
	ctx->map = map_read(filename);
	if (ctx->map == NULL)
		return (0);
	ctx->player = player_create_char_dir(ctx->map->player_init_x + 0.5,
		ctx->map->player_init_y + 0.5,
		ctx->map->player_init_dir);
	if (ctx->player == NULL)
		return (map_destroy(&ctx->map), 0);
	return (1);
}

static uint32_t	calculate_tilesize(t_map *m, uint32_t width, uint32_t height)
{
	uint32_t	tx;
	uint32_t	ty;

	if (m == NULL)
		return (0);
	tx = width / m->n_columns;
	ty = height / m->n_lines;
	if (tx < ty)
		return (tx);
	return (ty);
}

t_ctx	*ctx_create(char *filename)
{
	t_ctx		*ctx;

	if (filename == NULL)
		return (NULL);
	ctx = ft_calloc(1, sizeof(t_ctx));
	if (ctx == NULL)
		return (NULL);
	if (!add_map_player(ctx, filename))
		return (ctx_destroy(&ctx), NULL);
	ctx->tilesize = calculate_tilesize(ctx->map, WINDOW_WIDTH, WINDOW_HEIGHT);
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
	free(*ctx);
	*ctx = NULL;
	return (1);
}
