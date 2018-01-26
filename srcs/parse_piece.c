/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:19:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/26 17:48:50 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "dlst.h"
#include "get_next_line.h"
#include "ft_printf.h"

static int	parse_line(char *line, t_dlist **piece, int i, int piecex)
{
	int		j;
	t_pos	tmp;

	j = 0;
	while (line[j] && j < piecex)
	{
		if (line[j] == '*')
		{
			tmp.y = i;
			tmp.x = j;
			ft_dlstprepend(piece, ft_dlstnew(&tmp, sizeof(tmp)));
		}
		++j;
	}
	return (j == piecex);
}

t_dlist	*parse_piece(t_pos *origin)
{
	t_dlist		*piece;
	char		*line;
	int			i;

	if (!get_dim(&origin->y, &origin->x))
		return (NULL);
	piece = NULL;
	i = 0;
	line = NULL;
	while (i < origin->y && get_next_line(0, &line) == 1)
	{
		if (!parse_line(line, &piece, i, origin->x))
		{
			ft_dlstdel(&piece, free_block);
			return (NULL);
		}
		free(line);
		i += 1;
	}
	if (i != origin->y)
		ft_dlstdel(&piece, free_block);
	return (piece);
}
