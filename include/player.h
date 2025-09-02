/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:23:51 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/01 14:45:22 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "vec2d.h"

typedef struct s_player
{
	t_vec2d	pos;
	t_vec2d	dir;
}	t_player;
t_player	*player_create(double xpos, double ypos, double dirx, double diry);
void	    player_destroy(t_player **player);
#endif
