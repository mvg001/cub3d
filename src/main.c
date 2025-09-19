/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:53:11 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/19 16:08:20 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"
#include "cub3d.h"
#include "libft.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_ctx	*ctx;

	if (ac != 2)
	{
		ft_dprintf(2, "Usage: %s filename.cub\n", av[0]);
		return (1);
	}
	ctx = ctx_create(av[1]);
	if (ctx == NULL)
		return (2);
	run_app(ctx);
	ctx_destroy(&ctx);
	return (0);
}