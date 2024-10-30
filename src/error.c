/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:54:44 by wacista           #+#    #+#             */
/*   Updated: 2024/10/30 11:54:04 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *g)
{
	if (!g)
		return ;
	if (g->m.fd != 0 && g->m.fd != -1)
		close(g->m.fd);
	free(g);
}

void	error_return(t_game *g, char **av, int n)
{
	if (n == 0)
		ft_printf("Error\n%s: %s: %s\n", &av[0][2], av[1], strerror(errno));
	if (n == 1)
		ft_printf("Error\n%s: %s\n", &av[0][2], strerror(errno));
	if (n == 2)
		ft_printf("Error\n%s: %s: map is not a rectangle\n", &av[0][2], av[1]);
	free_game(g);
	exit(1);
}
