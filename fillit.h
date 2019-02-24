/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <knaumov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 09:12:50 by knaumov           #+#    #+#             */
/*   Updated: 2018/10/24 14:03:23 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

typedef struct			s_tetrimino
{
	char				**piece;
	char				symbol;
	struct s_tetrimino	*next;
}						t_tetrimino;

t_tetrimino				*input_check(const int fd, t_tetrimino *list);
t_tetrimino				*add_tetrimino(t_tetrimino *list, char *str);
int						check_for_tetriminos(t_tetrimino *list);
char					**create_map(int size);
int						algorithm(char **map, t_tetrimino *list);
void					display_solution(char **map);
int						list_size(t_tetrimino *root);
t_tetrimino				*cleaning_launcher(t_tetrimino *list);
t_tetrimino				*cleaning_columns_right(t_tetrimino *list);
t_tetrimino				*cleaning_columns_left(t_tetrimino *list);

#endif
