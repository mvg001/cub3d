/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:53:56 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/19 13:01:29 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#include "ctx.h"

# define FOV			66		// degrees
# define WINDOW_WIDTH	1024	// pixels
# define WINDOW_HEIGHT	768		// pixels
# define N_RAYS			9
# define TILE_COLOR     0x808080ff
# define RAY_COLOR		0xffff00ff
# define COLOR_BLACK	0x000000ff
# define COLOR_RED		0xff0000ff

# define PLAYER_SIZE			0.2
# define PLAYER_STEP			0.2		// plane
# define PLAYER_FAST_STEP		0.6		// plane
# define PLAYER_ROTATION		2		// degrees
# define PLAYER_FAST_ROTATION	5		// degrees

int		run_app(t_ctx *ctx);
void	cub3d_key_callback(mlx_key_data_t keydata, void *param);
#endif