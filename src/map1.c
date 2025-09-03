/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:40:49 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/03 10:31:05 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include "map.h"
#include "libft.h"

void	map_destroy(t_map **map)
{
    t_map   *m;

    if (map == NULL || *map == NULL)
        return ;
    m = *map;
    if (m->no_texture != NULL)
        free(m->no_texture);
    if (m->so_texture != NULL)
        free(m->so_texture);
    if (m->we_texture != NULL)
        free(m->we_texture);
    if (m->ea_texture != NULL)
        free(m->ea_texture);
    if (m->plane != NULL)
        ft_dispose_split(m->plane);
    *map = NULL;
}

char	**read_all_lines(int fd, int buffer_size)
{
    t_buf   *rbuf;
    void    **lines;
    char    *line;
    char    *pnl;

    rbuf = gnl_alloc_buf(buffer_size);
    if (rbuf == NULL)
        return (NULL);
    lines = NULL;
    while (1)
    {
        line = gnl_getline(fd, rbuf);
        if (line == NULL)
            break ;
        pnl = ft_strchr(line, '\n');
        if (pnl != NULL)
            *pnl = '\0';
        lines = ptr_array_append(lines, line);
    }
    gnl_dispose(rbuf);
    return ((char **)lines);
}

t_map	*map_readfd(int fd)
{
    t_map	*map;
    char    **lines;

    lines = read_all_lines(fd, MAP_BUFFER_SIZE);
    if (lines == NULL)
        return (NULL);
    map = ft_calloc(1, sizeof(t_map));
    if (map == NULL)
    {
        ft_dispose_split(lines);
        return (NULL);
    }
    if (map_parse(lines, map) != map)
    {
        map_destroy(&map);
        ft_dispose_split(lines);
        return (NULL);
    }
    ft_dispose_split(lines);
    return (map);
}

t_map	*map_read(char *filename)
{
    t_map	*map;
    int		fd;

    if (filename == NULL)
    {
        ft_dprintf(2, "Error\nNULL filename\n");
        return (NULL);
    }
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_dprintf(2, "Error\n");
        perror(filename);
        return (NULL);
    }
    map = map_readfd(fd);
    close(fd);
    return (map);
}
