/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:58:11 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/24 14:53:26 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			removing_dotted_columns_right(t_tetrimino **new,
	t_tetrimino **list, int dot_count, int y)
{
	char	*temp;
	int		x;

	temp = ft_strnew(1);
	if (dot_count == y)
	{
		x = 0;
		while (x < y)
		{
			temp = ft_strjoin(temp, ft_strsub((*list)->piece[x],
				0, (ft_strlen((*list)->piece[x]) - 1)));
			temp = ft_strjoin(temp, "\n");
			++x;
		}
		*new = add_tetrimino(*new, temp);
	}
	else
	{
		temp = ft_strcon((*list)->piece, "\n");
		*new = add_tetrimino(*new, temp);
	}
}

t_tetrimino		*cleaning_columns_right(t_tetrimino *list)
{
	int			x;
	int			y;
	int			dot_count;
	t_tetrimino	*new;

	new = NULL;
	while (list)
	{
		y = 0;
		x = ft_strlen(list->piece[y]);
		dot_count = 0;
		while (list->piece[y])
		{
			if (list->piece[y][x - 1] == '.')
				++dot_count;
			++y;
		}
		removing_dotted_columns_right(&new, &list, dot_count, y);
		list = list->next;
	}
	return (new);
}

void			removing_dotted_columns_left(t_tetrimino **new,
	t_tetrimino **list, int dot_count, int y)
{
	char	*temp;
	int		x;

	temp = ft_strnew(1);
	if (dot_count == y)
	{
		x = 0;
		while (x < y)
		{
			temp = ft_strjoin(temp, ft_strsub((*list)->piece[x],
				1, (ft_strlen((*list)->piece[x]) - 1)));
			temp = ft_strjoin(temp, "\n");
			++x;
		}
		*new = add_tetrimino(*new, temp);
	}
	else
	{
		temp = ft_strcon((*list)->piece, "\n");
		*new = add_tetrimino(*new, temp);
	}
}

t_tetrimino		*cleaning_columns_left(t_tetrimino *list)
{
	int			x;
	int			y;
	int			dot_count;
	t_tetrimino	*new;

	new = NULL;
	while (list)
	{
		y = 0;
		x = ft_strlen(list->piece[y]);
		dot_count = 0;
		while (list->piece[y])
		{
			if (list->piece[y][0] == '.')
				++dot_count;
			++y;
		}
		removing_dotted_columns_left(&new, &list, dot_count, y);
		list = list->next;
	}
	return (new);
}
