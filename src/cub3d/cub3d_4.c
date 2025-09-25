/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:15:17 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/25 15:29:18 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3d.h"
#include <stdint.h>

static uint32_t	gcd(uint32_t a, uint32_t b)
{
	uint32_t	r;

	r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return (b);
}

static void	calc_weights(uint32_t *a, uint32_t *b)
{
	uint32_t	mmc;
	
	mmc = ((uint64_t)(*a) * (uint64_t)(*b)) / gcd(*a,*b);
	*a = mmc / *a;
	*b = mmc / *b;
}

static void	get_txt_pix(mlx_texture_t *txt, uint32_t lin, uint32_t col, uint32_t *rgb)
{
	uint32_t	c;
	
	c = (txt->pixels[lin * txt->width + col]);
	
}


int	cub3d_slice_texture(mlx_texture_t *txt, uint32_t col,
	uint32_t len, uint32_t *col_pixes)
{
	uint32_t	wa;
	uint32_t	wb;
	uint32_t	i;
	uint32_t	j;

	if (!txt || !col_pixes || col >= txt->width || len > txt->height)
		return (0);
	wa = txt->height;
	wb = len;
	calc_weights(&wa, &wb);
	
	return (1);
}