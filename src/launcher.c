/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:48:38 by wacista           #+#    #+#             */
/*   Updated: 2024/11/01 19:04:02 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	convert_sprites(t_game *g, char **av)
{
	g->x.img_0 = mlx_xpm_file_to_image(g->x.mlx, "./sprites/img_0.xpm", \
	&g->x.img_pxl, &g->x.img_pxl);
	g->x.img_1 = mlx_xpm_file_to_image(g->x.mlx, "./sprites/img_1.xpm", \
	&g->x.img_pxl, &g->x.img_pxl);
	g->x.img_e = mlx_xpm_file_to_image(g->x.mlx, "./sprites/img_e.xpm", \
	&g->x.img_pxl, &g->x.img_pxl);
	g->x.img_c = mlx_xpm_file_to_image(g->x.mlx, "./sprites/img_c.xpm", \
	&g->x.img_pxl, &g->x.img_pxl);
	g->x.img_p = mlx_xpm_file_to_image(g->x.mlx, "./sprites/img_p.xpm", \
	&g->x.img_pxl, &g->x.img_pxl);
	g->x.img_p_top = mlx_xpm_file_to_image(g->x.mlx, "./sprites/img_p_top.xpm", \
	&g->x.img_pxl, &g->x.img_pxl);
	g->x.img_p_left = mlx_xpm_file_to_image(g->x.mlx, \
	"./sprites/img_p_left.xpm", &g->x.img_pxl, &g->x.img_pxl);
	g->x.img_p_right = mlx_xpm_file_to_image(g->x.mlx, \
	"./sprites/img_p_right.xpm", &g->x.img_pxl, &g->x.img_pxl);
	g->x.img_h = mlx_xpm_file_to_image(g->x.mlx, "./sprites/img_h.xpm", \
	&g->x.img_pxl, &g->x.img_pxl);
	if (!g->x.img_0 || !g->x.img_1 || !g->x.img_e || !g->x.img_c || !g->x.img_p \
	|| !g->x.img_p_top || !g->x.img_p_left || !g->x.img_p_right || !g->x.img_h)
		error_return(g, av, 11);
}

static void	put_player_position(t_game *g, int x, int y, int n)
{
	if (n == 0)
		mlx_put_image_to_window(g->x.mlx, g->x.win, g->x.img_p_top, x, y);
	else if (n == 1)
		mlx_put_image_to_window(g->x.mlx, g->x.win, g->x.img_p, x, y);
	else if (n == 2)
		mlx_put_image_to_window(g->x.mlx, g->x.win, g->x.img_p_left, x, y);
	else if (n == 3)
		mlx_put_image_to_window(g->x.mlx, g->x.win, g->x.img_p_right, x, y);
}

void	put_object_to_window(t_game *g, int x, int y, int n)
{
	int	draw_x;
	int	draw_y;

	draw_x = x * IMG_SIZE;
	draw_y = y * IMG_SIZE;
	if (g->m.map[y][x] == '0')
		mlx_put_image_to_window(g->x.mlx, g->x.win, g->x.img_0, draw_x, draw_y);
	else if (g->m.map[y][x] == '1')
		mlx_put_image_to_window(g->x.mlx, g->x.win, g->x.img_1, draw_x, draw_y);
	else if (g->m.map[y][x] == 'E')
		mlx_put_image_to_window(g->x.mlx, g->x.win, g->x.img_e, draw_x, draw_y);
	else if (g->m.map[y][x] == 'C')
		mlx_put_image_to_window(g->x.mlx, g->x.win, g->x.img_c, draw_x, draw_y);
	else if (g->m.map[y][x] == 'P')
		put_player_position(g, draw_x, draw_y, n);
	else if (g->m.map[y][x] == 'H')
		mlx_put_image_to_window(g->x.mlx, g->x.win, g->x.img_h, draw_x, draw_y);
}

void	display_objects(t_game *g, int n)
{
	int	i;
	int	j;

	i = 0;
	while (g->m.map[i])
	{
		j = 0;
		while (g->m.map[i][j])
		{
			put_object_to_window(g, j, i, n);
			j++;
		}
		i++;
	}
}

void	launch_game(t_game *g, char **av)
{
	convert_sprites(g, av);
	g->x.win = mlx_new_window(g->x.mlx, \
	g->x.img_pxl * g->m.x, g->x.img_pxl * g->m.y, &av[0][2]);
	if (!g->x.win)
		error_return(g, av, 1);
	display_objects(g, 1);
	g->exit_status = 0;
	mlx_hook(g->x.win, KeyPress, KeyPressMask, &keypress_events, g);
	mlx_hook(g->x.win, DestroyNotify, StructureNotifyMask, &free_game, g);
	mlx_loop_hook(g->x.mlx, display_moves, g);
	mlx_loop(g->x.mlx);
}
