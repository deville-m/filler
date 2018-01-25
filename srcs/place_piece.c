/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:38:09 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/25 19:03:15 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "dlst.h"
#include "ft_string.h"
#include "ft_printf.h"
#include "get_next_line.h"

void	place_piece(int **board, size_t dimx, size_t dimy, int player)
{
	size_t	piecex;
	size_t	piecey;
	t_dlist	*piece;

	if (!(piece = parse_piece(&piecex, &piecey)))
		return ;
}
