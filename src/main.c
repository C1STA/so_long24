/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:32:44 by wacista           #+#    #+#             */
/*   Updated: 2024/10/31 20:47:41 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *g)
{
	g->m.fd = 0;
	g->m.map = NULL;
	g->x.screen_y = 0;
	g->x.screen_x = 0;
	g->x.mlx = mlx_init();
	if (g->x.mlx)
	{
		mlx_get_screen_size(g->x.mlx, &g->x.screen_x, &g->x.screen_y);
		mlx_destroy_display(g->x.mlx);
		free(g->x.mlx);
	}
	g->x.mlx = NULL;
	g->m.exit = 0;
	g->m.item = 0;
	g->m.pos = 0;
}

int	main(int ac, char **av)
{
	t_game	*g;

	if (ac != 2)
		return (ft_printf("Error\n%s: \
accepts 1 arg, received %d\n", &av[0][2], ac - 1), 2);
	if (!isextension_valid(av))
		return (127);
	g = (t_game *)malloc(sizeof(t_game));
	if (!g)
		error_return(g, av, 1);
	init_struct(g);
	get_map(g, av);
	isrectangle(g, av);
	iswall(g, av);
	isitems(g, av);
	isplayable(g, av);
	printf("ok\n");
	free_game(g);
	return (0);
}
