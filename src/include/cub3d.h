/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:53:56 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/10 20:33:08 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "map.h"
# include "player.h"

# define TILE_SIZE	32
# define FOV		66	// degrees

typedef struct	s_ctx
{
	t_map	*map;
	t_player *player;
}	t_ctx;

void	run_app(t_map *map, t_player *player);
#endif