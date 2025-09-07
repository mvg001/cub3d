/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 22:15:08 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/07 20:07:08 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include "player.h"

int	map_check_size(t_map *map)
{
	map->n_lines = ft_split_count(map->plane);
	map->n_columns = map_largest_line(map->plane);
	if (map->n_lines >= 3 && map->n_columns >= 3)
		return (1);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Map too small", 2);
	return (0);	
}

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
	if (map_count_players(map) != 1)
		return (NULL);
	if (!map_set_player(map))
		return (NULL);
	return (map);
}
