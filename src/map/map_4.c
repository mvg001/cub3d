/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 22:15:08 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/09 12:30:05 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

int	map_set_player(t_map *map)
{
	int	jx;
	int iy;
	int	found;

	if (map == NULL)
		return (0);
	found = 0;
	iy = -1;
	while (!found && ++iy < map->n_lines)
	{
		jx = -1;
		while (!found && ++jx < map->n_columns)
			found = ft_strchr("NSWE", map->plane[iy][jx]) != NULL;
	}
	if (!found)
		return (ft_dprintf(2, "Error\nProcessing player position\n"), 0);
	map->player_init_y = iy;
	map->player_init_x = jx;
	map->player_init_dir = map->plane[iy][jx];
	map->plane[iy][jx] = '0';
	return (1);
}

t_map	*map_check(t_map *map)
{
	if (!map_is_texture_ok(map->so_texture)
		|| !map_is_texture_ok(map->so_texture)
		|| !map_is_texture_ok(map->we_texture)
		|| !map_is_texture_ok(map->ea_texture))
		return (NULL);
	if (!map_check_size(map))
		return (NULL);
	if (!map_adjust_lines(map))
		return (NULL);
	if (map_count_players(map) != 1 || !map_set_player(map))
		return (NULL);
	if (!map_walls_check(map))
		return (NULL);
	return (map);
}

static int	flood(t_map *map, int x, int y)
{
	if (y < 0 || y >= map->n_lines || x < 0 || x >= map->n_columns)
		return (0);
	if (map->plane[y][x] != '1' && map->plane[y][x] != '.')
	{
		map->plane[y][x] = '.';
		if (!flood(map, x,  y-1)
			|| !flood(map, x,  y+1)
			|| !flood(map, x-1, y)
			|| !flood(map, x+1, y))
			return (0);
	}
	return (1);
}

int	map_walls_check(t_map *map)
{
	if (map == NULL)
		return (0);
	if (!flood(map, map->player_init_x, map->player_init_y))
	{
		ft_dprintf(2, "Error\nMap not surrounded by walls\n");
		return (0);
	}
	return (1);
}

int	map_is_wall_position(t_map *map, double x, double y)
{
	int	i;
	int	j;

	i = (int)y;
	j = (int)x;
	if (i < 0 || i >= map->n_lines || j < 0 || j >= map->n_columns)
		return (0);
	return (map->plane[i][j] != '.');
}