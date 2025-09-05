/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:13:58 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/05 15:55:17 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"
#include "libft.h"

int	is_empty_line(char *line)
{
    if (line == NULL)
        return (1);
    while (*line)
    {
        if (*line != ' ' && *line != '\t')
            return (0);
        line++;
    }
    return (1);
}

int	is_map_line(char *line)
{
    if (line == NULL)
        return (0);
    while (*line == ' ')
        line++;
    if (*line == '1')
    {
        line++;
        while (*line && ft_strchr(" 01NSWE", *line) != NULL)
            line++;
        if (*line == '\0')
            return (1);
    }
    return (0);
}

void	map_print(t_map *map)
{
    int	i;
    ft_putendl_fd("\n### MAP:", 2);
    ft_dprintf(2, "NO: '%s'\n", map->no_texture);
    ft_dprintf(2, "SO: '%s'\n", map->so_texture);
    ft_dprintf(2, "WE: '%s'\n", map->we_texture);
    ft_dprintf(2, "EA: '%s'\n", map->ea_texture);
    ft_dprintf(2, "F: %x\n", map->floor_color);
    ft_dprintf(2, "C: %s\n", map->ceiling_color);
    ft_dprintf(2, "n_lines: %d\n", map->n_lines);
    ft_dprintf(2, "n_columns: %d\n", map->n_columns);
    if (map->plane != NULL)
    {
        i = -1;
        ft_dprintf(2, "plane:\n");
        while (map->plane[++i] != NULL)
            ft_dprintf(2, "%d: '%s'\n", i, map->plane[i]);
    }
    ft_putendl_fd("plane: empty", 2);
}
