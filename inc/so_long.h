/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:32:17 by wacista           #+#    #+#             */
/*   Updated: 2024/10/30 11:45:19 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_map
{
	int		fd;
	int		x;
	int		y;
	int		item;
	int		x_pos;
	int		y_pos;
	int		x_exit;
	int		y_exit;
	char	**map;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		img_pxl;
	int		screen_x;
	int		screen_y;
	void	*img_0;
	void	*img_1;
	void	*img_e;
	void	*img_c;
	void	*img_p;
	void	*img_p_top;
	void	*img_p_left;
	void	*img_p_right;
	void	*img_h;
}	t_mlx;

typedef struct s_game
{
	t_mlx	x;
	t_map	m;
	int		move_counter;
}	t_game;

# define IMG_SIZE 32

bool	isextension_valid(char **av);
char	**get_map(char **av, t_game *g);
void	error_return(t_game *g, char **av, int n);

#endif