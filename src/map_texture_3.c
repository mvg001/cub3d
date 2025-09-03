/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:51:50 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/03 16:08:41 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"
#include "libft.h"

static void	init(void (*f[])(t_parser *), t_parser *p)
{
	f[0] = NULL;
	f[1] = map_texture_1;
	f[2] = map_texture_2;
	f[3] = map_texture_3;
	f[4] = map_texture_4;
	f[5] = map_texture_5;
	f[6] = map_texture_6;
	f[7] = map_texture_7;
	f[8] = map_texture_8;
	f[9] = map_texture_9;
	p->state = 1;
	p->cw = NULL;
	p->words = NULL;
}

static int update_texture(char **words, t_map *map)
{
	int success;

	success = 1;
	if (ft_strcmp(words[0], "NO"))
		map->no_texture = words[1];
	else if (ft_strcmp(words[0], "SO"))
		map->so_texture = words[1];
	else if (ft_strcmp(words[0], "WE"))
		map->we_texture = words[1];
	else if (ft_strcmp(words[0], "EA"))
		map->we_texture = words[1];
	else
	{
		success = 0;
		ft_dprintf(2, "Error\nUnable to parse texture configuration '%s %s'\n",
			words[0], words[1]);
	}
	return success;
}

int	parse_texture_line(char *line, t_map *map)
{
	t_parser	p;
	void		(*f[10])(t_parser *);
	int			success;

	if (line == NULL)
		return (0);
	init(f, &p);
	p.cc = line;
	while (p.state > 0)
	{
		f[p.state](&p);
		p.cc++;
	}
	if (p.state < 0)
		success = 0;
	else
		success = update_texture(p.words, map);

	return (success);
}
