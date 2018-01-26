/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:38:09 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/26 18:44:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "filler.h"
#include "dlst.h"
#include "ft_string.h"
#include "ft_printf.h"
#include "get_next_line.h"

int		can_place(t_board b, t_dlist *piece, t_pos curr, int p)
{
	int connection;

	connection = 0;
	while (piece)
	{
		if (POS(piece)->y + curr.y >= b.dimy || POS(piece)->y + curr.y < 0
			|| POS(piece)->x + curr.x >= b.dimx || POS(piece)->x + curr.x < 0)
			return (0);
		if (b.board[curr.y + POS(piece)->y][curr.x + POS(piece)->x] != 0)
		{
			if (connection
			|| b.board[curr.y + POS(piece)->y][curr.x + POS(piece)->x] != p)
				return (0);
			++connection;
		}
		piece = piece->next;
	}
	return (connection);
}

t_pos	calc_min(t_board b, t_dlist *piece, t_pos curr, int player)
{
	static t_pos	minpos = {0, 0};
	static int		min = INT_MAX;

	if (!piece)
		return (minpos);
}

void	place_piece(t_board b, int player)
{
	t_pos	minpos;
	t_pos	origin;
	t_pos	curr;
	t_dlist	*piece;

	if (!(piece = parse_piece(&origin)))
		return ;
	curr.y = -origin.y;
	while (curr.y < b.dimy)
	{
		curr.x = -origin.x;
		while (curr.x < b.dimx)
		{
			if (can_place(b, piece, curr, player))
				calc_min(b, piece, curr, player);
			++curr.x;
		}
		++curr.y;
	}
	minpos = calc_min(b, NULL, curr, player);
	ft_dlstdel(&piece, free_block);
	ft_printf("%d %d\n", minpos.y, minpos.x);
}
