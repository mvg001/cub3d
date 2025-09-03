/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:02:10 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/03 13:35:44 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"

int parse_texture_line(char *line, t_map *map)
{
    t_parser    p;
    void (*f[])(t_parser *) = {
        NULL, map_texture_1, map_texture_2, map_texture_3,
        map_texture_4, map_texture_5,
    };
    p.state = 1;
    p.cc = line;
    p.cw = NULL;
    p.words = NULL;
    while (p.state > 0)
        f[p.state](&p);
    if (p.state == 0)
    {
        
    }
}
