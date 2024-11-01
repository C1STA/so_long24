/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:32:44 by wacista           #+#    #+#             */
/*   Updated: 2024/11/01 19:29:11 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx(t_game *g, char **av)
{
	g->x.screen_x = 0;
	g->x.screen_y = 0;
	g->x.mlx = mlx_init();
	if (!g->x.mlx)
		error_return(g, av, 1);
	mlx_get_screen_size(g->x.mlx, &g->x.screen_x, &g->x.screen_y);
	g->x.img_pxl = IMG_SIZE;
	g->x.img_0 = NULL;
	g->x.img_1 = NULL;
	g->x.img_e = NULL;
	g->x.img_c = NULL;
	g->x.img_p = NULL;
	g->x.img_p_top = NULL;
	g->x.img_p_left = NULL;
	g->x.img_p_right = NULL;
	g->x.img_h = NULL;
	g->x.win = NULL;
}

static void	init_struct(t_game *g, char **av)
{
	g->m.fd = 0;
	g->m.map = NULL;
	g->m.exit = 0;
	g->m.item = 0;
	g->m.pos = 0;
	g->move_counter = 0;
	g->exit_status = 1;
	init_mlx(g, av);
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
	init_struct(g, av);
	get_map(g, av);
	isrectangle(g, av);
	iswall(g, av);
	isitems(g, av);
	isplayable(g, av);
	launch_game(g, av);
	free_game(g);
	return (0);
}
