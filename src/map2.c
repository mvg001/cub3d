/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:13:58 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/02 16:55:48 by mvassall         ###   ########.fr       */
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
    char *p;

    if (line == NULL)
        return (0);
    p = line;
    while (*p)
    {
        if (*p != ' ' && *p != '\n' && *p != '\t')
            return (0);
        p++;
    }
    return (1);
}

int is_map_line(char *line)
{
    char    *p;
    int     count;

    if (line == NULL)
        return (0);
    p = line;
    count = 0;
    while (*p != '\0')
    {
        if (*p != ' ' && *p != '0' && *p != '1')
            return (0);
        if (*p == '0' || *p == '1')
            count++;
        p++;
    }
    return (count > 0);
}
