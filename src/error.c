/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:54:44 by wacista           #+#    #+#             */
/*   Updated: 2024/10/31 21:25:06 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *g)
{
	int	i;

	if (!g)
		return ;
	if (g->m.fd != 0 && g->m.fd != -1)
		close(g->m.fd);
	i = 0;
	if (g->m.map)
	{
		while (g->m.map[i])
		{
			if (g->m.map[i])
				free(g->m.map[i]);
			i++;
		}
		free(g->m.map);
	}
	if (g->x.mlx)
		free(g->x.mlx);
	free(g);
}

void	error_return(t_game *g, char **av, int n)
{
	if (n == 0)
		ft_printf("Error\n%s: %s: %s\n", &av[0][2], av[1], strerror(errno));
	if (n == 1)
		ft_printf("Error\n%s: %s\n", &av[0][2], strerror(errno));
	if (n == 2)
		ft_printf("Error\n%s: %s: not a rectangle\n", &av[0][2], av[1]);
	if (n == 3)
		ft_printf("Error\n%s: %s: too big\n", &av[0][2], av[1]);
	if (n == 4)
		ft_printf("Error\n%s: %s: too small\n", &av[0][2], av[1]);
	if (n == 5)
		ft_printf("Error\n%s: %s: not surrounded by walls\n", &av[0][2], av[1]);
	if (n == 6)
		ft_printf("Error\n%s: %s: unknown element\n", &av[0][2], av[1]);
	if (n == 7)
		ft_printf("Error\n%s: %s: accepts one exit only\n", &av[0][2], av[1]);
	if (n == 8)
		ft_printf("Error\n%s: %s: accepts one player only\n", &av[0][2], av[1]);
	if (n == 9)
		ft_printf("Error\n%s: %s: no collectible found\n", &av[0][2], av[1]);
	if (n == 10)
		ft_printf("Error\n%s: %s: not playable\n", &av[0][2], av[1]);
	free_game(g);
	exit(1);
}
