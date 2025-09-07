/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:54:52 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/07 14:59:31 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map.h"

char	*map_trim_right(char *line)
{
    int i;

    if (line == NULL)
        return (NULL);
    i = ft_strlen(line) - 1;
    while (i >= 0 && line[i] != '1')
    {
        if (line[i] == ' ' || line[i] == '0')
            line[i] = '\0';
        i--;
    }
    return (ft_strdup(line));
}

int	map_adjust_lines(t_map *map)
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
        {
            ft_dprintf(2, "Error\nUnable to adjust columns\n");
            return (0);
        }
        ft_memset(l, ' ', map->n_columns);
        l[map->n_columns] = '\0';
        ft_memcpy(l, map->plane[i], len);
        free(map->plane[i]);
        map->plane[i] = l;
    }
    return (1);
}

int	map_count_players(t_map *map)
{
    int	i;
    int	j;
    int	count;

    if (map == NULL)
        return (0);
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
    if (count != 1)
        ft_dprintf(2, "Error\nInvalid number of players %d\n", count);
    return (count);
}

t_map	*map_parse(char **lines, t_map *map)
{
    int i;
    char *aux;

    if (lines == NULL || *lines == NULL || map == NULL)
        return (NULL);
    i = -1; 
    while (lines[++i] != NULL)
    {
        if (map_is_empty_line(lines[i])
            || map_is_texture_line(lines[i], map)
            || map_is_color_line(lines[i], map))
            continue;
        if (map_is_map_line(lines[i]))
            break ;
        ft_dprintf(2, "Error\nUnable to parse line %d\n", i);
        return (NULL);
    }
    while (lines[i] != NULL && map_is_map_line(lines[i]))
    {
        aux = map_trim_right(lines[i]);
        map->plane = (char **)ptr_array_append((void **)map->plane, aux);
        i++;
    }
    if (lines[i] != NULL)
    {
        ft_dprintf(2, "Error\nUnable to parse line %d\n", i);
        return (NULL);
    }
    return (map_check(map));
}
