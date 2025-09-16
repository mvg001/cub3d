/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:58:02 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/16 17:43:36 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"
#include "player.h"
#include "ray.h"
#include "vec2d.h"
#include <float.h>
#include <math.h>

static double	ray_horizontal(t_ray *ray, t_player *player, t_map *map)
{
	double	t0;
	double	t;
	int		i;
	int		inc;
	t_vec2d	h;

	inc = 1;
	if (ray->rdir.y < 0.0)
		inc = -1;
	i = 0;
	t0 = (floor(player->pos.y) - player->pos.y) / ray->rdir.y;
	h.x = player->pos.x + ray->rdir.x * t0;
	h.y = player->pos.y + ray->rdir.y * t0;
	while (map_is_cell_wall(map, &h))
	{
		i += inc;
		t = t0 + (double)i / 
	}
	
}

static int	ray_calculate(t_ray *ray, t_player *player, t_map *map)
{
	double	th;
	double	tv;

	th = DBL_MAX;
	if (ray->rdir.y != 0.0)
		th = ray_horizontal(ray, player, map);
	tv = DBL_MAX;
	
	return (1);
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
