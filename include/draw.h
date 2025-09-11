/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:51:55 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/11 19:16:10 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

#include <stdint.h>
#include "MLX42/MLX42.h"

typedef struct	s_point
{
    int32_t		x;
    int32_t		y;
    uint32_t	color;
}	t_point;

typedef struct s_plot
{
	int32_t	dx;
	int32_t	dy;
	int32_t	inc;
	int32_t	d;
	int32_t	x;
	int32_t	y;
}	t_plot;

typedef struct	s_rectangle
{
	t_point		pos;
	uint32_t	width;
	uint32_t	height;
}	t_rectangle;

typedef struct	s_circle
{
	t_point		center;
	uint32_t	radius;
}	t_circle;

int32_t		draw_abs_dif(int32_t a, int32_t b);
int			draw_line_gradient(mlx_image_t *img, t_point *p0, t_point *p1);
int			draw_line(mlx_image_t *img, t_point *p0, t_point *p1, uint32_t color);
uint32_t	draw_mix_colors(uint32_t c1, int w1, uint32_t c2, int w2);
int			draw_rectangle(mlx_image_t *img, t_rectangle *rect, uint32_t color);
int 		draw_circumference(mlx_image_t *img, t_circle *cf,
	uint32_t color);
int 		draw_circle(mlx_image_t *img, t_circle *cf, uint32_t color);
#endif