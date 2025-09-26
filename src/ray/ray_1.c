/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:58:02 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/26 11:41:29 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "libft.h"
#include "map.h"
#include "player.h"
#include "ray.h"
#include "vec2d.h"

static void	get_hv_rays(t_ray *rh, t_ray *rv, t_player *player, t_map *map)
{
	rh->len = DBL_MAX;
	if (rh->rdir.y != 0.0)
		ray_horizontals(rh, player, map);
	rv->len = DBL_MAX;
	if (rv->rdir.x != 0.0)
		ray_verticals(rv, player, map);
}

static void	ray_calculate(t_ray *ray, t_player *player, t_map *map)
{
	t_ray	rh;
	t_ray	rv;

	rh = *ray;
	rv = *ray;
	get_hv_rays(&rh, &rv, player, map);
	if (rh.len < rv.len)
	{
		*ray = rh;
		ray->face = NORTH;
		if (ray->rdir.y > 0.0)
			ray->face = SOUTH;
		return ;
	}
	*ray = rv;
	ray->face = WEST;
	if (ray->rdir.x > 0.0)
		ray->face = EAST;
}

t_ray	*ray_casting(t_player *player, t_map *map, int n_rays)
{
	t_ray	*rays;
	t_vec2d	pdir;
	int		i;
	double	f;

	if (player == NULL || map == NULL || n_rays <= 0)
		return (NULL);
	rays = ft_calloc(n_rays, sizeof(t_ray));
	if (rays == NULL)
		return (NULL);
	pdir.x = -player->dir.y * player->tg_half_fov;
	pdir.y = player->dir.x * player->tg_half_fov;
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
