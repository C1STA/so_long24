/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:06:41 by wacista           #+#    #+#             */
/*   Updated: 2024/11/01 18:40:09 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_moves(t_game *g)
{
	char	*count;
	char	*disp;

	count = ft_itoa(g->move_counter);
	if (!count)
		return (-1);
	disp = ft_strjoin("moves: ", count);
	free(count);
	mlx_string_put(g->x.mlx, g->x.win, 12, g->m.y * g->x.img_pxl - 22, 0, disp);
	free(disp);
	return (0);
}

static void	end_game(t_game *g, int x, int y, int n)
{
	ft_printf("moves: %d\n", g->move_counter + 1);
	if (g->m.map[y][x] == 'E')
		ft_printf("gg!\n");
	else
		ft_printf("nice try..\n");
	g->m.map[y][x] = 'P';
	g->m.map[g->m.y_pos][g->m.x_pos] = '0';
	display_objects(g, n);
	free_game(g);
}

static void	normal_move(t_game *g, int x, int y)
{
	if (g->m.map[y][x] == 'C')
		g->m.item--;
	g->m.map[y][x] = 'P';
	if (g->m.x_pos != g->m.x_exit || g->m.y_pos != g->m.y_exit)
		g->m.map[g->m.y_pos][g->m.x_pos] = '0';
	g->m.x_pos = x;
	g->m.y_pos = y;
}

static void	move(t_game *g, int x, int y, int n)
{
	if (g->m.map[y][x] != '1')
	{
		if (g->m.y_pos == g->m.y_exit && g->m.x_pos == g->m.x_exit)
			g->m.map[g->m.y_pos][g->m.x_pos] = 'E';
		if (g->m.map[y][x] == 'E' && !g->m.item)
			end_game(g, x, y, n);
		if (g->m.map[y][x] == 'C' || g->m.map[y][x] == '0')
			normal_move(g, x, y);
		if (g->m.map[y][x] == 'E')
		{
			g->m.map[y][x] = 'P';
			g->m.map[g->m.y_pos][g->m.x_pos] = '0';
			g->m.x_pos = x;
			g->m.y_pos = y;
		}
		if (g->m.map[y][x] == 'H')
			end_game(g, x, y, n);
		g->move_counter++;
		ft_printf("moves: %d\n", g->move_counter);
		display_objects(g, n);
	}
	else
		put_object_to_window(g, g->m.x_pos, g->m.y_pos, n);
}

int	keypress_events(int keysym, t_game *g)
{
	if (keysym == XK_W || keysym == XK_w)
		move(g, g->m.x_pos, g->m.y_pos - 1, 0);
	if (keysym == XK_S || keysym == XK_s)
		move(g, g->m.x_pos, g->m.y_pos + 1, 1);
	if (keysym == XK_A || keysym == XK_a)
		move(g, g->m.x_pos - 1, g->m.y_pos, 2);
	if (keysym == XK_D || keysym == XK_d)
		move(g, g->m.x_pos + 1, g->m.y_pos, 3);
	if (keysym == XK_Escape)
	{
		g->exit_status = 0;
		free_game(g);
	}
	return (0);
}
