/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isplayable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:20:57 by wacista           #+#    #+#             */
/*   Updated: 2024/10/31 21:17:57 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] != '1' && map[y][x] != 'H')
	{
		if (map[y][x] != '-')
		{
			map[y][x] = '-';
			flood_fill(map, x, y + 1);
			flood_fill(map, x, y - 1);
			flood_fill(map, x + 1, y);
			flood_fill(map, x - 1, y);
		}
	}
}

static void	free_map_error(char **map, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(map[j++]);
	free(map);
}

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static char	**cpy_map(t_game *g, char **av)
{
	int		i;
	char	**dest;

	dest = (char **)malloc(sizeof(char *) * (g->m.y + 1));
	if (!dest)
		error_return(g, av, 1);
	i = 0;
	while (g->m.map[i])
	{
		dest[i] = ft_strdup(g->m.map[i]);
		if (!dest[i])
			return (free_map_error(dest, i), error_return(g, av, 1), NULL);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

void	isplayable(t_game *g, char **av)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = cpy_map(g, av);
	flood_fill(map, g->m.x_pos, g->m.y_pos);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (free_map(map), error_return(g, av, 10));
			j++;
		}
		i++;
	}
	free_map(map);
}
