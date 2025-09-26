/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:38:50 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/26 11:40:51 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include <stdbool.h>
# include <stdint.h>
#include "minimap.h"
# include "player.h"
# include "map.h"
# include "MLX42/MLX42.h"

typedef struct	s_ctx
{
	t_map		*map;
	t_player 	*player;
	t_minimap	mmap;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_texture_t	*textures[LAST_TAG];
	bool		redraw;
	double		player_rotation[4];
	double		player_fast_rotation[4];
}	t_ctx;

t_ctx	*ctx_create(char *filename);
int		ctx_destroy(t_ctx **ctx);
#endif