/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_dots.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:47:59 by amelikia          #+#    #+#             */
/*   Updated: 2018/10/24 13:59:09 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino		*cleaning_rows(t_tetrimino *list)
{
	int			i;
	char		*str;
	t_tetrimino	*new;

	new = NULL;
	while (list)
	{
		i = 0;
		str = ft_strnew(1);
		while (list->piece[i])
		{
			if (ft_strcmp(list->piece[i], "....") != 0)
			{
				str = ft_strjoin(str, list->piece[i]);
				str = ft_strjoin(str, "\n");
			}
			++i;
		}
		new = add_tetrimino(new, str);
		list = list->next;
	}
	return (new);
}

t_tetrimino		*cleaning_launcher(t_tetrimino *list)
{
	int count;

	count = 0;
	list = cleaning_rows(list);
	while (count != 3)
	{
		list = cleaning_columns_right(list);
		list = cleaning_columns_left(list);
		++count;
	}
	return (list);
}
