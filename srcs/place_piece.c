/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:38:09 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/27 21:29:03 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "filler.h"
#include "dlst.h"
#include "ft_string.h"
#include "ft_printf.h"
#include "get_next_line.h"

static int	can_place(t_board b, t_dlist *piece, t_pos curr, int p)
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

static int	ft_sqrt(int val)
{
	int i;

	i = 0;
	while (i * i < val)
		++i;
	return (i);
}

static int	get_min(t_pos tmppos, t_dlist *piece, t_pos curr)
{
	int		tmpx;
	int		tmpy;
	t_pos	tmp;

	tmp.x = POS(piece)->x + curr.x;
	tmp.y = POS(piece)->y + curr.y;
	tmpx = (tmp.x - tmppos.x) * (tmp.x - tmppos.x);
	tmpy = (tmp.y - tmppos.y) * (tmp.y - tmppos.y);
	return (ft_sqrt(tmpx + tmpy));
}

static int	get_dist(t_board b, t_dlist *piece, t_pos curr, int opponent)
{
	int		d;
	int		min;
	t_pos	tmp;

	tmp.y = 0;
	min = INT_MAX;
	while (tmp.y < b.dimy)
	{
		tmp.x = 0;
		while (tmp.x < b.dimx)
		{
			if (b.board[tmp.y][tmp.x] == opponent
			&& (d = get_min(tmp, piece, curr)) < min)
				min = d;
			++tmp.x;
		}
		++tmp.y;
	}
	return (min);
}

void		place_piece(t_board b, t_dlist *piece, t_pos origin, int player)
{
	int		tmp;
	int		min;
	t_pos	minpos;
	t_pos	curr;

	min = INT_MAX;
	minpos.x = 0;
	minpos.y = 0;
	curr.y = -origin.y;
	while (curr.y < b.dimy)
	{
		curr.x = -origin.x;
		while (curr.x < b.dimx)
		{
			if (can_place(b, piece, curr, player)
			&& (tmp = get_dist(b, piece, curr, (player == 1) ? 2 : 1)) < min)
			{
				minpos = curr;
				min = tmp;
			}
			++curr.x;
		}
		++curr.y;
	}
	ft_printf("%d %d\n", minpos.y, minpos.x);
}
