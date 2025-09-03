/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:13:58 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/03 10:31:47 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"
#include "libft.h"

t_map	*map_parse(char **lines, t_map *map)
{
    (void)lines;
    (void)map;
    return (NULL);
}

int	is_empty_line(char *line)
{
    if (line == NULL)
        return (0);
    while (*line)
    {
        if (*line != ' ' && *line != '\t')
            return (0);
        line++;
    }
    return (1);
}

int is_map_line(char *line)
{
    int     count;

    if (line == NULL)
        return (0);
    count = 0;
    while (*line != '\0')
    {
        if (*line != ' ' && *line != '0' && *line != '1')
            return (0);
        if (*line == '0' || *line == '1')
            count++;
        line++;
    }
    return (count > 0);
}
