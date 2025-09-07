/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:13:58 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/06 22:34:44 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
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
    if (map->plane == NULL)
    {
        ft_putendl_fd("plane: empty", 2);
        return ;
    }
    i = -1;
    ft_dprintf(2, "plane:\n");
    while (map->plane[++i] != NULL)
        ft_dprintf(2, "%d: '%s'\n", i, map->plane[i]);
}

int	is_texture_ok(char *filename)
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

int	largest_line(char **lines)
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
