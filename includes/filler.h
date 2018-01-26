/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:32:03 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/26 17:52:03 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include "dlst.h"
# define POS(x) ((t_pos *)x->content)

typedef struct	s_board
{
	int			**board;
	int			dimx;
	int			dimy;
}				t_board;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

int			get_dim(int *dimx, int *dimy);
void		del_board(int **board);
int			**init_board(int *dimx, int *dimy);
void		print_board(int fd, int **board, int dimx);
t_dlist		*parse_piece(t_pos *origin);
void		place_piece(t_board b, int player);
void		free_block(void	*content, size_t content_size);

#endif
