/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:42:53 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/26 11:40:36 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "vec2d.h"
#include "map.h"
#include "player.h"

typedef struct	s_ray
{
	t_vec2d	rdir;
	t_vec2d	colision;
	t_tags	face;
	double	len;
	double	p_len;
}	t_ray;

t_ray	*ray_casting(t_player *player, t_map *map, int n_rays);
double	ray_horizontals(t_ray *ray, t_player *player, t_map *map);
double	ray_verticals(t_ray *ray, t_player *player, t_map *map);
#endif