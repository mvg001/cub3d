/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user1 <user1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:15:17 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/25 18:29:00 by user1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3d.h"
#include "libft.h"
#include <stdint.h>

static void	get_txt_pix(mlx_texture_t *txt, uint32_t lin, uint32_t col, uint32_t *rgba)
{
	uint32_t	c;
	
	c = (txt->pixels[lin * txt->width + col]);
	rgba[0] = c & 0xff;
	rgba[1] = (c >> 8) & 0xff;
	rgba[2] = (c >> 16) & 0xff;
	rgba[3] = (c >> 24) & 0xff;
}

static uint32_t	calculate_pix(uint32_t *rgba, uint32_t w)
{
	uint32_t	wh;
	int			i;

	i = -1;
	wh = w / 2;
	while (++i < 4)
		rgba[i] = (rgba[i] + wh) / w;
	return ((rgba[0] & 0xff) | ((rgba[1] & 0xff) << 8) | ((rgba[2] & 0xff) << 16)
		| ((rgba[3] & 0xff) << 24));
}

static void	add(uint32_t *s, uint32_t *c)
{
	int	i;

	i = -1;
	while (++i < 4)
		s[i] += c[i];
}

static void	init_p(uint32_t na, uint32_t nb, t_slice *p)
{
	uint64_t	mmc;
	uint32_t	r;

	ft_bzero(p, sizeof(t_slice));
	p->na = na;
	p->nb = nb;
	mmc = ((uint64_t)(na) * (uint64_t)(nb));
	r = na % nb;
	while (r != 0)
	{
		na = nb;
		nb = r;
		r = na % nb;
	}
	p->m = mmc / nb;
	p->la = p->m / p->na;
	p->lb = p->m / p->nb;
	p->wa = p->la;
	p->wb = p->lb;
}

int	cub3d_slice_texture(mlx_texture_t *txt, uint32_t src_col,
	uint32_t len, uint32_t *col_pixes)
{
	t_slice	p;

	if (txt == NULL || col_pixes == NULL || src_col >= txt->width
		|| txt->height == 0 || len > txt->height || len == 0)
		return (0);
	init_p(txt->height, len, &p);
	get_txt_pix(txt, p.i, src_col, p.c);
	while (p.j < len)
	{
		if (p.wa == 0)
		{
			p.wa = p.la;
			get_txt_pix(txt, ++p.i, src_col, p.c);
		}
		if (p.wb == 0)
		{
			col_pixes[p.j++] = calculate_pix(p.s, p.lb);
			ft_bzero(p.s, 4 * sizeof(uint32_t));
			p.wb = p.lb;
		}
		add(p.s, p.c);
		p.wa--;
		p.wb--; 
	}
	return (1);
}
