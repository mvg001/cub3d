/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user1 <user1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:58:02 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/18 23:33:56 by user1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "libft.h"
#include "map.h"
#include "player.h"
#include "ray.h"
#include "vec2d.h"

static void	ray_calculate(t_ray *ray, t_player *player, t_map *map)
{
	double	tmin;
	double	t;
	t_ray	r;
	
	tmin = DBL_MAX;
	if (ray->rdir.y != 0.0)
	{
		r = *ray;
		t = ray_horizontals(&r, player, map);
		if (t < tmin)
		{
			*ray = r;
			tmin = t;
		}
	}
	if (ray->rdir.x != 0.0)
	{
		r = *ray;
		t = ray_verticals(&r, player, map);
		if (t < tmin)
		{
			*ray = r;
			tmin = t;
		}
	}
}

t_ray	*ray_casting(t_player *player, double tg_fovh, t_map *map, int n_rays)
{
	t_ray	*rays;
	t_vec2d	pdir;
	int		i;
	double	f;

	if (player == NULL || map == NULL || tg_fovh <= 0 || n_rays <= 0)
		return (NULL);
	rays = ft_calloc(n_rays, sizeof(t_ray));
	if (rays == NULL)
		return (NULL);
	pdir.x = -player->dir.y * tg_fovh;
	pdir.y = player->dir.x * tg_fovh;
	i = -1;
	while (++i < n_rays)
	{
		f = (2.0 * i) / (n_rays - 1.0) - 1.0;
		rays[i].rdir.x = player->dir.x + f * pdir.x;
		rays[i].rdir.y = player->dir.y + f * pdir.y;
		vec2d_normalize(&rays[i].rdir);
		ray_calculate(rays + i, player, map);
	}
	return (rays);
}
