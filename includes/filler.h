/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:32:03 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/24 17:47:31 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <unistd.h>

void	del_board(int **board);
int		**init_board(size_t *dimx, size_t *dimy);
void	print_board(int fd, int **board, size_t dimx);

#endif
