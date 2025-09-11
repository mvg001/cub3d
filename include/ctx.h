/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:38:50 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/11 12:55:11 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

#include <stdint.h>
# include "player.h"
# include "map.h"
# include "MLX42/MLX42.h"

typedef struct	s_ctx
{
	t_map		*map;
	t_player 	*player;
	uint32_t	tilesize;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_ctx;

t_ctx	*ctx_create(char *filename);
int		ctx_destroy(t_ctx **ctx);
#endif