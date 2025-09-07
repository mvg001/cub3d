/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:54:52 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/06 22:27:20 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"

static char	*trim_right(char *line)
{
    int i;

    if (line == NULL)
        return (NULL);
    i = ft_strlen(line);
    while (--i >= 0)
        if (line[i] == ' ')
            line[i] = '\0';
    return (ft_strdup(line));
}

static int	adjust_lines(t_map *map)
{
    int		i;
    int		len;
    char	*l;

    i = -1;
    while (map->plane[++i] != NULL)
    {
        len = ft_strlen(map->plane[i]);
        if (len == map->n_columns)
            continue ;
        l = malloc(map->n_columns + 1);
        if (l == NULL)
            return (0);
        ft_memset(l, ' ', map->n_columns);
        l[map->n_columns] = '\0';
        ft_memcpy(l, map->plane[i], len);
        free(map->plane[i]);
        map->plane[i] = l;
    }
    return (1);
}

static int	count_players(t_map *map)
{
    int	i;
    int	j;
    int	count;

    count = 0;
    i = -1;
    while (++i < map->n_lines)
    {
        j = -1;
        while (++j < map->n_columns)
        {
            if (map->plane[i][j] == '\0')
                break ;
            if (ft_strchr("NSWE", map->plane[i][j]) != NULL)
                count++;
        }
    }
    return (count);
}

static t_map	*check_map(t_map *map)
{
    if (!is_texture_ok(map->so_texture) || !is_texture_ok(map->so_texture)
        || !is_texture_ok(map->we_texture) || !is_texture_ok(map->ea_texture))
        return (NULL);
    map->n_lines = ft_split_count(map->plane);
    map->n_columns = largest_line(map->plane);
    if (map->n_lines < 3 || map->n_columns < 3 
        || !adjust_lines(map) || count_players(map) != 1)
        return (NULL);
    return (map);
}

t_map	*map_parse(char **lines, t_map *map)
{
    int i;

    if (lines == NULL || *lines == NULL || map == NULL)
        return (NULL);
    i = -1; 
    while (lines[++i] != NULL)
    {
        if (is_empty_line(lines[i]) || is_texture_line(lines[i], map)
            || is_color_line(lines[i], map))
            continue;
        if (is_map_line(lines[i]))
            break ;
        ft_dprintf(2, "Error\nUnable to parse line %d\n", i);
        return (NULL);
    }
    while (lines[i] != NULL && is_map_line(lines[i]))
        map->plane = (char **)ptr_array_append((void **)map->plane,
        trim_right(lines[i++]));
    if (lines[i] != NULL)
    {
        ft_dprintf(2, "Error\nUnable to parse line %d\n", i);
        return (NULL);
    }
    return (check_map(map));
}
