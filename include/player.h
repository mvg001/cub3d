/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:23:51 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/11 12:46:18 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "vec2d.h"

typedef struct s_player
{
	t_vec2d	pos;
	t_vec2d	dir;
	double	tg_half_fov;
}	t_player;

t_player	*player_create(double posx, double posy, double dirx, double diry);
t_player	*player_create_char_dir(double xpos, double ypos, char cdir);
void	    player_destroy(t_player **player);
#endif
