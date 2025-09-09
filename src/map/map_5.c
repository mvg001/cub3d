/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:39:08 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/09 15:05:11 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "vec2d.h"

int	map_get_cell_char(t_map *map, double x, double y)
{
	int	i;
	int	j;

	i = (int)y;
	j = (int)x;
	if (i < 0 || i >= map->n_lines || j < 0 || j >= map->n_columns)
		return (-1);
	return (map->plane[i][j]);
}
int	map_get_cell(t_map *map, t_vec2d *pos)
{
    return (map_get_cell_char(map, pos->x, pos->y));
}

int	map_is_wall_position(t_map *map, double x, double y)
{
	return (map_get_cell_char(map, x, y) != EMPTY_CHAR);
}

int	map_is_wall(t_map *map, t_vec2d *pos)
{
    return (map_is_wall_position(map, pos->x, pos->y));
}
