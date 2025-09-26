/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:53:56 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/26 12:21:07 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#include "ctx.h"
#include <stdint.h>

# define FOV			66		// degrees
# define WINDOW_WIDTH	768		// pixels
# define WINDOW_HEIGHT	512		// pixels

# define COLOR_BLACK	0x000000ff
# define COLOR_RED		0xff0000ff
# define COLOR_GRAY		0x808080ff

# define PLAYER_SIZE			0.2
# define PLAYER_STEP			0.2		// plane
# define PLAYER_FAST_STEP		0.6		// plane
# define PLAYER_ROTATION		2		// degrees
# define PLAYER_FAST_ROTATION	5		// degrees

# define FPS_STATS_N_SAMPLES	60
typedef struct	s_fps_stats
{
	int	samples[FPS_STATS_N_SAMPLES];
	int	n;
}	t_fps_stats;

typedef struct	s_slice
{
	uint32_t	m;
	uint32_t	na;
	uint32_t	nb;
	uint32_t	la;
	uint32_t	lb;
	uint32_t	wa;
	uint32_t	wb;
	uint32_t	s[4];
	uint32_t	c[4];
	uint32_t	i;
	uint32_t	j;
}	t_slice;

int		run_app(t_ctx *ctx);
void	cub3d_key_callback(mlx_key_data_t keydata, void *param);
void	cub3d_display_3d(void *param);
void	cub3d_print_fps(mlx_t *mlx);
int		cub3d_slice_texture(mlx_texture_t *txt, uint32_t txt_col,
	uint32_t len, uint32_t *col_pixes);
#endif