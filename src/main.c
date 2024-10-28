/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:32:44 by wacista           #+#    #+#             */
/*   Updated: 2024/10/28 17:56:23 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_v	*v;

	if (ac != 2)
		return (ft_printf("Error\nso_long: \
accepts 1 arg, received %d\n", ac - 1), 2);
	if (!isextension_valid(av[1]))
		return (1);
	v = (t_v *)malloc(sizeof(t_v));
	if (!v)
		return (ft_printf("Error\nso_long: %s\n", strerror(errno)), 1);
	v->m.map = NULL;
	v->m.map = get_map(av, v);
	return (0);
}
