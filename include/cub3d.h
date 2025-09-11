/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:53:56 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/11 16:06:07 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#include "ctx.h"

# define FOV			66	// degrees
# define WINDOW_WIDTH	1024	// pixels
# define WINDOW_HEIGHT	768	// pixels
# define TILE_COLOR     0x808080ff
# define COLOR_BLACK	0x000000ff
# define COLOR_RED		0xff0000ff
int	run_app(t_ctx *ctx);
#endif