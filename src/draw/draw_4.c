/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:03:18 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/11 19:15:26 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "draw.h"
#include <stdint.h>

static void	draw_points(mlx_image_t *img, t_point *center, int x, int y,
	uint32_t color)
{
	mlx_put_pixel(img, center->x + x, center->y + y, color);
	mlx_put_pixel(img, center->x - x, center->y + y, color);
	mlx_put_pixel(img, center->x + x, center->y - y, color);
	mlx_put_pixel(img, center->x - x, center->y - y, color);
	mlx_put_pixel(img, center->x + y, center->y + x, color);
	mlx_put_pixel(img, center->x - y, center->y + x, color);
	mlx_put_pixel(img, center->x + y, center->y - x, color);
	mlx_put_pixel(img, center->x - y, center->y - x, color);
}

static void	draw_lines(mlx_image_t *img, t_point *center, int x, int y,
	uint32_t color)
{
    t_point p1;
    t_point p2;
    
    p1.x = center->x - x;
    p1.y = center->y + y;
    p2.x = center->x + x;
    p2.y = p1.y;
    draw_line(img, &p1, &p2, color);
    p1.y = center->y - y;
    p2.y = p1.y;
    draw_line(img, &p1, &p2, color);
    p1.x = center->x - y;
    p1.y = center->y + x;
    p2.x = center->x + y;
    p2.y = p1.y;
    draw_line(img, &p1, &p2, color);
    p1.y = center->y - x;
    p2.y = p1.y;
    draw_line(img, &p1, &p2, color);
}

static int internal_draw(mlx_image_t *img, t_circle *cf, uint32_t color,
    void (*f)(mlx_image_t *, t_point *, int x, int y, uint32_t color))
{
	int	x;
	int y;
	int	d;
	
	x = 0;
	y = cf->radius;
	d = 3 - 2 * cf->radius;
	f(img, &cf->center, x, y, color);
	while (y >= x)
	{
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y);
		}
		else {
			d = d + 4 * x + 6;
		}
		x++;
		f(img, &cf->center, x, y, color);
	}
	return (1);
}

int draw_circumference(mlx_image_t *img, t_circle *cf, uint32_t color)
{
    return (internal_draw(img, cf, color, draw_points));
}

int draw_circle(mlx_image_t *img, t_circle *cf, uint32_t color)
{
    return (internal_draw(img, cf, color, draw_lines));
}