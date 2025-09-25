/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_texture_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:51:50 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/23 11:32:12 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map.h"
#include "libft.h"

static void	init_texture_sm(void (*f[])(t_parser *), t_parser *p)
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

static int	update_texture(char **words, t_map *map)
{
	int		success;
	char	*filename;

	success = 1;
	filename = ft_strtrim(words[1], " ");
	if (ft_strcmp(words[0], "NO") == 0)
		map->textures[NO_TEXTURE] = filename;
	else if (ft_strcmp(words[0], "SO") == 0)
		map->textures[SO_TEXTURE] = filename;
	else if (ft_strcmp(words[0], "WE") == 0)
		map->textures[WE_TEXTURE] = filename;
	else if (ft_strcmp(words[0], "EA") == 0)
		map->textures[EA_TEXTURE] = filename;
	else
		success = 0;
	free(words[1]);
	free(words[0]);
	free(words);
	if (!success)
		free(filename);
	return success;
}

int	map_is_texture_line(char *line, t_map *map)
{
	t_parser	p;
	void		(*f[10])(t_parser *);

	if (line == NULL)
		return (0);
	init_texture_sm(f, &p);
	p.cc = line;
	while (p.state > 0)
	{
		f[p.state](&p);
		p.cc++;
	}
	if (p.state == 0)
		return (update_texture(p.words, map));
	if (p.cw != NULL)
		free(p.cw);
	if (p.words != NULL)
		ft_dispose_split(p.words);
	return (0);
}
