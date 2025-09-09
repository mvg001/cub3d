/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:13:58 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/09 12:48:47 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "map.h"
#include "libft.h"

int	map_is_empty_line(char *line)
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

int	map_is_map_line(char *line)
{
    char    *p;
    int     count1;

    if (line == NULL)
        return (0);
    count1 = 0;
    p = line;
    while (*p == ' ')
        p++;
    if (*p == '1')
    {
        p++;
        count1++;
        while (*p && ft_strchr(" 01NSWE", *p) != NULL)
        {
            if (*p == '1')
                count1++;    
            p++;
        }
        if (*p == '\0')
            return (count1 > 1);
    }
    return (0);
}

int	map_print(t_map *map)
{
    int	i;

    if (map == NULL)
        return (0);
    ft_putendl_fd("\n### MAP:", 2);
    ft_dprintf(2, "NO: '%s'\nSO: '%s'\n", map->no_texture, map->so_texture);
    ft_dprintf(2, "WE: '%s'\nEA: '%s'\n", map->we_texture, map->ea_texture);
    ft_dprintf(2, "F: %x\nC: %x\n", map->floor_color, map->ceiling_color);
    ft_dprintf(2, "n_lines: %d\nn_columns: %d\n", map->n_lines, map->n_columns);
    ft_dprintf(2, "player_init_x: %d\n", map->player_init_x);
    ft_dprintf(2, "player_init_y: %d\n", map->player_init_y);
    ft_dprintf(2, "player_init_dir: %c\n", map->player_init_dir);
    if (map->plane == NULL)
        return (ft_putendl_fd("plane: empty", 2), 0);
    i = -1;
    ft_dprintf(2, "plane:\n");
    while (map->plane[++i] != NULL)
        if (i < 10)
            ft_dprintf(2, " %d: '%s'\n", i, map->plane[i]);
        else
            ft_dprintf(2, "%d: '%s'\n", i, map->plane[i]);
    return (1);
}

int	map_is_texture_ok(char *filename)
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

int	map_largest_line(char **lines)
{
    int i;
    int len;
    int llen;

    if (lines == NULL)
        return (-1);
    i = -1;
    llen = 0;
    while (lines[++i] != NULL)
    {
        len = ft_strlen(lines[i]);
        if (len > llen)
            llen = len;
    }
    return (llen);
}
