/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:55:43 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/24 17:48:21 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include "conversion.h"
#include "ft_ctype.h"
#include "ft_string.h"

static int	get_dim(size_t *dimx, size_t *dimy)
{
	char *line;
	char *tmp;

	if (get_next_line(0, &line) != 1)
		return (0);
	tmp = line;
	while (tmp && !ft_isdigit(*tmp))
		++tmp;
	*dimx = ft_atoi(tmp);
	while (tmp && ft_isdigit(*tmp))
		++tmp;
	*dimy = ft_atoi(tmp);
	free(line);
	return (*dimx && *dimy);
}

static int	parse_line(int **board, char *tmp, size_t i, size_t dimx)
{
	size_t j;

	j = 0;
	while (tmp[j])
	{
		if (tmp[j] == '.')
			board[i][j] = 0;
		else if (tmp[j] == 'O')
			board[i][j] = 1;
		else if (tmp[j] == 'X')
			board[i][j] = 2;
		else
			return (0);
		++j;
	}
	return(j == dimx);
}

static int	parse_board(int **board, size_t dimx, size_t dimy)
{
	char	*line;
	size_t	i;

	i = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strlen(line) < 5
			|| !(board[i] = (int *)malloc(sizeof(int) * dimx))
			|| !parse_line(board, line + 4, i, dimx))
		{
			free(line);
			return (0);
		}
		free(line);
		++i;
	}
	return (i == dimy);
}

void	del_board(int	**board)
{
	size_t i;

	i = 0;
	while (board[i])
	{
		free(board[i]);
		++i;
	}
	free(board);
}

int		**init_board(size_t *dimx, size_t *dimy)
{
	int		**board;
	char	*line;
	size_t	i;

	if (!get_dim(dimx, dimy)
		|| !(board = (int **)malloc(sizeof(int *) * (*dimy + 1))))
		return (NULL);
	get_next_line(0, &line);
	free(line);
	i = 0;
	while (i <= *dimy)
		board[i++] = NULL;
	if (!parse_board(board, *dimx, *dimy))
	{
		del_board(board);
		return (NULL);
	}
	return (board);
}
