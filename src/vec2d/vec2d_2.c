/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:34:53 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/10 12:24:54 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec2d.h"
#include "math.h"

t_rotation	vec2d_gen_rotation(double angle_rad)
{
    double *m;

    m = ft_calloc(4, sizeof(double));
    if (m == NULL)
        return (NULL);
    m[0] = cos(angle_rad);
    m[2] = sin(angle_rad);
    m[1] = -m[2];
    m[3] = m[0];
    return (m);
}

t_rotation	vec2d_gen_rotation_degree(double angle_degrees)
{
    return (vec2d_gen_rotation(angle_degrees * M_PI / 180.0));
}

int		vec2d_rotate(t_vec2d *v, t_rotation r)
{
    double	aux[2];

    if (v == NULL || r == NULL)
        return (0);
    aux[0] = r[0] * v->x + r[1] * v->y;
    aux[1] = r[2] * v->x + r[3] * v->y;
    v->x = aux[0];
    v->y = aux[1];
    return (1);
}