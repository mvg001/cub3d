/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user1 <user1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:26:03 by user1             #+#    #+#             */
/*   Updated: 2025/09/18 23:56:38 by user1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <math.h>
#include "map.h"
#include "ray.h"

static int	ray_horizontal_p(t_ray *ray, t_player *player, t_map *map)
{
	double	y;
	double	x;
	double	delta;

	delta = ray->rdir.x / ray->rdir.y;
	y = floor(player->pos.y) + 1.0;
	x = player->pos.x + delta * (y - player->pos.y);
	while (y < map->n_lines && map_get_cell_d(map, x, y) == EMPTY_CHAR)
	{
		y += 1.0;
		x += delta;
	}
	if (y < map->n_lines && map_get_cell_d(map, x, y) == WALL_CHAR)
	{
		ray->colision.x = x;
		ray->colision.y = y;
		ray->len = (y - player->pos.y) / ray->rdir.y;
		return (1);
	}
	return (0);
}

static int	ray_horizontal_n(t_ray *ray, t_player *player, t_map *map)
{
	double	y;
	double	x;
	double	delta;

	delta = ray->rdir.x / ray->rdir.y;
	y = floor(player->pos.y);
	x = player->pos.x + delta * (y - player->pos.y);
	while (y > 0 && map_get_cell_d(map, x, y - 1.0) == EMPTY_CHAR)
	{
		y -= 1.0;
		x -= delta;
	}
	if (y > 0 && map_get_cell_d(map, x, y - 1.0) == WALL_CHAR)
	{
		ray->colision.x = x;
		ray->colision.y = y;
		ray->len = (y - player->pos.y) / ray->rdir.y;
		return (1);
	}
	return (0);
}

double	ray_horizontals(t_ray *ray, t_player *player, t_map *map)
{
	if ((ray->rdir.y > 0.0 && ray_horizontal_p(ray, player, map))
		|| (ray->rdir.y < 0.0 && ray_horizontal_n(ray, player, map)))
	{
		ray->p_len = ray->len * 
			(ray->rdir.x * player->dir.x + ray->rdir.y * player->dir.y);		
		return (ray->len);
	}
	return (DBL_MAX);
}
