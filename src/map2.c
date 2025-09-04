/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:13:58 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/04 16:01:02 by mvassall         ###   ########.fr       */
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
        return (1);
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
    if (line == NULL)
        return (0);
    while (*line == ' ')
        line++;
    if (*line == '1')
    {
        line++;
        while (ft_strchr(" 01NSWE", *line) != NULL)
            line++;
        if (*line == '\0' || *line == '\n')
            return (1);
    }
    return (0);
}
