/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:27:35 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/01 14:54:55 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "vec2d.h"
#include "libft.h"

t_player	*player_create(double xpos, double ypos, double dirx, double diry)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->pos.x = xpos;
	player->pos.y = ypos;
	player->dir.x = dirx;
	player->dir.y = diry;
	vec2d_normalize(&player->dir);
	return (player);
}

void	player_destroy(t_player **player)
{
	if (player == NULL || *player == NULL)
		return ;
	free(*player);
	*player = NULL;
}

