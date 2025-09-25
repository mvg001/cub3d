/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:51:48 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/25 11:26:04 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

#include <stdbool.h>
# define MINIMAP_TILE_COLOR     0x808080ff
# define MINIMAP_RAY_COLOR		0xffff00ff
# define MINIMAP_N_RAYS			7
# define MINIMAP_SCALE			0.25
# define MINIMAP_MIN_TILESIZE	6

typedef struct s_minimap
{
	int		tile_size;
	bool	draw;
}	t_minimap;

typedef struct s_ctx	t_ctx;

void	minimap_draw(t_ctx *ctx);
void	minimap_calculate(t_ctx *ctx);
#endif