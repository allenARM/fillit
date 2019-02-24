/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_tetriminos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:58:38 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/24 14:53:50 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_adjacent_sides(t_tetrimino *list, int x, int y, int count)
{
	if (list->piece[y][x] == '#')
	{
		if (x != 3 && list->piece[y][x + 1] == '#')
			++count;
		if (x != 0 && list->piece[y][x - 1] == '#')
			++count;
		if (y != 3 && list->piece[y + 1][x] == '#')
			++count;
		if (y != 0 && list->piece[y - 1][x] == '#')
			++count;
	}
	return (count);
}

int		check_for_tetriminos(t_tetrimino *list)
{
	int	x;
	int	y;
	int	count;

	while (list)
	{
		count = 0;
		y = 0;
		while (list->piece[y])
		{
			x = 0;
			while (list->piece[y][x])
			{
				count = check_adjacent_sides(list, x, y, count);
				++x;
			}
			++y;
		}
		if (count != 6 && count != 8)
			return (-1);
		list = list->next;
	}
	return (1);
}
