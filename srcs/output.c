/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:41:18 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/24 17:50:51 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	print_board(int fd, int **board, size_t dimx)
{
	size_t i;
	size_t j;

	ft_fprintf(fd, "Board:\n");
	i = 0;
	while (board[i])
	{
		j = 0;
		while (j < dimx)
		{
			ft_fprintf(fd, "%d ", board[i][j]);
			++j;
		}
		ft_fprintf(fd, "\n");
		++i;
	}
}
