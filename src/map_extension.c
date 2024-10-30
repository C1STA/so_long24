/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:46:18 by wacista           #+#    #+#             */
/*   Updated: 2024/10/30 11:56:53 by wacista          ###   ########.fr       */
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

void	get_map_size(char **av, t_game *g)
{
	char	*map;

	g->m.fd = open(av[1], O_RDONLY);
	if (g->m.fd == -1)
		error_return(g, av, 0);
	map = get_next_line(g->m.fd);
	if (!map)
		error_return(g, av, 1);
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

char	**get_map(char **av, t_game *g)
{
	int		i;
	//int		fd;
	//char	**map;

	i = 0;
	g->m.map = NULL;
	g->m.fd = 0;
	get_map_size(av, g);
	return (NULL);
}
