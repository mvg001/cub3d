/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:07:20 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/22 12:02:40 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdint.h>

int32_t draw_abs_dif(int32_t a, int32_t b)
{
        if (a < b)
                return (b - a);
        return (a - b);
}

uint32_t draw_mix_colors(uint32_t c1, int w1, uint32_t c2, int w2)
{
        int		total;
        uint32_t	r;
        uint32_t	g;
        uint32_t	b;
        uint32_t        a;

        if (c1 == c2)
                return (c1);
        total = w1 + w2;
        if (w1 < 0 || w2 < 0 || total <= 0)
                return (c1);
        r = (((c1 >> 24) & 0xff) * w1 + ((c2 >> 24) & 0xff) * w2) / total;
        g = (((c1 >> 16) & 0xff) * w1 + ((c2 >> 16) & 0xff) * w2) / total;
        b = (((c1 >> 8) & 0xff) * w1 + ((c2 >> 8) & 0xff) * w2) / total;
        a = ((c1 & 0xff) * w1 + (c2 & 0xff) * w2) / total;
        return (a | (b << 8) | (g << 16) | (r << 24));
}
