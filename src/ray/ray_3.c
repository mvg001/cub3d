/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:22:39 by user1             #+#    #+#             */
/*   Updated: 2025/09/19 15:35:23 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <math.h>
#include "ray.h"

static int	ray_verticals_p(t_ray *ray, t_player *player, t_map *map)
{
	double	y;
	double	x;
	double	delta;

	delta = ray->rdir.y / ray->rdir.x;
	x = floor(player->pos.x) + 1.0;
	y = player->pos.y + delta * (x - player->pos.x);
	while (x < map->n_columns && map_get_cell_d(map, x, y) == EMPTY_CHAR)
	{
		x += 1.0;
		y += delta;
	}
	if (x < map->n_columns && map_get_cell_d(map, x, y) == WALL_CHAR)
	{
		ray->colision.x = x;
		ray->colision.y = y;
		ray->len = (x - player->pos.x) / ray->rdir.x;
		return (1);
	}
	return (0);
}

static int	ray_verticals_n(t_ray *ray, t_player *player, t_map *map)
{
	double	y;
	double	x;
	double	delta;

	delta = ray->rdir.y / ray->rdir.x;
	x = floor(player->pos.x);
	y = player->pos.y + delta * (x - player->pos.x);
	while (x > 0 && map_get_cell_d(map, x - 1.0, y) == EMPTY_CHAR)
	{
		x -= 1.0;
		y -= delta;
	}
	if (x > 0 && map_get_cell_d(map, x - 1.0, y) == WALL_CHAR)
	{
		ray->colision.x = x;
		ray->colision.y = y;
		ray->len = (x - player->pos.x) / ray->rdir.x;
		return (1);
	}
	return (0);
}

double	ray_verticals(t_ray *ray, t_player *player, t_map *map)
{
	if ((ray->rdir.x > 0.0 && ray_verticals_p(ray, player, map))
		|| (ray->rdir.x < 0.0 && ray_verticals_n(ray, player, map)))
	{
		ray->p_len = ray->len * 
			(ray->rdir.x * player->dir.x + ray->rdir.y * player->dir.y);
		return (ray->len);
	}
	return (DBL_MAX);
}
