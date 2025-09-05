/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:38:53 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/04 15:10:33 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"
#include "libft.h"

static void init_color_sm(void (*f[])(t_parser *), t_parser *p)
{
    f[0] = NULL;
    f[1] = map_color1;
    f[2] = map_color2;
    f[3] = map_color3;
    f[4] = map_color4;
    f[5] = map_color5;
    p->state = 1;
    p->cw = NULL;
    p->words = NULL;
}

static int	update_color(char **words, t_map *map)
{
    int			color[3];
    int			i;
    uint32_t	n;

    if (ft_split_count(words) != 4)
        return (0);
    i = 0;
    while (i < 3)
    {
        if (!ft_is_int(words[i+1]))
            return (0);
        color[i] = ft_atoi(words[i+1]);
        if (color[i] < 0 || color[i] > 255)
            return (0);
    }
    n = (color[0] << 16) | (color[1] << 8) | color[0];
    if (words[0][0] == 'C')
        map->ceiling_color = n;
    else if (words[0][0] == 'F')
        map->floor_color = n;
    else
        return (0);
    return (1);
}

int	is_color_line(char *line, t_map *map)
{
    t_parser	p;
    void		(*f[6])(t_parser *);
    int			success;
    
    if (line == NULL)
        return (0);
    init_color_sm(f, &p);
    p.cc = line;
    while (p.state > 0)
    {
        f[p.state](&p);
        p.cc++;
    }
    success = 0;
    if (p.state == 0)
        success = update_color(p.words, map);
    if (p.cw != NULL)
        free(p.cw);
    if (p.words != NULL)
        ft_dispose_split(p.words);
    return (success);
}