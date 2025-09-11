/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:27:35 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/11 15:10:52 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "cub3d.h"
#include "vec2d.h"
#include "libft.h"
#include <math.h>

t_player	*player_create(double xpos, double ypos, double dirx, double diry)
{
	t_player	*player;

	if (dirx == 0.0 && diry == 0.0)
		return (NULL);
	player = ft_calloc(1, sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->pos.x = xpos;
	player->pos.y = ypos;
	player->dir.x = dirx;
	player->dir.y = diry;
	vec2d_normalize(&player->dir);
	player->tg_half_fov = tan((FOV * M_PI) / 360.0);
	return (player);
}

void	player_destroy(t_player **player)
{
	if (player == NULL || *player == NULL)
		return ;
	free(*player);
	*player = NULL;
}

static int	get_player_dir(t_vec2d *dir, char char_dir)
{
	if (dir == NULL)
		return (0);
	dir->x = 0.0;
	dir->y = 0.0;
	if (char_dir == 'N')
		dir->y = -1.0;
	else if (char_dir == 'S')
		dir->y = 1.0;
	else if (char_dir == 'W')
		dir->x = -1.0;
	else if (char_dir == 'E')
		dir->x = 1.0;
	else
	 	return (0);
	return (1);
}

t_player	*player_create_char_dir(double xpos, double ypos, char cdir)
{
	t_vec2d	pdir;
	
	if (!get_player_dir(&pdir, cdir))
		return (NULL);
	return (player_create(xpos, ypos, pdir.x, pdir.y));
}