/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:30:11 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/27 21:23:55 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "filler.h"
#include "get_next_line.h"
#include "ft_io.h"
#include "conversion.h"
#include "ft_string.h"

static int		get_player(void)
{
	int		player;
	char	*line;

	if (get_next_line(0, &line) == 1 && ft_strlen(line) >= 11)
	{
		player = ft_atoi(line + 10);
		if (player == 1 || player == 2)
		{
			free(line);
			return (player);
		}
	}
	free(line);
	return (0);
}

int				main(void)
{
	int		player;
	t_board	b;
	t_dlist	*piece;
	t_pos	origin;

	if ((player = get_player()) != 1 && player != 2)
		return (1);
	while (1)
	{
		if (!(b.board = init_board(&b.dimx, &b.dimy)))
			return (1);
		if (!(piece = parse_piece(&origin)))
		{
			del_board(b.board);
			return (1);
		}
		place_piece(b, piece, origin, player);
		ft_dlstdel(&piece, free_block);
		del_board(b.board);
	}
	return (0);
}
