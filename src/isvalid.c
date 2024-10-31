/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:57:05 by wacista           #+#    #+#             */
/*   Updated: 2024/10/31 20:19:41 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	isrectangle(t_game *g, char **av)
{
	int	i;
	int	len;

	i = 0;
	if (g->m.x * IMG_SIZE > g->x.screen_x || g->m.y * IMG_SIZE > g->x.screen_y)
		error_return(g, av, 3);
	if (g->m.x < 3 || g->m.y < 3)
		error_return(g, av, 4);
	if (g->m.x == g->m.y)
		error_return(g, av, 2);
	while (g->m.map[i])
	{
		len = ft_strlen(g->m.map[i]);
		if (g->m.map[i][len - 1] == '\n')
		{
			if (g->m.x != len - 1)
				error_return(g, av, 2);
		}
		else
		{
			if (g->m.x != len)
				error_return(g, av, 2);
		}
		i++;
	}
}

void	iswall(t_game *g, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->m.map[i])
	{
		while (i == 0 && j < g->m.x - 1)
		{
			if (g->m.map[i][j] != '1' || g->m.map[g->m.y - 1][j] != '1')
				error_return(g, av, 5);
			j++;
		}
		if (*g->m.map[i] != '1' || g->m.map[i][g->m.x - 1] != '1')
			error_return(g, av, 5);
		i++;
	}
}

static bool	isvalidchar(char c)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'E' \
	&& c != 'P' && c != 'H' && c != '\n')
		return (false);
	return (true);
}

static void	identifier(t_game *g, int i, int j)
{
	if (g->m.map[i][j] == 'E')
	{
		g->m.exit++;
		g->m.x_exit = j;
		g->m.y_exit = i;
	}
	else if (g->m.map[i][j] == 'P')
	{
		g->m.pos++;
		g->m.x_pos = j;
		g->m.y_pos = i;
	}
	else if (g->m.map[i][j] == 'C')
		g->m.item++;
}

void	isitems(t_game *g, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (g->m.map[i])
	{
		j = 0;
		while (g->m.map[i][j])
		{
			if (!isvalidchar(g->m.map[i][j]))
				error_return(g, av, 6);
			identifier(g, i, j);
			j++;
		}
		i++;
	}
	if (g->m.exit != 1)
		error_return(g, av, 7);
	if (g->m.pos != 1)
		error_return(g, av, 8);
	if (!g->m.item)
		error_return(g, av, 9);
}
