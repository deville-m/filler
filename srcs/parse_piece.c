/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:19:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/25 19:03:11 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "dlst.h"
#include "get_next_line.h"
#include "ft_printf.h"

static int	parse_line(int i, int piecex, int piecey)
{
	int		j;
	t_block	tmp;

	j = 0;
	while (dimx)
	{
		if (line[j] == '*')
		{
			tmp = {}
			ft_dlstappend(&piece, ft_dlstnew())
		++j;
	}
	return (i == dimx);
}

t_dlist	*parse_piece(size_t *piecex, size_t *piecey)
{
	t_dlist	*piece;
	char	*line;
	int		i;
	int		j;

	if (!get_dim(piecex, piecey))
		return (NULL);
	piece = NULL;
	i = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (!parse_line(&piece, i++, piecex))
			return (0);
	}
	return (i == dimy && y == dimx);
}
