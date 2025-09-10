/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:39:08 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/10 10:47:52 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "stdlib.h"

int	map_get_cell_d(t_map *map, double x, double y)
{
	int	i;
	int	j;

	if (map == NULL)
		return (-1);
	i = (int)y;
	j = (int)x;
	if (i < 0 || i >= map->n_lines || j < 0 || j >= map->n_columns)
		return (-1);
	return (map->plane[i][j]);
}
int	map_get_cell(t_map *map, t_vec2d *pos)
{
	if (map == NULL || pos == NULL)
		return (-1);
    return (map_get_cell_d(map, pos->x, pos->y));
}

int	map_is_cell_wall_d(t_map *map, double x, double y)
{
	if (map == NULL)
		return (-1);
	return (map_get_cell_d(map, x, y) != EMPTY_CHAR);
}

int	map_is_cell_wall(t_map *map, t_vec2d *pos)
{
	if (map == NULL || pos == NULL)
		return (-1);
    return (map_is_cell_wall_d(map, pos->x, pos->y));
}
