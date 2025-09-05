/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:54:52 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/05 16:04:41 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "map.h"

static int	check_texture(char *filename)
{
    int	fd;

    if (filename == NULL)
        return (0);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_putendl_fd("ERROR", 2);
        perror(filename);
        return (0);
    }
    close(fd);
    return (1);
}

static t_map	*check_map(t_map *map)
{
    if (!check_texture(map->so_texture) || !check_texture(map->so_texture)
        || !check_texture(map->we_texture) || check_texture(map->ea_texture))
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
        ft_strdup(lines[i++]));
    if (lines[i] != NULL)
    {
        ft_dprintf(2, "Error\nUnable to parse line %d\n", i);
        return (NULL);
    }
    return (check_map(map));
}
