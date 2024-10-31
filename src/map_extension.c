/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:46:18 by wacista           #+#    #+#             */
/*   Updated: 2024/10/31 20:23:19 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	isextension_valid(char **av)
{
	size_t	i;

	i = ft_strlen(av[1]);
	if (i > 3)
	{
		if (!ft_strcmp(".ber", &av[1][i - 4]))
			return (true);
	}
	ft_printf("Error\n%s: %s: unknown extension\n", &av[0][2], av[1]);
	return (false);
}

static void	get_map_size(t_game *g, char **av)
{
	char	*map;

	g->m.fd = open(av[1], O_RDONLY);
	if (g->m.fd == -1)
		error_return(g, av, 0);
	map = get_next_line(g->m.fd);
	if (!map)
		error_return(g, av, 1);
	if (map[ft_strlen(map) - 1] == '\n')
		g->m.x = ft_strlen(map) - 1;
	else
		g->m.x = ft_strlen(map);
	g->m.y = 1;
	free(map);
	while (map)
	{
		map = get_next_line(g->m.fd);
		if (map)
		{
			g->m.y++;
			free(map);
		}
	}
	close(g->m.fd);
	g->m.fd = 0;
}

void	init_map(t_game *g)
{
	int	i;

	i = 0;
	while (i <= g->m.y)
		g->m.map[i++] = NULL;
}

void	get_map(t_game *g, char **av)
{
	int		i;

	i = 0;
	get_map_size(g, av);
	g->m.map = (char **)malloc(sizeof(char *) * (g->m.y + 1));
	if (!g->m.map)
		error_return(g, av, 1);
	init_map(g);
	g->m.fd = open(av[1], O_RDONLY);
	if (g->m.fd == -1)
		error_return(g, av, 0);
	while (i < g->m.y)
		g->m.map[i++] = get_next_line(g->m.fd);
	g->m.map[i] = NULL;
	close(g->m.fd);
	g->m.fd = 0;
}
