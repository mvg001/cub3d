/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:39:08 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/09 12:42:57 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "vec2d.h"

int	map_is_wall(t_map *map, t_vec2d *pos)
{
    return (map_is_wall_position(map, pos->x, pos->y));
}
