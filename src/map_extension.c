/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:46:18 by wacista           #+#    #+#             */
/*   Updated: 2024/10/28 18:19:31 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	isextension_valid(char *s)
{
	size_t	i;

	i = ft_strlen(s);
	if (i > 3)
	{
		if (!ft_strcmp(".ber", &s[i - 4]))
			return (true);
	}
	ft_printf("Error\nso_long: map is not valid\n");
	return (false);
}

void	get_map_size(char **av, t_v *v)
{
	int		fd;
	char	*map;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_return();
	map = get_next_line(fd);
	if (!map)
		error_return();
	v->m.x = (int)ft_strlen(map);
	free(map);
	v->m.y = 1;
	while (map)
	{
		map = get_next_line(fd);
		if (map)
		{
			v->m.y++;
			free(map);
		}
	}
	close(fd);
}

char	**get_map(char **av, t_v *v)
{
	int		i;
	int		fd;
	char	**map;

	i = 0;
	v->m.map = NULL;
	get_map_size(av, v);
}