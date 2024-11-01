/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:54:44 by wacista           #+#    #+#             */
/*   Updated: 2024/11/01 19:25:47 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_mlx(t_game *g)
{
	if (!g->x.mlx)
		return ;
	if (g->x.img_0)
		mlx_destroy_image(g->x.mlx, g->x.img_0);
	if (g->x.img_1)
		mlx_destroy_image(g->x.mlx, g->x.img_1);
	if (g->x.img_e)
		mlx_destroy_image(g->x.mlx, g->x.img_e);
	if (g->x.img_c)
		mlx_destroy_image(g->x.mlx, g->x.img_c);
	if (g->x.img_p)
		mlx_destroy_image(g->x.mlx, g->x.img_p);
	if (g->x.img_p_top)
		mlx_destroy_image(g->x.mlx, g->x.img_p_top);
	if (g->x.img_p_left)
		mlx_destroy_image(g->x.mlx, g->x.img_p_left);
	if (g->x.img_p_right)
		mlx_destroy_image(g->x.mlx, g->x.img_p_right);
	if (g->x.img_h)
		mlx_destroy_image(g->x.mlx, g->x.img_h);
	if (g->x.win)
		mlx_destroy_window(g->x.mlx, g->x.win);
	mlx_destroy_display(g->x.mlx);
	free(g->x.mlx);
}

int	free_game(t_game *g)
{
	int	i;
	int	status;

	if (!g)
		exit(1);
	status = g->exit_status;
	if (g->m.fd != 0 && g->m.fd != -1)
		close(g->m.fd);
	if (g->m.map)
	{
		i = 0;
		while (g->m.map[i])
			if (g->m.map[i])
				free(g->m.map[i++]);
		free(g->m.map);
	}
	destroy_mlx(g);
	free(g);
	exit(status);
}

void	error_return(t_game *g, char **av, int n)
{
	if (n == 0)
		ft_printf("Error\n%s: %s: %s\n", &av[0][2], av[1], strerror(errno));
	else if (n == 1)
		ft_printf("Error\n%s: %s\n", &av[0][2], strerror(errno));
	else if (n == 2)
		ft_printf("Error\n%s: %s: not a rectangle\n", &av[0][2], av[1]);
	else if (n == 3)
		ft_printf("Error\n%s: %s: too big\n", &av[0][2], av[1]);
	else if (n == 4)
		ft_printf("Error\n%s: %s: too small\n", &av[0][2], av[1]);
	else if (n == 5)
		ft_printf("Error\n%s: %s: not surrounded by walls\n", &av[0][2], av[1]);
	else if (n == 6)
		ft_printf("Error\n%s: %s: unknown element\n", &av[0][2], av[1]);
	else if (n == 7)
		ft_printf("Error\n%s: %s: accepts one exit only\n", &av[0][2], av[1]);
	else if (n == 8)
		ft_printf("Error\n%s: %s: accepts one player only\n", &av[0][2], av[1]);
	else if (n == 9)
		ft_printf("Error\n%s: %s: no collectible found\n", &av[0][2], av[1]);
	else if (n == 10)
		ft_printf("Error\n%s: %s: not playable\n", &av[0][2], av[1]);
	else if (n == 11)
		ft_printf("Error\n%s: %s: cannot initalize sprite\n", &av[0][2], av[1]);
	free_game(g);
}
