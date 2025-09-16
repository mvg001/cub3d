/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:42:53 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/16 16:39:46 by mvassall         ###   ########.fr       */
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
	double	len;
	double	p_len;
}	t_ray;

t_ray	*ray_casting(t_player *player, double tg_fovh, t_map *map, int n_rays);
#endif